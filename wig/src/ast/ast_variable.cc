#include <iostream>
#include "ast_variable.h"

using namespace std;

VariableExpression::VariableExpression(string name,
                   TypeExpression *type,
                   bool isConst,
                   Expression *value):
                   name_(name),
                   type_(type),
                   is_const_(isConst),
                   value_(value){}

void VariableExpression::PrettyPrint(){
  if(is_const_){
    cout<<"const ";
  }
  type_->PrettyPrint();
  cout<<" "<<name_;
  if(value_){
    cout<<" = ";
    value_->PrettyPrint();
  }
  cout<<";"<<endl;
}
