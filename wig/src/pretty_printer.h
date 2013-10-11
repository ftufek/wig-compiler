#ifndef PRETTY_PRINTER_H
#define PRETTY_PRINTER_H

#include "ast.h"

namespace pp {

class PrettyPrintVisitor : public ast::Visitor
{
public:
    void visit(ast::Service *s) override;
    void visit(ast::Whatever *s ) override;
    void visit(ast::Variable *s) override;
    void visit(ast::Function *s) override;
    void visit(ast::Field *s) override;
    void visit(ast::Empty *s) override;
    void visit(ast::HtmlTag *s) override;
    void visit(ast::Argument *s) override;
    void visit(ast::MetaTag *s) override;
    void visit(ast::Schema *s) override;
    void visit(ast::String *s) override;
    void visit(ast::List *s) override;
    void visit(ast::Type *s) override;

    void visit(ast::EmptyStm *s) override;
    void visit(ast::CompoundStm *s) override;
};

}

#endif // PRETTY_PRINTER_H
