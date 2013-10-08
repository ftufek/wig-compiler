#ifndef AST_STM_H
#define AST_STM_H

#include <iostream>
#include "ast.h"

class StmExpression : public Expression
{
public:
    StmExpression();
};

class EmptyStmExpression : public StmExpression
{
public:
    EmptyStmExpression();
    void PrettyPrint() override{
        std::cout<<";"<<std::endl;
    }
};

#endif // AST_STM_H
