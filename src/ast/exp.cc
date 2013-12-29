#include "exp.h"
#include "../ast.h"

namespace ast{

Exp::Exp():type_(kType::UNDEFINED){}
void Exp::accept(Visitor *v) { v->visit(this); }
void Exp::set_type(kType type){
	type_ = type;
}
kType Exp::get_type() const{
	return type_;
}
void Exp::reset_type(){
	type_ = kType::UNDEFINED;
}


LValExp::LValExp(std::string lvalue):lvalue_(lvalue){}
void LValExp::accept(Visitor *v) { v->visit(this); }
bool LValExp::is_tuple_ref() const{
	return lvalue_. find(".") < lvalue_.size();
}
std::string LValExp::get_tuple_name() const{
	return lvalue_.substr(0, lvalue_.find("."));
}
std::string LValExp::get_field_name() const{
	return lvalue_.substr(lvalue_.find(".")+1);
}
std::string LValExp::get_lvalue(){
	return lvalue_;
}


BinopExp::BinopExp(Exp *left, kBinopType type, Exp *right)
    :left_(left), type_(type), right_(right){}
BinopExp::~BinopExp(){
	delete(left_);
	delete(right_);
}
void BinopExp::accept(Visitor *v) { v->visit(this); }


UnopExp::UnopExp(kUnopType type, Exp *exp):type_(type), exp_(exp){}
UnopExp::~UnopExp(){
	delete(exp_);
}
void UnopExp::accept(Visitor *v) { v->visit(this); }


TupleopExp::TupleopExp(Exp *exp, kTupleopType type, std::list<std::string> *ids)
    :exp_(exp), type_(type), ids_(ids) {}
TupleopExp::~TupleopExp(){
	delete(exp_);
	delete(ids_);
}
void TupleopExp::accept(Visitor *v) { v->visit(this); }


FunctionExp::FunctionExp(std::string id, std::list<Exp *> *exps)
    :id_(id), exps_(exps) {}
FunctionExp::~FunctionExp(){
	delete(exps_);
}
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
FieldValExp::~FieldValExp(){
	delete(exp_);
}
void FieldValExp::accept(Visitor *v) { v->visit(this); }

TupleExp::TupleExp(std::list<Exp *> *field_vals):field_vals_(field_vals){}
TupleExp::~TupleExp(){
	for(auto it : *field_vals_){
		delete(it);
	}
	delete(field_vals_);
}
void TupleExp::accept(Visitor *v) { v->visit(this); }
}
