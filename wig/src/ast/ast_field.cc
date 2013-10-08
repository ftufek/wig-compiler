#include "../ast.h"

using namespace std;

FieldExpression::FieldExpression(Type type, string id)
  :type(type), id(id){}

void FieldExpression::prettyPrint(){
  cout<<typeToStr(type)<<" "<<id<<";"<<endl;
}
