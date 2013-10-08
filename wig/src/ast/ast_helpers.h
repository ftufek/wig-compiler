#ifndef AST_HELPERS_H
#define AST_HELPERS_H

#include <string>
#include <map>
#include "ast.h"
#include "ast_list.h"
#include "ast_html.h"

namespace ast{

Base *wrapAround(std::string name,
                 std::map<std::string, std::string> *attrs,
                 List *exp);
Base *wrapHtml(List *exp);
std::map<std::string, std::string> *emptyMap();
std::map<std::string, std::string> *initMap(std::string key, std::string val);
std::map<std::string, std::string> *mergeMap(
        std::map<std::string, std::string> *m1,
        std::map<std::string, std::string> *m2);

List *initList(Base *e);
List *addBack(List *list, Base *exp);

}

#endif // AST_HELPERS_H
