#ifndef AST_HTML_H
#define AST_HTML_H

#include <string>
#include <map>
#include "ast.h"

class HtmlTagExpression : public Expression {
public:
  HtmlTagExpression(std::string id,
                    std::map<std::string, std::string> *attrs = new std::map<std::string,std::string>,
                    bool isClosing = false,
                    bool isGap = false);
  void prettyPrint();

protected:
  std::string id;
  std::map<std::string, std::string> *attrs;
  bool isClosing;
  bool isGap;
};

#endif // AST_HTML_H
