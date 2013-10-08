#include <iostream>
#include "ast_meta.h"

MetaTagExpression::MetaTagExpression(std::string content)
  :content_(content){}

void MetaTagExpression::PrettyPrint(){
  std::cout<<"<!-- ";
  std::cout<<content_;
  std::cout<<" -->";
}
