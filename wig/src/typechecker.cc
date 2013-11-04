/*
 * typechecker.cc
 *
 *  Created on: Oct 29, 2013
 *      Author: user
 */


#include <sstream>
#include <boost/optional.hpp>
#include "typechecker.h"
#include "error.h"
#include "pretty_printer.h"

namespace visitors {

boost::optional<ast::Schema *> TypeChecker::sym2schema(st::Symbol sym){
	boost::optional<ast::Schema *> schema_def;
	auto tuple_var = dynamic_cast<ast::Variable *>(sym.get_node());
	if(tuple_var){
		auto schema_name = tuple_var->type_->tuple_id_;
		auto schema = sym_table_.FindSymbol(schema_name);
		if(schema){
			schema_def.reset(dynamic_cast<ast::Schema *>
											(schema.get().get_node()));
		}
	}
	return schema_def;
}

TypeChecker::TypeChecker()
	:sym_table_(st::Table()), exp_type_(ast::kType::UNDEFINED){}
TypeChecker::~TypeChecker(){};

void TypeChecker::UpdateSymTable(ast::Base *s){
	sym_table_ = st::Table(*s->get_sym_table()); //create a new copy
}

ast::kType TypeChecker::get_exp_type(){
	return exp_type_.get();
}

void TypeChecker::set_exp_type(ast::kType type){
	exp_type_.reset(type);
}

std::string TypeChecker::PrettyPrint(ast::Exp *node){
	std::ostringstream ss;
	auto printer = visitors::PrettyPrinter(ss, false);
	node->accept(&printer);
	ss.flush();
	return ss.str();
}

void TypeChecker::UNDEFINED(){
	set_exp_type(ast::kType::UNDEFINED);
}

void TypeChecker::visit(ast::Service *s){
	UpdateSymTable(s);
	s->functions_->accept(this);
	s->sessions_->accept(this);
}
void TypeChecker::visit(ast::Whatever *s){}
void TypeChecker::visit(ast::Variable *s){
	set_exp_type(s->type_->type_);
}
void TypeChecker::visit(ast::Function *s){
	s->stm_->accept(this);
}
void TypeChecker::visit(ast::Field *s){}
void TypeChecker::visit(ast::Empty *s){}
void TypeChecker::visit(ast::HtmlTag *s){}
void TypeChecker::visit(ast::Argument *s){
	set_exp_type(s->type_->type_);
}
void TypeChecker::visit(ast::MetaTag *s){}
void TypeChecker::visit(ast::Schema *s){}
void TypeChecker::visit(ast::String *s){}
void TypeChecker::visit(ast::List *s){
	for(auto exp : (*s->exps_)){
		exp->accept(this);
	}
}
void TypeChecker::visit(ast::Type *s){
	set_exp_type(s->type_);
}
void TypeChecker::visit(ast::Session *s){
	s->stm_->accept(this);
}

void TypeChecker::visit(ast::EmptyStm *s){
	//Nothing to typecheck!
}

void TypeChecker::visit(ast::CompoundStm *s){
	for(auto stm : (*s->stms_)){
		UpdateSymTable(s);
		stm->accept(this);
	}
}
void TypeChecker::visit(ast::ShowStm *s){
	s->doc_->accept(this);
}
void TypeChecker::visit(ast::DocumentStm *s){
	auto html_id = s->id_;
	auto html_sym = sym_table_.FindSymbol(html_id);
	if(html_sym){
		UNDEFINED();
		html_sym.get().get_node()->accept(this);
		if(get_exp_type() != ast::kType::HTML){
			UNDEFINED();
			error::GenerateError(error::SHOULD_BE_HTML, html_id, s->at_line());
		}
	}else{
		error::GenerateError(error::HTML_DOESNT_EXIST, html_id, s->at_line());
	}
}
void TypeChecker::visit(ast::PlugStm *s){}
void TypeChecker::visit(ast::InputStm *s){}
void TypeChecker::visit(ast::ReceiveStm *s){}
void TypeChecker::visit(ast::ExitStm *s){
	s->doc_->accept(this);
}
void TypeChecker::visit(ast::ReturnStm *s){}
void TypeChecker::visit(ast::IfStm *s){
	auto temp = get_exp_type();
	s->condition_->accept(this);
	if(get_exp_type() != ast::kType::BOOL){
		error::GenerateError(error::SHOULD_BE_BOOL, PrettyPrint(s->condition_), s->at_line());
	}
	set_exp_type(temp);
	s->true_stm_->accept(this);
	if(s->else_stm_){
		s->else_stm_->accept(this);
	}
}
void TypeChecker::visit(ast::WhileStm *s){}
void TypeChecker::visit(ast::ExpStm *s){
	s->exp_->accept(this);
}

void TypeChecker::visit(ast::Exp *s){}
void TypeChecker::visit(ast::LValExp *s){
	if(!s->is_tuple_ref()){
		auto sym = sym_table_.FindSymbol(s->get_lvalue());
		if(sym){
			set_exp_type(sym.get().get_type());
		}else{
			UNDEFINED();
		}
	}else{
		//it's a tuple
		//TODO: the following is very ugly! fix when have time
		auto sym = sym_table_.FindSymbol(s->get_tuple_name());
		if(sym){
			auto schema = sym2schema(sym.get());
			if(schema){
				auto schema_def = schema.get();
				auto exps = schema_def->fields_->exps_;
				for(auto exp : *exps){
					ast::Field *field = dynamic_cast<ast::Field *>(exp);
					if(field->id_ == s->get_field_name()){
						set_exp_type(field->type_->type_);
						return;
					}
				}
				UNDEFINED();
			}
		}
	}
}
void TypeChecker::visit(ast::BinopExp *s){
	s->left_->accept(this);
	auto l_type = get_exp_type();
	s->right_->accept(this);
	auto r_type = get_exp_type();
	switch(s->type_){
	case ast::kBinopType::Assignment:{
		/* lvalue = exp */
		if(l_type == r_type){
			set_exp_type(l_type);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::TYPES_DONT_MATCH,PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::Equals:
	case ast::kBinopType::NotEquals:{
		if(l_type == r_type){
			set_exp_type(ast::kType::BOOL);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::TYPES_DONT_MATCH, PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::LowerThan:
	case ast::kBinopType::LowerEquals:
	case ast::kBinopType::HigherEquals:
	case ast::kBinopType::HigherThan:{
		if(l_type == ast::kType::INT && l_type == r_type){
			set_exp_type(ast::kType::BOOL);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::CAN_COMPARE_INTEGERS_ONLY,PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::Add:{
		if((l_type == ast::kType::INT || l_type == ast::kType::STRING)
				&& l_type == r_type){
			set_exp_type(l_type);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::OP_INT_OR_STR_ONLY, PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::Sub:
	case ast::kBinopType::Mult:
	case ast::kBinopType::Div:
	case ast::kBinopType::Mod:{
		if(l_type == ast::kType::INT && l_type == r_type){
			set_exp_type(ast::kType::INT);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::OP_INT_ONLY, PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::And:
	case ast::kBinopType::Or:{
		if(l_type == ast::kType::BOOL && l_type == r_type){
			set_exp_type(ast::kType::BOOL);
			return;
		}else{
			UNDEFINED();
			error::GenerateError(error::OP_BOOL_ONLY, PrettyPrint(s), s->at_line());
		}
		break;
	}

	case ast::kBinopType::Combine:
		//TODO: do this later...
		break;
	default:
		UNDEFINED();
		break;
	}
}
void TypeChecker::visit(ast::UnopExp *s){}
void TypeChecker::visit(ast::TupleopExp *s){
	//TODO: typecheck KEEP and DISCARD
}
void TypeChecker::visit(ast::FunctionExp *s){
	//Typechecking function call
	auto f_sym = sym_table_.FindSymbol(s->id_);
	if(f_sym){
		ast::Function *function = dynamic_cast<ast::Function *>(f_sym.get().get_node());
		if(function){
			if(function->args_->size() != s->exps_->size()){
				error::GenerateError(error::NOT_SAME_NUMBER_PARAMETERS,s->id_, s->at_line());
			}else{
				auto arg_it = function->args_->begin();
				auto exp_it = s->exps_->begin();
				for(int i = 0;
						arg_it != function->args_->end();
						++arg_it, ++exp_it, ++i){
					(*arg_it)->accept(this);
					auto arg_type = get_exp_type();
					(*exp_it)->accept(this);
					auto exp_type = get_exp_type();
					if(arg_type != exp_type){
						error::GenerateError(error::ARGUMENT_TYPE_DONT_MATCH,
										PrettyPrint(s), s->at_line());
						break;
					}
				}
			}
		}else{
			error::GenerateError(error::NOT_A_FUNCTION, s->id_, s->at_line());
		}
	}else{
		error::GenerateError(error::NOT_A_FUNCTION, s->id_, s->at_line());
	}
}
void TypeChecker::visit(ast::IntegerExp *s){
	set_exp_type(ast::kType::INT);
}
void TypeChecker::visit(ast::TrueExp *s){
	set_exp_type(ast::kType::BOOL);
}
void TypeChecker::visit(ast::FalseExp *s){
	set_exp_type(ast::kType::BOOL);
}
void TypeChecker::visit(ast::StringExp *s){
	set_exp_type(ast::kType::STRING);
}
void TypeChecker::visit(ast::FieldValExp *s){}
void TypeChecker::visit(ast::TupleExp *s){
	//TODO: typecheck each field
	set_exp_type(ast::kType::TUPLE);
}

}
