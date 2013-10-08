#ifndef AST_STRING_H
#define AST_STRING_H

#include <string>
#include "ast.h"

class StringExpression : public Expression {
public:
  StringExpression(std::string content_);
  void PrettyPrint();

protected:
  std::string content_;
};

#endif // AST_STRING_H
