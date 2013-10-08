#include "ast_list.h"

ExpressionList::ExpressionList(std::list<Expression *> *exps):exps_(exps){}

void ExpressionList::PrettyPrint(){
  for(auto iterator = exps_->begin(); iterator != exps_->end(); ++iterator){
    (*iterator)->PrettyPrint();
  }
}

std::list<Expression *> *ExpressionList::getList(){
  return exps_;
}
