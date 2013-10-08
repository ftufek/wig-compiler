#ifndef AST_FIELD_H
#define AST_FIELD_H

#include "ast_type.h"

class FieldExpression : public Expression {
public:
  FieldExpression(TypeExpression *type, std::string id);
  void prettyPrint();

protected:
  TypeExpression *type;
  std::string id;
};

#endif // AST_FIELD_H
