#ifndef __AST_H
#define __AST_H

#include <string>
#include <list>
#include <iostream>
using namespace std;


/* EXPRESSION AST CLASSES */
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

class ExpressionList : public Expression{
public:
  ExpressionList(list<Expression *> *exps = new list<Expression *>);
  void prettyPrint();
  list<Expression *> *getList();

protected:
  list<Expression *> *exps;
};


class ServiceExpression : public Expression {
public:
  ServiceExpression(ExpressionList *htmls);
  void prettyPrint();

protected:
  ExpressionList *htmls;
};

class VariableExpression : public Expression {
public:
  VariableExpression(string name, 
                     string type,
                     bool isConst,
                     Expression *value);
  void prettyPrint();

protected:
  string name;
  string type;
  bool isConst;
  Expression *value;
};

class HtmlTagExpression : public Expression {
public:
  HtmlTagExpression(string id,
                    bool closing = false);
  void prettyPrint();

protected:
  string id;
  bool closing;
};

#endif
