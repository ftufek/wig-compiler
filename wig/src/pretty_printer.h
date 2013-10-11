#ifndef PRETTY_PRINTER_H
#define PRETTY_PRINTER_H

#include "ast.h"

namespace pp {

class PrettyPrintVisitor : public ast::Visitor
{
public:
    virtual void visit(ast::Base *s) override;
    void visit(ast::Service *s) override;
    virtual void visit(ast::Whatever *s ) override;
    virtual void visit(ast::Variable *s) override;
    virtual void visit(ast::Function *s) override;
    virtual void visit(ast::Field *s) override;
    virtual void visit(ast::Empty *s) override;
    virtual void visit(ast::HtmlTag *s) override;
    virtual void visit(ast::Argument *s) override;
    virtual void visit(ast::MetaTag *s) override;
    virtual void visit(ast::Schema *s) override;
    virtual void visit(ast::String *s) override;
    virtual void visit(ast::List *s) override;

    virtual void visit(ast::Stm *s) override;
    virtual void visit(ast::EmptyStm *s) override;
    virtual void visit(ast::CompoundStm *s) override;
};

}

#endif // PRETTY_PRINTER_H
