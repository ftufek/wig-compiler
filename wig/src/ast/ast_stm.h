#ifndef AST_STM_H
#define AST_STM_H

#include <iostream>
#include <list>
#include "ast.h"
#include "ast_variable.h"

namespace ast {

class Stm : public Base
{
public:
    Stm();
    void accept(Visitor *v) override;
};

class CompoundStm : public Stm
{
public:
    CompoundStm(std::list<Stm *> *stms = new std::list<Stm *>,
                std::list<Variable *> *vars = new std::list<Variable *>);
    void accept(Visitor *v) override;

protected:
    std::list<Variable *> *vars_;
    std::list<Stm *> *stms_;    
};

class EmptyStm : public Stm
{
public:
    EmptyStm(bool print_semicol = false);
    void accept(Visitor *v) override;

protected:
    bool print_semicol_;
};

}

#endif // AST_STM_H
