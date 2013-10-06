#include "../ast.h"

Expression *wrapHtml(ExpressionList *exp){
  Expression *opening = new HtmlTagExpression("html");
  Expression *closing = new HtmlTagExpression("html", true);

  exp->getList()->push_front(opening);
  exp->getList()->push_back(closing);
  return exp;
}
