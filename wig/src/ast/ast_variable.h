#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

#include <cstddef>
#include <string>
#include "ast.h"
#include "ast_type.h"

const bool kConstVar = true;
const bool kNoConstVar = false;
const std::nullptr_t kNoVal = nullptr;

class VariableExpression : public Expression {
public:
  VariableExpression(std::string name_,
                     TypeExpression *type_,
                     bool is_const_,
                     Expression *value_);
  void PrettyPrint() override;

protected:
  std::string name_;
  TypeExpression *type_;
  bool is_const_;
  Expression *value_;
};

#endif // AST_VARIABLE_H
