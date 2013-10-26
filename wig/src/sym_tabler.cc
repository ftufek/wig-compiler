/*
 * sym_tabler.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "sym_tabler.h"

namespace visitors{

SymTabler::SymTabler(): sym_table_(st::Table()){};
SymTabler::~SymTabler(){};

void SymTabler::visit(ast::Service *s){
	sym_table_.Scope();
	s->global_variables_->accept(this);
	s->set_sym_table(new st::Table(sym_table_));
}
void SymTabler::visit(ast::Whatever *s){}

void SymTabler::visit(ast::Variable *s){
	sym_table_.PutSymbol(s->name_, st::Symbol::VARIABLE);
}

void SymTabler::visit(ast::Function *s){}
void SymTabler::visit(ast::Field *s){}
void SymTabler::visit(ast::Empty *s){}
void SymTabler::visit(ast::HtmlTag *s){
	sym_table_.PutSymbol(s->id_, st::Symbol::HTML);
}
void SymTabler::visit(ast::Argument *s){}
void SymTabler::visit(ast::MetaTag *s){}
void SymTabler::visit(ast::Schema *s){}
void SymTabler::visit(ast::String *s){}

void SymTabler::visit(ast::List *s){
	for(auto it : *(s->exps_)){
		it->accept(this);
	}
}

void SymTabler::visit(ast::Type *s){}
void SymTabler::visit(ast::Session *s){}

void SymTabler::visit(ast::EmptyStm *s){}
void SymTabler::visit(ast::CompoundStm *s){}
void SymTabler::visit(ast::ShowStm *s){}
void SymTabler::visit(ast::DocumentStm *s){}
void SymTabler::visit(ast::PlugStm *s){}
void SymTabler::visit(ast::InputStm *s){}
void SymTabler::visit(ast::ReceiveStm *s){}
void SymTabler::visit(ast::ExitStm *s){}
void SymTabler::visit(ast::ReturnStm *s){}
void SymTabler::visit(ast::IfStm *s){}
void SymTabler::visit(ast::WhileStm *s){}
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
