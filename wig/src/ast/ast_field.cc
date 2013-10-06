#include "../ast.h"

FieldExpression::FieldExpression(Type type, string id)
  :type(type), id(id){}

void FieldExpression::prettyPrint(){
  cout<<typeToStr(type)<<" "<<id<<";"<<endl;
}
