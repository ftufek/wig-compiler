#include "../ast.h"

SchemaExpression::SchemaExpression(std::string id, ExpressionList *fields)
  :id(id), fields(fields){}

void SchemaExpression::prettyPrint(){
  std::cout<<"schema "<<id<<" {"<<std::endl;
  fields->prettyPrint();
  std::cout<<"}"<<std::endl;
}
