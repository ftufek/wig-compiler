#ifndef AST_SERVICE_H
#define AST_SERVICE_H

class ServiceExpression : public Expression {
public:
  ServiceExpression(ExpressionList *htmls,
                    ExpressionList *schemas);
  void prettyPrint();

protected:
  ExpressionList *htmls;
  ExpressionList *schemas;
};

#endif // AST_SERVICE_H
