#ifndef AST_EMPTY_H
#define AST_EMPTY_H

class EmptyExpression : public Expression {
public:
  EmptyExpression();
  void prettyPrint();
};

#endif // AST_EMPTY_H
