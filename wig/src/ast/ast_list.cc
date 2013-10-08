#include "../ast.h"

ExpressionList::ExpressionList(std::list<Expression *> *exps):exps(exps){}

void ExpressionList::prettyPrint(){
  std::list<Expression *>::const_iterator iterator;
  for(iterator = exps->begin(); iterator != exps->end(); ++iterator){
    (*iterator)->prettyPrint();
  }
}

std::list<Expression *> *ExpressionList::getList(){
  return exps;
}
