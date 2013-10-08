#include <iostream>
#include "ast_string.h"

StringExpression::StringExpression(std::string content)
  :content_(content){}

void StringExpression::PrettyPrint(){
  std::cout<<"\""<<content_<<"\"";
}
