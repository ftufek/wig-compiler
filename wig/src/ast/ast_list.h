#ifndef AST_LIST_H
#define AST_LIST_H

#include <list>
#include "ast.h"

class ExpressionList : public Expression{
public:
  ExpressionList(std::list<Expression *> *exps_ = new std::list<Expression *>);
  void PrettyPrint();
  std::list<Expression *> *getList();

protected:
  std::list<Expression *> *exps_;
};

#endif // AST_LIST_H
