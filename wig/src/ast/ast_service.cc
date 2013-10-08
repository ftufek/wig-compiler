#include "../ast.h"

using namespace std;

ServiceExpression::ServiceExpression(ExpressionList *htmls,
                                     ExpressionList *schemas,
                                     ExpressionList *functions,
                                     ExpressionList *globalVariables)
                                    :htmls_(htmls),
                                     schemas_(schemas),
                                     functions_(functions),
                                     global_variables_(globalVariables){}

void ServiceExpression::PrettyPrint(){
  cout<<"service {"<<endl;
  htmls_->PrettyPrint();
  cout<<endl;
  schemas_->PrettyPrint();
  cout<<endl;
  global_variables_->PrettyPrint();
  cout<<endl;
  functions_->PrettyPrint();
  cout<<"}"<<endl;
}

