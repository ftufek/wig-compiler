#include "../ast.h"

MetaTagExpression::MetaTagExpression(std::string content)
  :content(content){}

void MetaTagExpression::prettyPrint(){
  std::cout<<"<!-- ";
  std::cout<<content;
  std::cout<<" -->";
}
