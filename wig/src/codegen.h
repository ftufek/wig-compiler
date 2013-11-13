#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <iostream>
#include <fstream>
#include "ast.h"
#include "codegen/template.h"

namespace visitors {

class CodeGenerator : public ast::Visitor
{
public:
	CodeGenerator(std::ostream &out);

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

private:
    std::ostream &cgout;

    std::string PrettyPrint(ast::Base *s);


    //info for schema to python class generation
    std::list<std::pair<std::string, std::string>> _fields;
};

}

#endif // CODE_GENERATOR_H
