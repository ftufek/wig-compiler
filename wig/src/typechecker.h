/*
 * typechecker.h
 *
 *  Created on: Oct 29, 2013
 *      Author: user
 */

#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include <boost/optional.hpp>
#include "ast.h"
#include "symbol_table/table.h"

namespace visitors{

class TypeChecker : public ast::Visitor
{
public:
	TypeChecker();
	virtual ~TypeChecker();

    virtual void visit(ast::Service *s);
    virtual void visit(ast::Whatever *s);
    virtual void visit(ast::Variable *s);
    virtual void visit(ast::Function *s);
    virtual void visit(ast::Field *s);
    virtual void visit(ast::Empty *s);
    virtual void visit(ast::HtmlTag *s);
    virtual void visit(ast::Argument *s);
    virtual void visit(ast::MetaTag *s);
    virtual void visit(ast::Schema *s);
    virtual void visit(ast::String *s);
    virtual void visit(ast::List *s);
    virtual void visit(ast::Type *s);
    virtual void visit(ast::Session *s);

    virtual void visit(ast::EmptyStm *s);
    virtual void visit(ast::CompoundStm *s);
    virtual void visit(ast::ShowStm *s);
    virtual void visit(ast::DocumentStm *s);
    virtual void visit(ast::PlugStm *s);
    virtual void visit(ast::InputStm *s);
    virtual void visit(ast::ReceiveStm *s);
    virtual void visit(ast::ExitStm *s);
    virtual void visit(ast::ReturnStm *s);
    virtual void visit(ast::IfStm *s);
    virtual void visit(ast::WhileStm *s);
    virtual void visit(ast::ExpStm *s);

    virtual void visit(ast::Exp *s);
    virtual void visit(ast::LValExp *s);
    virtual void visit(ast::BinopExp *s);
    virtual void visit(ast::UnopExp *s);
    virtual void visit(ast::TupleopExp *s);
    virtual void visit(ast::FunctionExp *s);
    virtual void visit(ast::IntegerExp *s);
    virtual void visit(ast::TrueExp *s);
    virtual void visit(ast::FalseExp *s);
    virtual void visit(ast::StringExp *s);
    virtual void visit(ast::FieldValExp *s);
    virtual void visit(ast::TupleExp *s);

private:
    ast::kType get_exp_type();
    void set_exp_type(ast::kType type);
    std::string PrettyPrint(ast::Exp *node);
    void UpdateSymTable(ast::Base *node);

    st::Table sym_table_; //represents the symbol table in the current scope
    boost::optional<ast::kType> exp_type_;
};

}


#endif /* TYPECHECKER_H_ */
