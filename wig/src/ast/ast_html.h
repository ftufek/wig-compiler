#ifndef AST_HTML_H
#define AST_HTML_H

#include <string>
#include <map>
#include "ast.h"

class HtmlTagExpression : public Expression {
public:
  HtmlTagExpression(std::string id,
                    std::map<std::string, std::string> *attrs =
                                         new std::map<std::string,std::string>,
                    bool is_closing_ = false,
                    bool is_gap_ = false);
  void PrettyPrint();

protected:
  std::string id;
  std::map<std::string, std::string> *attrs;
  bool is_closing_;
  bool is_gap_;
};

#endif // AST_HTML_H
