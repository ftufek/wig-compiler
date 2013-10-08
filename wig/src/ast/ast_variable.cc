#include <iostream>
#include "ast_variable.h"

using namespace std;

namespace ast {

Variable::Variable(string name,
                   Type *type,
                   bool isConst,
                   Base *value):
                   name_(name),
                   type_(type),
                   is_const_(isConst),
                   value_(value){}

void Variable::PrettyPrint(){
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

}
