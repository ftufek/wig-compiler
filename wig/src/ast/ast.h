#ifndef AST_H
#define AST_H

extern int yylineno;

namespace ast {

/* The Base Interface for all AST classes */
class Base{
public:
    Base();
    virtual ~Base();
    virtual void PrettyPrint() = 0;

protected:
    int at_line_;
};

}



#endif // AST_H
