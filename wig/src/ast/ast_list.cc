#include "ast_list.h"

ExpressionList::ExpressionList(std::list<Expression *> *exps):exps_(exps){}

void ExpressionList::PrettyPrint(){
  for(auto const &exp : *exps_){
      exp->PrettyPrint();
  }
}

std::list<Expression *> *ExpressionList::getList(){
  return exps_;
}
