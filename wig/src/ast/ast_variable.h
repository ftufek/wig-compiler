#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

#include <cstddef>

const bool kConstVar = true;
const bool kNoConstVar = false;
const std::nullptr_t kNoVal = nullptr;

class VariableExpression : public Expression {
public:
  VariableExpression(std::string name,
                     TypeExpression *type,
                     bool isConst,
                     Expression *value);
  void prettyPrint();

protected:
  std::string name;
  TypeExpression *type;
  bool isConst;
  Expression *value;
};

#endif // AST_VARIABLE_H
