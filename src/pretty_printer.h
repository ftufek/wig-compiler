#ifndef PRETTY_PRINTER_H
#define PRETTY_PRINTER_H

#include <iostream>
#include <fstream>
#include "ast.h"

namespace visitors {

class PrettyPrinter : public ast::Visitor
{
public:
	PrettyPrinter(std::ostream &out, bool verbose);

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
    void visit(ast::Session *s) override;

    void visit(ast::EmptyStm *s) override;
    void visit(ast::CompoundStm *s) override;
    void visit(ast::ShowStm *s) override;
    void visit(ast::DocumentStm *s) override;
    void visit(ast::PlugStm *s) override;
    void visit(ast::ReceiveStm *s) override;
    void visit(ast::InputStm *s) override;
    void visit(ast::ExitStm *s) override;
    void visit(ast::ReturnStm *s) override;
    void visit(ast::IfStm *s) override;
    void visit(ast::WhileStm *s) override;
    void visit(ast::ExpStm *s) override;

    void visit(ast::Exp *s) override;
    void visit(ast::LValExp *s) override;
    void visit(ast::BinopExp *s) override;
    void visit(ast::UnopExp *s) override;
    void visit(ast::TupleopExp *s) override;
    void visit(ast::FunctionExp *s) override;
    void visit(ast::IntegerExp *s) override;
    void visit(ast::TrueExp *s) override;
    void visit(ast::FalseExp *s) override;
    void visit(ast::StringExp *s) override;
    void visit(ast::FieldValExp *s) override;
    void visit(ast::TupleExp *s) override;

protected:
    void Indent();
    void DeIndent();
    void PrintIndent();
    void PrintSymTable(ast::Base *s, bool last_scope_only = false);
    void PrintType(ast::Exp *s);
    void PrintType(ast::kType type);

private:
    std::string indent_ = std::string("");
    std::ostream &ppout;
    bool verbose_;
};

}

#endif // PRETTY_PRINTER_H
