#ifndef AST_STM_H
#define AST_STM_H

#include <iostream>
#include <list>
#include "ast.h"
#include "ast_variable.h"
#include "ast_exp.h"

namespace ast {

class Stm : public Base
{
public:
    Stm();
};


class CompoundStm : public Stm
{
public:
    CompoundStm(std::list<Stm *> *stms = new std::list<Stm *>,
                std::list<Variable *> *vars = new std::list<Variable *>);
    void accept(Visitor *v) override;

    std::list<Variable *> *vars_;
    std::list<Stm *> *stms_;    
};


class EmptyStm : public Stm
{
public:
    EmptyStm(bool print_semicol = false);
    void accept(Visitor *v) override;

    bool print_semicol_;
};

class PlugStm : public Stm
{
public:
    PlugStm(std::string id,
            Exp *exp);
    void accept(Visitor *v) override;

    std::string id_;
    Exp *exp_;
};

class InputStm : public Stm
{
public:
    InputStm(std::string lvalue,
             std::string id);
    void accept(Visitor *v) override;

    std::string lvalue_;
    std::string id_;
};

class DocumentStm : public Stm
{
public:
    DocumentStm(std::string id_,
                bool pluggable_ = false,
                std::list<PlugStm *> *plugs_=new std::list<PlugStm*>);
    void accept(Visitor *v) override;

    std::string id_;
    bool pluggable_;
    std::list<PlugStm *> *plugs_;
};


class ShowStm : public Stm
{
public:
    ShowStm(DocumentStm *doc,
            Stm *receive);
    void accept(Visitor *v) override;

    DocumentStm *doc_;
    Stm *receive_;
};


class ReceiveStm : public Stm
{
public:
    ReceiveStm(std::list<Stm *> *inputs = new std::list<Stm *>);
    void accept(Visitor *v) override;

    std::list<Stm *> *inputs_;
};

}

#endif // AST_STM_H
