#ifndef AST_WHATEVER_H
#define AST_WHATEVER_H

class WhateverExpression : public Expression {
public:
  WhateverExpression(std::string whatever);
  void prettyPrint();

protected:
  std::string whatever;
};

#endif // AST_WHATEVER_H
