#include "../ast_helpers.h"

Expression *wrapAround(string name, map<string, string> *attrs,
                       ExpressionList *exp){
  Expression *opening = new HtmlTagExpression(name, attrs);
  Expression *closing = new HtmlTagExpression(name, 
                                              emptyMap(),
                                              true);
  exp->getList()->push_front(opening);
  exp->getList()->push_back(closing);
  return exp;
}


Expression *wrapHtml(ExpressionList *exp){
  return wrapAround("html", emptyMap(), exp);
}

map<string, string> *emptyMap(){
  return new map<string, string>;
}

map<string, string> *initMap(string key, string val){
  map<string, string> *a = emptyMap();
  a->insert(pair<string, string>(key, val));
  return a;
}

map<string, string> *mergeMap(map<string, string> *m1,
                           map<string, string> *m2){
  m1->insert(m2->begin(), m2->end());
  return m1;
}

ExpressionList *initList(Expression *e){
  ExpressionList *l = new ExpressionList();
  l->getList()->push_front(e);
  return l;
}

ExpressionList *addBack(ExpressionList *list, Expression *exp){
  list->getList()->push_back(exp);
  return list;
}
