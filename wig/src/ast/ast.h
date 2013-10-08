#ifndef AST_H
#define AST_H

#include <string>
#include <map>

/* The Base Interface for all AST classes */
class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void prettyPrint() = 0;

protected:
  int atLine;
};

#endif // AST_H
