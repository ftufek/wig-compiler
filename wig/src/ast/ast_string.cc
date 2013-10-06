#include "../ast.h"

StringExpression::StringExpression(string content)
  :content(content){}

void StringExpression::prettyPrint(){
  cout<<"\""<<content<<"\"";
}
