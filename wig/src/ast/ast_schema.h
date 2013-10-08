#ifndef AST_SCHEMA_H
#define AST_SCHEMA_H

#include <string>
#include "ast.h"
#include "ast_list.h"

class SchemaExpression : public Expression {
public:
  SchemaExpression(std::string id_,
                   ExpressionList *fields_ = new ExpressionList());
  void PrettyPrint() override;

protected:
  std::string id_;
  ExpressionList *fields_;
};

#endif // AST_SCHEMA_H
