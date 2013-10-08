#ifndef AST_STM_H
#define AST_STM_H

#include <iostream>
#include "ast.h"

namespace ast {

class Stm : public Base
{
public:
    Stm();
};

class EmptyStm : public Stm
{
public:
    EmptyStm();
    void PrettyPrint() override{
        std::cout<<";"<<std::endl;
    }
};

}

#endif // AST_STM_H
