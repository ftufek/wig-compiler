/*
 * sym_tabler.h
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#ifndef SYM_TABLER_H_
#define SYM_TABLER_H_

#include "ast.h"
#include "symbol_table/table.h"

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
class SymTabler : public ast::Visitor
{
public:
	SymTabler();
	~SymTabler();

	void visit(ast::Service *s);
	void visit(ast::Whatever *s);
	void visit(ast::Variable *s);
	void visit(ast::Function *s);
	void visit(ast::Field *s);
	void visit(ast::Empty *s);
	void visit(ast::HtmlTag *s);
	void visit(ast::Argument *s);
	void visit(ast::MetaTag *s);
	void visit(ast::Schema *s);
	void visit(ast::String *s);
	void visit(ast::List *s);
	void visit(ast::Type *s);
	void visit(ast::Session *s);

	void visit(ast::EmptyStm *s);
	void visit(ast::CompoundStm *s);
	void visit(ast::ShowStm *s);
	void visit(ast::DocumentStm *s);
	void visit(ast::PlugStm *s);
	void visit(ast::InputStm *s);
	void visit(ast::ReceiveStm *s);
	void visit(ast::ExitStm *s);
	void visit(ast::ReturnStm *s);
	void visit(ast::IfStm *s);
	void visit(ast::WhileStm *s);
	void visit(ast::ExpStm *s);

	void visit(ast::Exp *s);
	void visit(ast::LValExp *s);
	void visit(ast::BinopExp *s);
	void visit(ast::UnopExp *s);
	void visit(ast::TupleopExp *s);
	void visit(ast::FunctionExp *s);
	void visit(ast::IntegerExp *s);
	void visit(ast::TrueExp *s);
	void visit(ast::FalseExp *s);
	void visit(ast::StringExp *s);
	void visit(ast::FieldValExp *s);
	void visit(ast::TupleExp *s);

private:
	st::Table sym_table_;
};

}


#endif /* SYM_TABLER_H_ */
