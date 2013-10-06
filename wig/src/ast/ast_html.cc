#include "../ast.h"

HtmlTagExpression::HtmlTagExpression
    (string id, map<string, string> *attrs, bool isClosing, bool isGap)
    :id(id), attrs(attrs), isClosing(isClosing), isGap(isGap) {}

void HtmlTagExpression::prettyPrint(){
  if(isClosing)
    cout<<"</";
  else if(isGap)
    cout<<"<[";
  else
    cout<<"<";

  cout<<id;

  if(isGap)
    cout<<"]>";
  else
    cout<<">";
}
