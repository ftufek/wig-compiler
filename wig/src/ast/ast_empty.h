#ifndef AST_EMPTY_H
#define AST_EMPTY_H

#include "ast.h"

class EmptyExpression : public Expression {
public:
  EmptyExpression();
  void PrettyPrint();
};

#endif // AST_EMPTY_H
