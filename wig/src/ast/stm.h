#ifndef AST_STM_H
#define AST_STM_H

#include <iostream>
#include <list>
#include "ast.h"
#include "variable.h"
#include "exp.h"

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
                std::list<Base *> *vars = new std::list<Base *>);
    void accept(Visitor *v) override;

    std::list<Base *> *vars_;
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


class ReceiveStm : public Stm
{
public:
    ReceiveStm(std::list<Stm *> *inputs = new std::list<Stm *>);
    void accept(Visitor *v) override;

    std::list<Stm *> *inputs_;
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


class ExitStm : public Stm
{
public:
    ExitStm(DocumentStm *doc);
    void accept(Visitor *v) override;

    DocumentStm *doc_;
};


class ReturnStm : public Stm
{
public:
    ReturnStm(Exp *exp = new Exp());
    void accept(Visitor *v) override;

    Exp *exp_;
};


class IfStm : public Stm
{
public:
    IfStm(Exp *condition,
          Stm *true_stm,
          Stm *else_stm = nullptr);
    void accept(Visitor *v) override;

    Exp *condition_;
    Stm *true_stm_;
    Stm *else_stm_;
};


class WhileStm : public Stm
{
public:
    WhileStm(Exp *condition,
             Stm *stm);
    void accept(Visitor *v) override;

    Exp *condition_;
    Stm *stm_;
};


class ExpStm : public Stm
{
public:
    ExpStm(Exp *exp);
    void accept(Visitor *v) override;

    Exp *exp_;
};

}

#endif // AST_STM_H
