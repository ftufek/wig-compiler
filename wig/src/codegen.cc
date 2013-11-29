#include <iostream>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "codegen.h"
#include "pretty_printer.h"

using namespace std;

namespace visitors {

#define DEF_JUMP_NEXT_LABEL true

CodeGenerator::CodeGenerator(std::ostream &out)
	:cgout(out),_fields({}), _sessions({}), _in_session({}), _current_label(0),
	 _label_stms({}), _in_fn({}), _plugs({}), _exps({}),
	 _sym_table(st::Table()), _is_generating_global_variables(false) {}

std::string CodeGenerator::PrettyPrint(ast::Base *s){
	stringstream ss;
	auto printer = visitors::PrettyPrinter(ss, false);
	s->accept(&printer);
	return ss.str();
}

void CodeGenerator::UpdateSymTable(ast::Base *s){
	_sym_table = st::Table(*s->get_sym_table());
}

std::string CodeGenerator::CallNextLogic(const int label){
	if(_in_session.size()){
		return _t_call_next_logic(_in_session, label);
	}else if(_in_fn.size()){
		return _t_next_fn(_in_fn, label);
	}
	return "";
}

void CodeGenerator::PrintLabelStms(const int label,
								   std::list<std::string> stms,
								   bool jump_to_next_label){
	if(_in_session.size()){
		if(jump_to_next_label){
			bool already_contains_jump = false;
			for(auto stm : stms){
				if(stm.find("next_logic") != std::string::npos){
					already_contains_jump = true;
					break;
				}
			}
			if(already_contains_jump){
				cerr<<"Trying to insert jump to next when there's already a jump present"<<endl;
			}else{
				stms.push_back(_t_next_logic(_in_session, label+1));
			}
		}
		cgout<<_t_session_stm_stack(_in_session, label, stms);
	}else if(_in_fn.size()){
		if(jump_to_next_label){
			stringstream ss;
			ss<<"__set_fn_logic("<<label+1<<")";
			stms.push_back(ss.str());
		}
		cgout<<_t_fn_decl(_in_fn, label, stms);
	}
	ClearStms();
}

void CodeGenerator::PrintFnCallStms(){
	if(_label_stms.size() && _fn_call_stms.size()){
		//print what was previously there
		PrintLabelStms(NewLabel(), _label_stms, true);
	}
	if(_fn_call_stms.size()){
		for(auto call : _fn_call_stms){
			_label_stms.push_back("global __vars");
			string copy_vars_id = boost::lexical_cast<std::string>(
											boost::uuids::random_generator()());
			_label_stms.push_back("__vars[\""+copy_vars_id + "\"] = copy.deepcopy(__vars)");
			_label_stms.push_back(call.fn_call_exp);
			_label_stms.push_back("return_val = __vars[\"__return_value\"]");
			_label_stms.push_back("call_stack = __vars[\"__call_stack\"]");
			_label_stms.push_back("__vars = __vars[\""+copy_vars_id + "\"]");
			_label_stms.push_back("__vars[\"__return_value\"] = return_val");
			_label_stms.push_back("__vars[\"__call_stack\"] = call_stack");
			_label_stms.push_back(CallNextLogic(_current_label+2));
			PrintLabelStms(NewLabel(), _label_stms);

			_label_stms.push_back("global __returned_from_fn");

			list<string> else_stms{};
			if(_in_session.size()){
				else_stms.push_back("__save_session_"+_in_session+"()");
			}

			_label_stms.push_back(_t_if_stm("__returned_from_fn",
									list<string>{
										"__returned_from_fn = False",
										_t_var(call.unique_key) + " = " + _t_var("__return_value"),
										CallNextLogic(_current_label+2)},
									else_stms));
			PrintLabelStms(NewLabel(), _label_stms);
		}
	}
	_fn_call_stms.clear();
}

void CodeGenerator::ClearStms(){
	_label_stms.clear();
}

int CodeGenerator::NewLabel(){
	_current_label++;
	return _current_label;
}

std::string CodeGenerator::ExpToStr(ast::Exp *s){
	s->accept(this);
	if(_exps.size()){
		auto e = _exps.back();
		_exps.pop_back();
		return e;
	}else{
		return "ERROR_IN_EXP_TO_STR";
	}
}

void CodeGenerator::visit(ast::Service *s){
	UpdateSymTable(s);
	cgout<<_t_env()
		 <<_t_imports(std::list<std::string> {"cgi","cgitb","os","uuid",
									"pickle","copy", "sys", "traceback"})
		 <<_t_enable_cgi()<<_t_state_vars()<<endl;

	s->schemas_->accept(this);
	cgout<<_t_html_layout()<<endl;

	_is_generating_global_variables = true;
	s->htmls_->accept(this);
	cgout<<_t_global_vars_helpers()<<endl;
	s->global_variables_->accept(this);
	_is_generating_global_variables = false;

	cgout<<_t_fn_helpers()<<endl;
	s->functions_->accept(this);

	s->sessions_->accept(this);

	cgout<<_t_main_print_stms(_sessions)<<endl;
}

void CodeGenerator::visit(ast::Whatever *s ) {}

void CodeGenerator::visit(ast::Variable *s) {
	if(_is_generating_global_variables){
		if(s->type_->type_ == ast::kType::HTML){
			//Generate html function
			cgout<<_t_html_function(s->name_, PrettyPrint(s->value_))<<endl;
		}else{
			string def_val{"\"\""};
			switch(s->type_->type_){
			//INT, BOOL, STRING, VOID, TUPLE, HTML, SCHEMA, UNDEFINED
			case ast::kType::INT:
				def_val = "0";
				break;

			case ast::kType::BOOL:
				def_val = "False";
				break;

			default:
				break;
			}
			auto key = _sym_table.GetUniqueKeySymbol(s->name_);
			if(key){
				cgout<<_t_global_var(key.get(), def_val)<<endl;
			}else{
				cerr<<"ERROR_IN_CODEGEN";
			}
		}
	}
}

void CodeGenerator::visit(ast::Function *s) {
	UpdateSymTable(s->stm_);
	_in_fn = s->id_;
	_label_stms.clear();

	std::list<std::string> args{};
	for(auto arg : *(s->args_)){
		args.push_back("_arg_"+arg->id_);
		auto sym = _sym_table.GetUniqueKeySymbol(arg->id_);
		if(sym){
			_label_stms.push_back(_t_var(sym.get()) + " = " + "_arg_"+arg->id_);
		}else{
			cerr<<"ERROR function argument isn't in the symbol table!"<<endl;
		}
	}
	_label_stms.push_back("__call_fn(\""+s->id_+"\")");
	_label_stms.push_back(_t_next_fn(_in_fn, _current_label+2));
	cgout<<_t_fn_decl(s->id_, NewLabel(), _label_stms, args);
	_label_stms.clear();
	s->stm_->accept(this);
	_label_stms.clear();
	_current_label = 0;
	_in_fn = "";
}

void CodeGenerator::visit(ast::Field *s) {
	string field_name = s->id_;
	string field_default_value{"\"\""};
	switch(s->type_->type_){
	//INT, BOOL, STRING, VOID, TUPLE, HTML, SCHEMA, UNDEFINED
	case ast::kType::INT:
		field_default_value = "0";
		break;

	case ast::kType::BOOL:
		field_default_value = "False";
		break;

	default:
		break;
	}
	_fields.push_back(make_pair(field_name, field_default_value));
}

void CodeGenerator::visit(ast::Empty *) {}
void CodeGenerator::visit(ast::HtmlTag *s) {}
void CodeGenerator::visit(ast::Argument *s) {}
void CodeGenerator::visit(ast::MetaTag *s) {}

void CodeGenerator::visit(ast::Schema *s) {
	_fields.clear();
	s->fields_->accept(this);
	cgout<<_t_schema_class(s->id_, _fields);
	cgout<<endl;
	_fields.clear();
}

void CodeGenerator::visit(ast::String *s) {}

void CodeGenerator::visit(ast::List *s) {
	for(auto e : *(s->getList())){
		e->accept(this);
	}
}

void CodeGenerator::visit(ast::Type *s) {}

void CodeGenerator::visit(ast::Session *s){
	_sessions.push_back(s->id_);
	cgout<<_t_save_session(s->id_)<<endl
			<<_t_init_session(s->id_)<<endl
			<<_t_load_session(s->id_)<<endl
			<<_t_session(s->id_)<<endl;

	_in_session = s->id_;
	_label_stms.clear();
	s->stm_->accept(this);

	//The following is necessary, because the way I designed session logic is
	//at the end there's always a jump to next label. But once everything is
	//generated, there's no next label. So I need to revert it
	_label_stms.push_back(_t_call_next_logic(_in_session, _current_label));
	PrintLabelStms(NewLabel(), _label_stms);

	_label_stms.clear();
	_current_label = 0;
	_in_session = "";
}

void CodeGenerator::visit(ast::EmptyStm *s) {/* NOTHING TO DO */}

void CodeGenerator::visit(ast::CompoundStm *s) {
	UpdateSymTable(s);
	for(auto stm : *(s->stms_)){
		UpdateSymTable(s);
		stm->accept(this);
	}
}

void CodeGenerator::visit(ast::ShowStm *s) {
	s->doc_->accept(this);
	if(s->receive_){
		s->receive_->accept(this);
	}
}

void CodeGenerator::visit(ast::DocumentStm *s){
	_plugs.clear();
	for(auto plug : *(s->plugs_)){
		plug->accept(this);
	}
	_label_stms.push_back(_t_print_html(s->id_,_plugs));
	PrintLabelStms(NewLabel(), _label_stms, DEF_JUMP_NEXT_LABEL);
}

void CodeGenerator::visit(ast::PlugStm *s){
	string plug = "'" + s->id_ + "':";
	plug.append(ExpToStr(s->exp_));
	PrintFnCallStms();
	_plugs.push_back(plug);
}

void CodeGenerator::visit(ast::ReceiveStm *s){
	for(auto input : *(s->inputs_)){
		input->accept(this);
	}
	_label_stms.push_back(_t_call_next_logic(_in_session, _current_label+2));
	PrintLabelStms(NewLabel(), _label_stms);
}

void CodeGenerator::visit(ast::InputStm *s){
	auto sym = _sym_table.GetUniqueKeySymbol(s->lvalue_);
	if(sym){
		string var = _t_var(sym.get());

		auto var_ast = static_cast<ast::Variable *>(
						_sym_table.FindSymbol(s->lvalue_).get().get_node());
		string input = _t_cgi_input(s->id_);
		switch(var_ast->type_->type_){
		case ast::kType::INT:
			input = _t_cgi_input(s->id_, "int");
			break;
		default:
			break;
		}
		_label_stms.push_back(var + " = " + input);
	}
}

void CodeGenerator::visit(ast::ExitStm *s){
	if(!_in_session.empty()){
		s->doc_->accept(this);
	}
}

void CodeGenerator::visit(ast::ReturnStm *s){
	string exp_str = ExpToStr(s->exp_);
	PrintFnCallStms();
	_label_stms.push_back(_t_return_stm(exp_str));
	PrintLabelStms(NewLabel(), _label_stms);
}

void CodeGenerator::visit(ast::IfStm *s){
	int if_label;
	if(_label_stms.size() > 0){
		int before_if_label = NewLabel();
		if_label = NewLabel();
		_label_stms.push_back(CallNextLogic(if_label));
		PrintLabelStms(before_if_label, _label_stms); //print everything before now
	}else{
		if_label = NewLabel();
	}

	s->true_stm_->accept(this);
	auto true_stms = _label_stms;
	_label_stms.clear();
	if(s->else_stm_){
		int else_label = _current_label+1;
		s->else_stm_->accept(this);
		auto else_stms = _label_stms;

		true_stms.push_back(CallNextLogic(_current_label+3));
		PrintLabelStms(NewLabel(), true_stms);

		else_stms.push_back(CallNextLogic(_current_label+2));
		PrintLabelStms(NewLabel(), else_stms);

		_label_stms.push_back(_t_if_stm(ExpToStr(s->condition_),
								list<string>{CallNextLogic(if_label+1)},
								list<string>{CallNextLogic(else_label)}));
		PrintLabelStms(if_label, _label_stms);
	}else{
		true_stms.push_back(CallNextLogic(_current_label+2));
		PrintLabelStms(NewLabel(), true_stms);

		_label_stms.push_back(_t_if_stm(ExpToStr(s->condition_),
										list<string>{CallNextLogic(if_label+1)},
										list<string>{CallNextLogic(_current_label+1)}));
		PrintLabelStms(if_label, _label_stms);
	}
}

void CodeGenerator::visit(ast::WhileStm *s){
	_label_stms.push_back(_t_call_next_logic(_in_session, _current_label+2));
	PrintLabelStms(NewLabel(), _label_stms); //print everything before now
	int while_label = _current_label+1;
	string condition = ExpToStr(s->condition_);
	PrintFnCallStms();
	int while_label_condition_tail = NewLabel();

	s->stm_->accept(this);
	_label_stms.push_back(_t_call_next_logic(_in_session, while_label));
	PrintLabelStms(NewLabel(), _label_stms);

	_label_stms.push_back(_t_if_stm(condition,
									list<string>{_t_call_next_logic(_in_session, while_label_condition_tail+1)},
									list<string>{_t_call_next_logic(_in_session, _current_label+1)}));
	PrintLabelStms(while_label_condition_tail, _label_stms);
}

void CodeGenerator::visit(ast::ExpStm *s){
	string exp_str = ExpToStr(s->exp_);
	PrintFnCallStms();
	_label_stms.push_back(exp_str);
	if(_exps.size()){
		cerr<<"ERROR exp stack should be empty!"<<endl;
	}
}

void CodeGenerator::visit(ast::Exp *){
}

void CodeGenerator::visit(ast::LValExp *s){
	if(!s->is_tuple_ref()){
		auto key = _sym_table.GetUniqueKeySymbol(s->lvalue_);
		if(key){
			_exps.push_back(_t_var(key.get()));
		}else{
			_sym_table.PrettyPrint(std::cerr);
			cerr<<"ERROR_IN_CODEGEN_FOR_LVALUE:"<<s->lvalue_;
		}
	}else{
		//TODO: implement
		auto key = _sym_table.GetUniqueKeySymbol(s->get_tuple_name());
		if(key){

		}
	}
}

void CodeGenerator::visit(ast::BinopExp *s){
	auto left = ExpToStr(s->left_);
	auto right = ExpToStr(s->right_);
	auto op = "";
	switch(s->type_){
	case ast::kBinopType::Assignment:{
		op = "=";
		break;
	}
	case ast::kBinopType::Equals:
		op = "==";
		break;

	case ast::kBinopType::NotEquals:
		op = "!=";
		break;

	case ast::kBinopType::LowerThan:
		op = "<";
		break;

	case ast::kBinopType::HigherThan:
		op = ">";
		break;

	case ast::kBinopType::LowerEquals:
		op = "<=";
		break;

	case ast::kBinopType::HigherEquals:
		op = ">=";
		break;

	case ast::kBinopType::Add:
		op = "+";
		break;

	case ast::kBinopType::Sub:
		op = "-";
		break;

	case ast::kBinopType::Mult:
		op = "*";
		break;

	case ast::kBinopType::Div:
		op = "/";
		break;

	case ast::kBinopType::Mod:
		op = "%";
		break;

	case ast::kBinopType::And:
		op = "and";
		break;

	case ast::kBinopType::Or:
		op = "or";
		break;

	case ast::kBinopType::Combine:
		op = "<<";
		break;
	default:
		break;
	}
	_exps.push_back(left + " " + op + " " + right);
}

void CodeGenerator::visit(ast::UnopExp *s){
	auto val = ExpToStr(s->exp_);
	switch(s->type_){
	case ast::kUnopType::LogicNegate:
		_exps.push_back("not "+val);
		break;
	case ast::kUnopType::Minus:
		_exps.push_back("-"+val);
		break;
	default:
		break;
	}
}

void CodeGenerator::visit(ast::TupleopExp *s){
	//TODO: implement
}

void CodeGenerator::visit(ast::FunctionExp *s){
	string fn_call_id = boost::lexical_cast<std::string>(
								boost::uuids::random_generator()());

	stringstream ss;
	ss<<"__logic_fn_"<<s->id_<<"_1";
	ss<<"(";

	auto it = s->exps_->begin();
	if(it != s->exps_->end()){
		ss<<ExpToStr(*it);
		++it;
	}

	for(; it != s->exps_->end(); ++it){
		ss<<", ";
		ss<<ExpToStr(*it);
	}
	ss<<")";
	_fn_call_stms.push_back(FnCall(s->id_, fn_call_id, ss.str()));
	_exps.push_back(_t_var(fn_call_id));
}

void CodeGenerator::visit(ast::IntegerExp *s){
	stringstream ss;
	ss<<s->i_;
	_exps.push_back(ss.str());
}

void CodeGenerator::visit(ast::TrueExp *s){
	_exps.push_back("True");
}

void CodeGenerator::visit(ast::FalseExp *s){
	_exps.push_back("False");
}

void CodeGenerator::visit(ast::StringExp *s){
	_exps.push_back(s->str_);
}

void CodeGenerator::visit(ast::FieldValExp *s){
	//TODO: implement
}

void CodeGenerator::visit(ast::TupleExp *s){
	//TODO: implement
}

}
