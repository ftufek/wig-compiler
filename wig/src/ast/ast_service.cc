#include "../ast.h"

using namespace std;

ServiceExpression::ServiceExpression(ExpressionList *htmls,
                                     ExpressionList *schemas,
                                     ExpressionList *globalVariables)
    :htmls(htmls), schemas(schemas), globalVariables(globalVariables){}

void ServiceExpression::prettyPrint(){
  cout<<"service {"<<endl;
  htmls->prettyPrint();
  cout<<endl;
  schemas->prettyPrint();
  cout<<endl;
  globalVariables->prettyPrint();
  cout<<"}"<<endl;
}

