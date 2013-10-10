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
};

class CompoundStm : public Stm
{
public:
    CompoundStm(std::list<Variable *> *vars = new std::list<Variable *>,
                std::list<Stm *> *stms = new std::list<Stm *>);
    void PrettyPrint() override;

protected:
    std::list<Variable *> *vars_;
    std::list<Stm *> *stms_;
};

class EmptyStm : public Stm
{
public:
    EmptyStm();
    void PrettyPrint() override;
};

}

#endif // AST_STM_H
