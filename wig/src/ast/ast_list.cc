#include "../ast.h"

ExpressionList::ExpressionList(list<Expression *> *exps):exps(exps){}

void ExpressionList::prettyPrint(){
  list<Expression *>::const_iterator iterator;
  for(iterator = exps->begin(); iterator != exps->end(); ++iterator){
    (*iterator)->prettyPrint();
  }
}

list<Expression *> *ExpressionList::getList(){
  return exps;
}
