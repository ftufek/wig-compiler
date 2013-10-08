#include "../ast.h"

using namespace std;

FieldExpression::FieldExpression(TypeExpression *type, string id)
  :type(type), id(id){}

void FieldExpression::PrettyPrint(){
  type->PrettyPrint();
  cout<<" "<<id<<";"<<endl;
}
