#ifndef __AST_HELPERS_H
#define __AST_HELPERS_H

#include "ast.h"

Expression *wrapAround(string name, map<string, string> *attrs,
                       ExpressionList *exp);
Expression *wrapHtml(ExpressionList *exp);
map<string, string> *emptyMap();
map<string, string> *initMap(string key, string val);
map<string, string> *mergeMap(map<string, string> *m1,
                           map<string, string> *m2);

#endif
