#include "../ast.h"

using namespace std;

void printList(list<Expression *> *exps){
  list<Expression *>::const_iterator iterator;
  for(iterator = exps->begin(); iterator != exps->end(); ++iterator){
    (*iterator)->prettyPrint();
  }
}

ServiceExpression::ServiceExpression(list<Expression *> *htmls){
  this->htmls = htmls;
}

void ServiceExpression::prettyPrint(){
  cout<<"service {"<<endl;
  printList(htmls);
  cout<<"}"<<endl;
}

