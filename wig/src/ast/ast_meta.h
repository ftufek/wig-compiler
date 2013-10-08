#ifndef AST_META_H
#define AST_META_H

class MetaTagExpression : public Expression {
public:
  MetaTagExpression(std::string content);
  void prettyPrint();

protected:
  std::string content;
};

#endif // AST_META_H
