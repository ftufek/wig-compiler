#include "../ast.h"

HtmlTagExpression::HtmlTagExpression
    (string id, bool closing)
    :id(id), closing(closing) {}

void HtmlTagExpression::prettyPrint(){
  if(closing)
    cout<<"</";
  else
    cout<<"<";
  cout<<id<<">";
}
