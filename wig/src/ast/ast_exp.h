#ifndef AST_EXP_H
#define AST_EXP_H

#include <string>
#include "ast.h"

namespace ast{

class Exp : public Base
{
public:
    Exp();
    void accept(Visitor *v) override;
};


class LValExp: public Exp
{
public:
    LValExp(std::string lvalue);
    void accept(Visitor *v) override;

    std::string lvalue_;
};

}

#endif // AST_EXP_H
