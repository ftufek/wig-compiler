#ifndef AST_LIST_H
#define AST_LIST_H

class ExpressionList : public Expression{
public:
  ExpressionList(std::list<Expression *> *exps = new std::list<Expression *>);
  void prettyPrint();
  std::list<Expression *> *getList();

protected:
  std::list<Expression *> *exps;
};

#endif // AST_LIST_H
