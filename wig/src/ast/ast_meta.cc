#include "../ast.h"

MetaTagExpression::MetaTagExpression(string content)
  :content(content){}

void MetaTagExpression::prettyPrint(){
  cout<<"<!-- ";
  cout<<content;
  cout<<" -->";
}
