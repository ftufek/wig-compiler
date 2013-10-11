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


enum class kBinopType{
    Assignment, Equals
};

class BinopExp : public Exp
{
public:
    BinopExp(Exp *left, kBinopType type, Exp *right);
    void accept(Visitor *v) override;

    Exp *left_;
    kBinopType type_;
    Exp *right_;
};

}

#endif // AST_EXP_H
