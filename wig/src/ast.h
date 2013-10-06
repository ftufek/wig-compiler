#ifndef __AST_H
#define __AST_H

#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;
extern int lineno;

/* EXPRESSION AST CLASSES */
class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void prettyPrint() = 0;

protected:
  int atLine;
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
                    map<string, string> *attrs = new map<string,string>,
                    bool isClosing = false,
                    bool isGap = false);
  void prettyPrint();

protected:
  string id;
  map<string, string> *attrs;
  bool isClosing;
  bool isGap;
};

class MetaTagExpression : public Expression {
public:
  MetaTagExpression(string content);
  void prettyPrint();

protected:
  string content;
};

class StringExpression : public Expression {
public:
  StringExpression(string content);
  void prettyPrint();

protected:
  string content;
};

class WhateverExpression : public Expression {
public:
  WhateverExpression(string whatever);
  void prettyPrint();
  
protected:
  string whatever;
};

#endif
