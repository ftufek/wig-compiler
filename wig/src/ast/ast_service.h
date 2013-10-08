#ifndef AST_SERVICE_H
#define AST_SERVICE_H

class ServiceExpression : public Expression {
public:
  ServiceExpression(ExpressionList *htmls,
                    ExpressionList *schemas,
                    ExpressionList *globalVariables = new ExpressionList());
  void prettyPrint();

protected:
  ExpressionList *htmls;
  ExpressionList *schemas;
  ExpressionList *globalVariables;
};

#endif // AST_SERVICE_H
