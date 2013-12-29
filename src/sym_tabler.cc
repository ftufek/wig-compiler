/*
 * sym_tabler.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "sym_tabler.h"

namespace visitors{

SymTabler::SymTabler(): sym_table_(st::Table()), _function_arg_syms({}){};
SymTabler::~SymTabler(){};

void SymTabler::visit(ast::Service *s){
	sym_table_.Scope();
	s->htmls_->accept(this);
	s->schemas_->accept(this);
	s->global_variables_->accept(this);
	s->functions_->accept(this);
	s->sessions_->accept(this);
	s->set_sym_table(new st::Table(sym_table_));
}
void SymTabler::visit(ast::Whatever *s){}

void SymTabler::visit(ast::Variable *s){
	sym_table_.PutSymbol(st::Symbol::ForVariable(s));
	if(s->type_->type_ == ast::kType::HTML && s->value_){
		sym_table_.Scope();
		s->value_->accept(this);
		s->set_sym_table(new st::Table(sym_table_));
		sym_table_.UnScope();
	}
}

void SymTabler::visit(ast::Function *s){
	sym_table_.PutSymbol(st::Symbol::ForFunction(s));
	//Need to add function arguments to the symbols available in the scope
	for(auto arg : *(s->args_)){
		_function_arg_syms.push_back(st::Symbol::ForArgument(arg));
	}
	s->stm_->accept(this);
	_function_arg_syms.clear();
}
void SymTabler::visit(ast::Field *s){
	sym_table_.PutSymbol(st::Symbol::ForField(s));
}
void SymTabler::visit(ast::Empty *s){}
void SymTabler::visit(ast::HtmlTag *s){
	if(s->is_gap_ || s->id_ == "input" || s->id_ == "select"){
		sym_table_.PutSymbol(st::Symbol::ForHtmlTag(s));
	}
}
void SymTabler::visit(ast::Argument *s){}
void SymTabler::visit(ast::MetaTag *s){}
void SymTabler::visit(ast::Schema *s){
	sym_table_.PutSymbol(st::Symbol::ForSchema(s));
	sym_table_.Scope();
	s->fields_->accept(this);
	s->set_sym_table(new st::Table(sym_table_));
	sym_table_.UnScope();
}
void SymTabler::visit(ast::String *s){}

void SymTabler::visit(ast::List *s){
	for(auto it : *(s->exps_)){
		it->accept(this);
	}
}

void SymTabler::visit(ast::Type *s){}
void SymTabler::visit(ast::Session *s){
	sym_table_.PutSymbol(st::Symbol::ForSession(s));
	s->stm_->accept(this);
}

void SymTabler::visit(ast::EmptyStm *s){}
void SymTabler::visit(ast::CompoundStm *s){
	sym_table_.Scope();
	for(auto sym : _function_arg_syms){
		sym_table_.PutSymbol(sym);
	}
	_function_arg_syms.clear();
	for(auto it : *(s->vars_)){
		it->accept(this);
	}
	for(auto stm : *(s->stms_)){
		stm->accept(this);
	}
	s->set_sym_table(new st::Table(sym_table_));
	sym_table_.UnScope();
}
void SymTabler::visit(ast::ShowStm *s){}
void SymTabler::visit(ast::DocumentStm *s){}
void SymTabler::visit(ast::PlugStm *s){}
void SymTabler::visit(ast::InputStm *s){}
void SymTabler::visit(ast::ReceiveStm *s){}
void SymTabler::visit(ast::ExitStm *s){}
void SymTabler::visit(ast::ReturnStm *s){}
void SymTabler::visit(ast::IfStm *s){
	s->true_stm_->accept(this);
	if(s->else_stm_){
		s->else_stm_->accept(this);
	}
}
void SymTabler::visit(ast::WhileStm *s){
	s->stm_->accept(this);
}
void SymTabler::visit(ast::ExpStm *s){}

void SymTabler::visit(ast::Exp *s){}
void SymTabler::visit(ast::LValExp *s){}
void SymTabler::visit(ast::BinopExp *s){}
void SymTabler::visit(ast::UnopExp *s){}
void SymTabler::visit(ast::TupleopExp *s){}
void SymTabler::visit(ast::FunctionExp *s){}
void SymTabler::visit(ast::IntegerExp *s){}
void SymTabler::visit(ast::TrueExp *s){}
void SymTabler::visit(ast::FalseExp *s){}
void SymTabler::visit(ast::StringExp *s){}
void SymTabler::visit(ast::FieldValExp *s){}
void SymTabler::visit(ast::TupleExp *s){}


}
