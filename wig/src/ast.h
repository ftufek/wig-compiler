#ifndef __TREE_H
#define __TREE_H

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void prettyPrint() = 0;
};

class EmptyExpression : public Expression {
public:
  EmptyExpression();
  void prettyPrint();
};

class ServiceExpression : public Expression {
public:
  ServiceExpression(list<Expression *> *htmls);
  void prettyPrint();

protected:
  list<Expression *> *htmls;
};

class VariableExpression : public Expression {
public:
  VariableExpression(string *name);
  void prettyPrint();

protected:
  string *name;
};

#endif
