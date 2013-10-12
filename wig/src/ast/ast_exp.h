#ifndef AST_EXP_H
#define AST_EXP_H

#include <string>
#include <list>
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
    Assignment, Equals, NotEquals, LowerThan,
    HigherThan, LowerEquals, HigherEquals,
    Add, Sub, Mult, Div, Mod,
    And, Or,
    Combine
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


enum class kUnopType{
    LogicNegate, Minus
};

class UnopExp : public Exp
{
public:
    UnopExp(kUnopType type, Exp *exp);
    void accept(Visitor *v) override;

    kUnopType type_;
    Exp *exp_;
};


enum class kTupleopType{
    Keep, Discard
};

class TupleopExp : public Exp
{
public:
    TupleopExp(Exp *exp,
               kTupleopType type,
               std::list<std::string> *ids);
    void accept(Visitor *v) override;

    Exp *exp_;
    kTupleopType type_;
    std::list<std::string> *ids_;
};


class FunctionExp : public Exp
{
public:
    FunctionExp(std::string id, std::list<Exp *> *exps);
    void accept(Visitor *v) override;

    std::string id_;
    std::list<Exp *> *exps_;
};

}

#endif // AST_EXP_H
