#ifndef __TREE_H
#define __TREE_H

#include <string>
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
  ServiceExpression();
  void prettyPrint();
};

class VariableExpression : public Expression {
public:
  VariableExpression(string *name);
  void prettyPrint();

protected:
  string *name;
};

#endif
