#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

class VariableExpression : public Expression {
public:
  VariableExpression(std::string name,
                     std::string type,
                     bool isConst,
                     Expression *value);
  void prettyPrint();

protected:
  std::string name;
  std::string type;
  bool isConst;
  Expression *value;
};

#endif // AST_VARIABLE_H
