#ifndef AST_H
#define AST_H

extern int yylineno;

/* The Base Interface for all AST classes */
class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void prettyPrint() = 0;

protected:
  int at_line_;
};

#endif // AST_H
