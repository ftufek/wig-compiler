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

  if(attrs->size() > 0){
    for(map<string,string>::const_iterator it = attrs->begin();
        it != attrs->end(); ++it){
      cout<<" "<<it->first;
      if(it->second.length() > 0){
        cout<<"="<<it->second;
      }
    }
  }

  if(isGap)
    cout<<"]>";
  else
    cout<<">";
}
