#include "../ast.h"

StringExpression::StringExpression(std::string content)
  :content(content){}

void StringExpression::prettyPrint(){
  std::cout<<"\""<<content<<"\"";
}
