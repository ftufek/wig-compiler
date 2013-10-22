/*
 * ast_visitor.cc
 *
 *  Created on: Oct 20, 2013
 *      Author: user
 */

#include "ast_visitor.h"

namespace ast{

MultipleVisitors::~MultipleVisitors(){
	for(auto it : *visitors_){
		delete(it);
	}
	delete(visitors_);
}

void MultipleVisitors::visit(Service *service){
	for(auto const visitor : *visitors_){
		service->accept(visitor);
	}
}

}


