#include "../ast.h"

using namespace std;

ServiceExpression::ServiceExpression(ExpressionList *htmls,
                                     ExpressionList *schemas)
  :htmls(htmls), schemas(schemas){}

void ServiceExpression::prettyPrint(){
  cout<<"service {"<<endl;
  htmls->prettyPrint();
  cout<<endl;
  schemas->prettyPrint();
  cout<<"}"<<endl;
}

