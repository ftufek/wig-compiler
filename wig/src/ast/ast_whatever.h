#ifndef AST_WHATEVER_H
#define AST_WHATEVER_H

#include <string>
#include "ast.h"

class WhateverExpression : public Expression {
public:
  WhateverExpression(std::string whatever_);
  void PrettyPrint();

protected:
  std::string whatever_;
};

#endif // AST_WHATEVER_H
