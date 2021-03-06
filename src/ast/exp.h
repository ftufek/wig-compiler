#ifndef AST_EXP_H
#define AST_EXP_H

#include <string>
#include <list>
#include "ast.h"
#include "type.h"

namespace ast{

class Exp : public Base
{
public:
    Exp();
    void accept(Visitor *v) override;

    void set_type(kType type);
    kType get_type() const;
    void reset_type();

private:
    kType type_;
};


class LValExp: public Exp
{
public:
    LValExp(std::string lvalue);
    void accept(Visitor *v) override;

    bool is_tuple_ref() const;
    std::string get_tuple_name() const;
    std::string get_field_name() const;
    std::string get_lvalue();

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
    ~BinopExp();
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
    ~UnopExp();
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
    ~TupleopExp();
    void accept(Visitor *v) override;

    Exp *exp_;
    kTupleopType type_;
    std::list<std::string> *ids_;
};


class FunctionExp : public Exp
{
public:
    FunctionExp(std::string id, std::list<Exp *> *exps);
    ~FunctionExp();
    void accept(Visitor *v) override;

    std::string id_;
    std::list<Exp *> *exps_;
};


class IntegerExp : public Exp
{
public:
    IntegerExp(int i);
    void accept(Visitor *v) override;

    int i_;
};

class TrueExp : public Exp
{
public:
    TrueExp();
    void accept(Visitor *v) override;
};

class FalseExp : public Exp
{
public:
    FalseExp();
    void accept(Visitor *v) override;
};


class StringExp : public Exp
{
public:
    StringExp(std::string str);
    void accept(Visitor *v) override;

    std::string str_;
};


class FieldValExp : public Exp
{
public:
    FieldValExp(std::string id, Exp *exp);
    ~FieldValExp();
    void accept(Visitor *v) override;

    std::string id_;
    Exp *exp_;
};

class TupleExp : public Exp
{
public:
    TupleExp(std::list<Exp *> *field_vals);
    ~TupleExp();
    void accept(Visitor *v) override;

    std::list<Exp *> *field_vals_;
};
}

#endif // AST_EXP_H
