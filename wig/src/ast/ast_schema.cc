#include "../ast.h"

SchemaExpression::SchemaExpression(string id, ExpressionList *fields)
  :id(id), fields(fields){}

void SchemaExpression::prettyPrint(){
  cout<<"schema "<<id<<" {"<<endl;
  fields->prettyPrint();
  cout<<"}"<<endl;
}
