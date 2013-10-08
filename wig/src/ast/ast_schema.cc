#include <iostream>
#include "ast_schema.h"

SchemaExpression::SchemaExpression(std::string id, ExpressionList *fields)
  :id_(id), fields_(fields){}

void SchemaExpression::PrettyPrint(){
  std::cout<<"schema "<<id_<<" {"<<std::endl;
  fields_->PrettyPrint();
  std::cout<<"}"<<std::endl;
}
