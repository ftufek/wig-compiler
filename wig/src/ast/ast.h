#ifndef AST_H
#define AST_H

#include <string>

enum Type{
  INT, BOOL, STRING, VOID
};

std::string typeToStr(Type type);

/* EXPRESSION AST CLASSES */
class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void prettyPrint() = 0;

protected:
  int atLine;
};

#endif // AST_H
