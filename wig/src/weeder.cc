/*
 * weeder.cc
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#include <iostream>
#include "weeder.h"

namespace visitors {

Weeder::Weeder() {}
Weeder::~Weeder() {}

bool Weeder::is_valid(){
	return is_valid_;
}

void Weeder::visit(ast::Service *s){
    s->functions_->accept(this);
    s->sessions_->accept(this);
}

void Weeder::visit(ast::Whatever *s ) {
}

void Weeder::visit(ast::Variable *s) {
    s->type_->accept(this);
    if(s->value_){
        s->value_->accept(this);
    }
}

void Weeder::visit(ast::Function *s) {
	temp_ends_with_return_ = false;
	s->stm_->accept(this);
	if(!temp_ends_with_return_ && s->type_->type_ != ast::kType::VOID){
		is_valid_ = false;
		std::cerr<<"ERROR: Function "<<s->id_<<" doesn't end with a return statement!"<<std::endl;
	}
	temp_ends_with_return_ = false;
}

void Weeder::visit(ast::Field *s) {
    s->type_->accept(this);
}

void Weeder::visit(ast::Empty *) {}

void Weeder::visit(ast::HtmlTag *s) {
}

void Weeder::visit(ast::Argument *s) {
    s->type_->accept(this);
}

void Weeder::visit(ast::MetaTag *s) {
}

void Weeder::visit(ast::Schema *s) {
    s->fields_->accept(this);
}

void Weeder::visit(ast::String *s) {
}

void Weeder::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void Weeder::visit(ast::Type *s) {
}

void Weeder::visit(ast::Session *s){
	temp_ends_with_return_ = false;
    s->stm_->accept(this);
    if(!temp_ends_with_return_){
    	is_valid_ = false;
    	std::cerr<<"ERROR: Session "<<s->id_<<" doesn't end with a return statement!"<<std::endl;
    }
    temp_ends_with_return_ = false;
}

void Weeder::visit(ast::EmptyStm *s) {
}

void Weeder::visit(ast::CompoundStm *s) {
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
    	temp_ends_with_return_ = false;
        stm->accept(this);
    }
}

void Weeder::visit(ast::ShowStm *s) {
    s->doc_->accept(this);
    s->receive_->accept(this);
}

void Weeder::visit(ast::DocumentStm *s){
    if(s->pluggable_){
        auto it = s->plugs_->begin();
        if(it != s->plugs_->end()){
            (*it)->accept(this);
            ++it;
        }
        for(; it != s->plugs_->end(); ++it){
            (*it)->accept(this);
        }
    }else{
    }
}

void Weeder::visit(ast::PlugStm *s){
    s->exp_->accept(this);
}

void Weeder::visit(ast::ReceiveStm *s){
    auto it = s->inputs_->begin();
    if(it != s->inputs_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->inputs_->end(); ++it){
        (*it)->accept(this);
    }
}

void Weeder::visit(ast::InputStm *s){
}

void Weeder::visit(ast::ExitStm *s){
    temp_ends_with_return_ = true;
}

void Weeder::visit(ast::ReturnStm *s){
    temp_ends_with_return_ = true;
}

void Weeder::visit(ast::IfStm *s){
	//For if statements, both branches have to return otherwise it's an error
    s->condition_->accept(this);
    s->true_stm_->accept(this);
    if(s->else_stm_ != nullptr){
    	bool temp = temp_ends_with_return_;
    	temp_ends_with_return_ = false;
        s->else_stm_->accept(this);
        if(temp && temp_ends_with_return_){
        	temp_ends_with_return_ = true;
        }
        temp_ends_with_return_ = temp;
    }
}

void Weeder::visit(ast::WhileStm *s){
    s->condition_->accept(this);
    s->stm_->accept(this);
}

void Weeder::visit(ast::ExpStm *s){
    s->exp_->accept(this);
}

void Weeder::visit(ast::Exp *){
}

void Weeder::visit(ast::LValExp *s){
}

void Weeder::visit(ast::BinopExp *s){
    s->left_->accept(this);
    s->right_->accept(this);
}

void Weeder::visit(ast::UnopExp *s){
    s->exp_->accept(this);
}

void Weeder::visit(ast::TupleopExp *s){
    s->exp_->accept(this);
}

void Weeder::visit(ast::FunctionExp *s){
    auto it = s->exps_->begin();
    if(it != s->exps_->end()){
        (*it)->accept(this);
        ++it;
    }

    for(; it != s->exps_->end(); ++it){
        (*it)->accept(this);
    }
}

void Weeder::visit(ast::IntegerExp *s){
}

void Weeder::visit(ast::TrueExp *){
}

void Weeder::visit(ast::FalseExp *){
}

void Weeder::visit(ast::StringExp *s){
}

void Weeder::visit(ast::FieldValExp *s){
    s->exp_->accept(this);
}

void Weeder::visit(ast::TupleExp *s){
    auto it = s->field_vals_->begin();
    if(it != s->field_vals_->end()){
        (*it)->accept(this);
        ++it;
    }
    for(; it != s->field_vals_->end(); ++it){
        (*it)->accept(this);
    }
}

}
