#ifndef __AST_HELPERS_H
#define __AST_HELPERS_H

#include "ast.h"

Expression *wrapAround(std::string name, std::map<std::string, std::string> *attrs,
                       ExpressionList *exp);
Expression *wrapHtml(ExpressionList *exp);
std::map<std::string, std::string> *emptyMap();
std::map<std::string, std::string> *initMap(std::string key, std::string val);
std::map<std::string, std::string> *mergeMap(std::map<std::string, std::string> *m1,
                           std::map<std::string, std::string> *m2);

ExpressionList *initList(Expression *e);
ExpressionList *addBack(ExpressionList *list, Expression *exp);
#endif
