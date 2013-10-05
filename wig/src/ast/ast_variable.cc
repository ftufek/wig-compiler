#include "../ast.h"

using namespace std;

VariableExpression::VariableExpression(string name, 
                   string type,
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
  cout<<type<<" "<<name<<" = ";
  value->prettyPrint();
  cout<<endl;
}
