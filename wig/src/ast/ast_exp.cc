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

}
