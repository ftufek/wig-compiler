#ifndef AST_STRING_H
#define AST_STRING_H

class StringExpression : public Expression {
public:
  StringExpression(std::string content);
  void prettyPrint();

protected:
  std::string content;
};

#endif // AST_STRING_H
