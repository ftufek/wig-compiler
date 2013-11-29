#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <iostream>
#include <stack>
#include <fstream>
#include "ast.h"
#include "codegen/template.h"
#include "sym_tabler.h"

namespace visitors {

class FnCall{
public:
	FnCall(std::string fn_name,
		   std::string key,
		   std::string fn_call_exp):fn_name(fn_name),
		   unique_key(key), fn_call_exp(fn_call_exp){}
	std::string fn_name;
	std::string unique_key;
	std::string fn_call_exp;
};

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

    //info for main print stm generation
    std::list<std::string> _sessions;

    //info for session generation
    std::string _in_session;
    int _current_label;
    int NewLabel();
    void ResetLabel();
    std::list<std::string> _label_stms;
    void ClearStms();
    void PrintLabelStms(const int label,
    					std::list<std::string> stms,
    					bool jump_to_next_label = false);

    //info for function generation
    std::string _in_fn;
    std::list<FnCall> _fn_call_stms;
    void PrintFnCallStms();

    std::string CallNextLogic(const int label, const bool with_set = true);

    //info for DocumentStm generation
    std::list<std::string> _plugs;

    //info for Exp generation
    std::list<std::string> _exps;
    std::string ExpToStr(ast::Exp *s);

    //symbol tables
    void UpdateSymTable(ast::Base *node);
    st::Table _sym_table; //represents the symbol table in the current scope

    //info for global variable generation
    bool _is_generating_global_variables;
};

}

#endif // CODE_GENERATOR_H
