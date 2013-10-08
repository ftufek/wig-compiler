#include "../ast.h"

using namespace std;

VariableExpression::VariableExpression(string name,
                   TypeExpression *type,
                   bool isConst,
                   Expression *value):
                   name(name), 
                   type(type), 
                   isConst(isConst),
                   value(value){}

void VariableExpression::prettyPrint(){
  if(isConst){
    cout<<"const ";
  }
  type->prettyPrint();
  cout<<" "<<name;
  if(value){
    cout<<" = ";
    value->prettyPrint();
  }
  cout<<";"<<endl;
}
