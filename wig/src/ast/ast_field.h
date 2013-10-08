#ifndef AST_FIELD_H
#define AST_FIELD_H

class FieldExpression : public Expression {
public:
  FieldExpression(Type type, std::string id);
  void prettyPrint();

protected:
  Type type;
  std::string id;
};

#endif // AST_FIELD_H
