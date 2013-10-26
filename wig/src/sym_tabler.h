/*
 * sym_tabler.h
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#ifndef SYM_TABLER_H_
#define SYM_TABLER_H_

#include "ast_visitor.h"

namespace visitors{

/**
 * This class is a visitor that traverses the AST tree and
 * generates a symbol table for each scope. Than it associates
 * these tables with the appropriate AST node.
 *
 * For example, let's say we have the following:
 * service{
 * int a;
 * bool b;
 * }
 *
 * This class will traverse this input, it will create symbols
 * for "a" and "b". It will create the Symbol Table for the service
 * and associate the table with the Service node.
 */
class SymTabler : public ast::VisitorOptional
{
	SymTabler();
	~SymTabler();


};

}


#endif /* SYM_TABLER_H_ */
