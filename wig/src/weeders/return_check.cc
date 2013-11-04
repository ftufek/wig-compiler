/*
 * ReturnCheck.cc
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#include <iostream>
#include "return_check.h"
#include "../error.h"

namespace visitors {

ReturnCheck::ReturnCheck() {}
ReturnCheck::~ReturnCheck() {}

bool ReturnCheck::is_valid(){
	return is_valid_;
}

void ReturnCheck::visit(ast::Service *s){
    s->functions_->accept(this);
    s->sessions_->accept(this);
}

void ReturnCheck::visit(ast::Function *s) {
	temp_ends_with_return_ = false;
	s->stm_->accept(this);
	if(!temp_ends_with_return_ && s->type_->type_ != ast::kType::VOID){
		is_valid_ = false;
		error::GenerateError(error::NO_RETURN, s->id_, s->at_line());
	}
	temp_ends_with_return_ = false;
}

void ReturnCheck::visit(ast::List *s) {
    for(auto const &exp : *(s->exps_)){
        exp->accept(this);
    }
}

void ReturnCheck::visit(ast::Session *s){
	temp_ends_with_return_ = false;
    s->stm_->accept(this);
    if(!temp_ends_with_return_){
    	is_valid_ = false;
    	error::GenerateError(error::NO_RETURN, s->id_, s->at_line());
    }
    temp_ends_with_return_ = false;
}

void ReturnCheck::visit(ast::CompoundStm *s) {
    for(auto const &var : *(s->vars_)){
        var->accept(this);
    }
    for(auto const &stm : *(s->stms_)){
    	temp_ends_with_return_ = false;
        stm->accept(this);
    }
}

void ReturnCheck::visit(ast::ExitStm *s){
    temp_ends_with_return_ = true;
}

void ReturnCheck::visit(ast::ReturnStm *s){
    temp_ends_with_return_ = true;
}

void ReturnCheck::visit(ast::IfStm *s){
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
}
