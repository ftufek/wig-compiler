/*
 * ast_visitor.cc
 *
 *  Created on: Oct 20, 2013
 *      Author: user
 */

#include "ast_visitor.h"

namespace ast{

void MultipleVisitors::visit(Service *service){
	for(auto const visitor : *visitors_){
		service->accept(visitor);
	}
}

}


