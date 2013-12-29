/*
 * ast.cc
 *
 *  Created on: Oct 27, 2013
 *      Author: user
 */

#include "ast.h"

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
