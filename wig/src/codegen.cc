#include <iostream>
#include <string>
#include <sstream>
#include "codegen.h"
#include "pretty_printer.h"

using namespace std;

namespace visitors {

#define DEF_JUMP_NEXT_LABEL true

CodeGenerator::CodeGenerator(std::ostream &out)
	:cgout(out),_fields({}), _sessions({}), _in_session({}),
	 _current_label(0), _label_stms({}), _exps({}),_sym_table(st::Table()),
	 _is_generating_global_variables(false) {}

std::string CodeGenerator::PrettyPrint(ast::Base *s){
	stringstream ss;
	auto printer = visitors::PrettyPrinter(ss, false);
	s->accept(&printer);
	return ss.str();
}

void CodeGenerator::UpdateSymTable(ast::Base *s){
	_sym_table = st::Table(*s->get_sym_table());
}

void CodeGenerator::PrintLabelStms(const int label,
								   std::list<std::string> stms,
								   bool jump_to_next_label){
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
	ClearStms();
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
	auto e = _exps.back();
	_exps.pop_back();
	return e;
}

void CodeGenerator::visit(ast::Service *s){
	UpdateSymTable(s);
	cgout<<_t_env()
		 <<_t_imports(std::list<std::string> {"cgi","cgitb","os","uuid","pickle"})
		 <<_t_enable_cgi()<<_t_state_vars()<<endl;

	s->schemas_->accept(this);
	cgout<<_t_html_layout()<<endl;

	_is_generating_global_variables = true;
	s->htmls_->accept(this);
	cgout<<_t_global_vars_helpers()<<endl;
	s->global_variables_->accept(this);
	_is_generating_global_variables = false;

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
	UpdateSymTable(s);
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
	_in_session = "";
}

void CodeGenerator::visit(ast::EmptyStm *s) {/* NOTHING TO DO */}

void CodeGenerator::visit(ast::CompoundStm *s) {
	for(auto stm : *(s->stms_)){
		UpdateSymTable(s);
		stm->accept(this);
	}
}

void CodeGenerator::visit(ast::ShowStm *s) {
	if(!_in_session.empty()){
		s->doc_->accept(this);
		if(s->receive_){
			s->receive_->accept(this);
		}
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
	_plugs.push_back(plug);
}

void CodeGenerator::visit(ast::ReceiveStm *s){
	for(auto input : *(s->inputs_)){
		input->accept(this);
	}
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
	//TODO: implement
}

void CodeGenerator::visit(ast::IfStm *s){
	int before_if_label = NewLabel();
	int if_label = NewLabel();
	_label_stms.push_back(_t_call_next_logic(_in_session, if_label));
	PrintLabelStms(before_if_label, _label_stms); //print everything before now

	s->true_stm_->accept(this);
	_label_stms.push_back(_t_call_next_logic(_in_session, _current_label+2));
	PrintLabelStms(NewLabel(), _label_stms);

	_label_stms.push_back(_t_if_stm(ExpToStr(s->condition_),
									list<string>{_t_call_next_logic(_in_session, if_label+1)},
									list<string>{_t_call_next_logic(_in_session, _current_label+1)}));
	PrintLabelStms(if_label, _label_stms);
}

void CodeGenerator::visit(ast::WhileStm *s){
	int before_while_label = NewLabel();
	int while_label = NewLabel();
	_label_stms.push_back(_t_call_next_logic(_in_session, while_label));
	PrintLabelStms(before_while_label, _label_stms); //print everything before now

	s->stm_->accept(this);
	_label_stms.push_back(_t_call_next_logic(_in_session, while_label));
	PrintLabelStms(NewLabel(), _label_stms);

	_label_stms.push_back(_t_if_stm(ExpToStr(s->condition_),
									list<string>{_t_call_next_logic(_in_session, while_label+1)},
									list<string>{_t_call_next_logic(_in_session, _current_label+1)}));
	PrintLabelStms(while_label, _label_stms);
}

void CodeGenerator::visit(ast::ExpStm *s){
	_label_stms.push_back(ExpToStr(s->exp_));
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
			cerr<<"ERROR_IN_CODEGEN";
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
		op = "&&";
		break;

	case ast::kBinopType::Or:
		op = "||";
		break;

	case ast::kBinopType::Combine:
		op = "<<";
		break;
	default:
		break;
	}
	_exps.push_back(left + op + right);
}

void CodeGenerator::visit(ast::UnopExp *s){
	//TODO: implement
}

void CodeGenerator::visit(ast::TupleopExp *s){
	//TODO: implement
}

void CodeGenerator::visit(ast::FunctionExp *s){
	//TODO: implement
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
