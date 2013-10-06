#include "../ast_helpers.h"

Expression *wrapHtml(ExpressionList *exp){
  Expression *opening = new HtmlTagExpression("html");
  Expression *closing = new HtmlTagExpression("html", emptyMap(), true);

  exp->getList()->push_front(opening);
  exp->getList()->push_back(closing);
  return exp;
}

map<string, string> *emptyMap(){
  return new map<string, string>;
}
