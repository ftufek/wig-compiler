#include "ast_exp.h"
#include "ast_visitor.h"

namespace ast{

Exp::Exp(){}
void Exp::accept(Visitor *v) { v->visit(this); }


LValExp::LValExp(std::string lvalue):lvalue_(lvalue){}
void LValExp::accept(Visitor *v) { v->visit(this); }


BinopExp::BinopExp(Exp *left, kBinopType type, Exp *right)
    :left_(left), type_(type), right_(right){}
void BinopExp::accept(Visitor *v) { v->visit(this); }


UnopExp::UnopExp(kUnopType type, Exp *exp):type_(type), exp_(exp){}
void UnopExp::accept(Visitor *v) { v->visit(this); }


TupleopExp::TupleopExp(Exp *exp, kTupleopType type, std::list<std::string> *ids)
    :exp_(exp), type_(type), ids_(ids) {}
void TupleopExp::accept(Visitor *v) { v->visit(this); }


FunctionExp::FunctionExp(std::string id, std::list<Exp *> *exps)
    :id_(id), exps_(exps) {}
void FunctionExp::accept(Visitor *v) { v->visit(this); }


IntegerExp::IntegerExp(int i) :i_(i) {}
void IntegerExp::accept(Visitor *v) { v->visit(this); }


TrueExp::TrueExp(){}
void TrueExp::accept(Visitor *v) { v->visit(this); }

FalseExp::FalseExp(){}
void FalseExp::accept(Visitor *v) { v->visit(this); }


StringExp::StringExp(std::string str) :str_(str) {}
void StringExp::accept(Visitor *v) { v->visit(this); }


FieldValExp::FieldValExp(std::string id, Exp *exp):id_(id), exp_(exp){}
void FieldValExp::accept(Visitor *v) { v->visit(this); }

TupleExp::TupleExp(std::list<Exp *> *field_vals):field_vals_(field_vals){}
void TupleExp::accept(Visitor *v) { v->visit(this); }
}
