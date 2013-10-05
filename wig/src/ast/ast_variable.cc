#include "../ast.h"

using namespace std;

VariableExpression::VariableExpression(string *name){
  this->name = name;
}

void VariableExpression::prettyPrint(){
  cout<<"Variable "<<name<<endl;
}
