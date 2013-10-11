#ifndef AST_EXP_H
#define AST_EXP_H

#include "ast.h"

namespace ast{

class Exp : public Base
{
public:
    Exp();
    void accept(Visitor *v) override;
};

}

#endif // AST_EXP_H
