#ifndef AST_H
#define AST_H

extern int yylineno;

namespace st{
class Table;
}

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
    virtual ~Base();
    int at_line(){return at_line_;};
    virtual void accept(Visitor *v){};
    const st::Table* get_sym_table() const;
    void set_sym_table(st::Table *table);
protected:
    int at_line_;
    st::Table *sym_table_;
};

}

#endif // AST_H
