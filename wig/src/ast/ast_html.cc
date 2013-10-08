#include "../ast.h"

HtmlTagExpression::HtmlTagExpression
    (std::string id, std::map<std::string, std::string> *attrs, bool isClosing, bool isGap)
    :id(id), attrs(attrs), isClosing(isClosing), isGap(isGap) {}

void HtmlTagExpression::prettyPrint(){
  if(isClosing)
    std::cout<<"</";
  else if(isGap)
    std::cout<<"<[";
  else
    std::cout<<"<";

  std::cout<<id;

  if(attrs->size() > 0){
    for(auto it = attrs->begin(); it != attrs->end(); ++it){
      std::cout<<" "<<it->first;
      if(it->second.length() > 0){
        std::cout<<"="<<it->second;
      }
    }
  }

  if(isGap)
    std::cout<<"]>";
  else
    std::cout<<">";
}
