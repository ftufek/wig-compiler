#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

const bool kConstVar = true;
const bool kNoConstVar = false;
const int kNoVal = 0;

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
