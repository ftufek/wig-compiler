#include "../ast.h"

HtmlTagExpression::HtmlTagExpression
    (string id, bool isClosing, bool isGap)
    :id(id), isClosing(isClosing), isGap(isGap) {}

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
