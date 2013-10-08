#ifndef AST_FIELD_H
#define AST_FIELD_H

#include <string>
#include "ast.h"
#include "ast_type.h"

class FieldExpression : public Expression {
public:
  FieldExpression(TypeExpression *type, std::string id);
  void PrettyPrint() override;

protected:
  TypeExpression *type;
  std::string id;
};

#endif // AST_FIELD_H
