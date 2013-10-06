#include "../ast.h"

using namespace std;

ServiceExpression::ServiceExpression(ExpressionList *htmls)
  :htmls(htmls){}

void ServiceExpression::prettyPrint(){
  cout<<"service {"<<endl;
  htmls->prettyPrint();
  cout<<"}"<<endl;
}

