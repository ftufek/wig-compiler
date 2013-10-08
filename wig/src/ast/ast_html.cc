#include <iostream>
#include "ast_html.h"

using namespace std;

namespace ast {

HtmlTag::HtmlTag
    (string id, map<string, string> *attrs, bool isClosing, bool isGap)
    :id(id), attrs(attrs), is_closing_(isClosing), is_gap_(isGap) {}

void HtmlTag::PrettyPrint(){
  if(is_closing_)
    std::cout<<"</";
  else if(is_gap_)
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

  if(is_gap_)
    std::cout<<"]>";
  else
    std::cout<<">";
}

}
