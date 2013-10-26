#ifndef AST_H
#define AST_H

extern int yylineno;

namespace ast {

class Visitor;
class Visitable
{
public:
	virtual ~Visitable(){};
    virtual void accept(Visitor *v) = 0;
};

/* The Base Class (Interface) for all AST classes */
class Base : public Visitable{
public:
    Base();
    virtual ~Base() {};

    int at_line(){return at_line_;}

protected:
    int at_line_;
};



}



#endif // AST_H
