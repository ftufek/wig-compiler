#ifndef AST_SCHEMA_H
#define AST_SCHEMA_H

class SchemaExpression : public Expression {
public:
  SchemaExpression(std::string id,
                   ExpressionList *fields = new ExpressionList());
  void prettyPrint();

protected:
  std::string id;
  ExpressionList *fields;
};

#endif // AST_SCHEMA_H
