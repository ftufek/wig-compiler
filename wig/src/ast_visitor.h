#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "ast.h"

namespace ast {

class Visitor
{
public:
	virtual ~Visitor(){};

    virtual void visit(Service *s) = 0;
    virtual void visit(Whatever *s) = 0;
    virtual void visit(Variable *s) = 0;
    virtual void visit(Function *s) = 0;
    virtual void visit(Field *s) = 0;
    virtual void visit(Empty *s) = 0;
    virtual void visit(HtmlTag *s) = 0;
    virtual void visit(Argument *s) = 0;
    virtual void visit(MetaTag *s) = 0;
    virtual void visit(Schema *s) = 0;
    virtual void visit(String *s) = 0;
    virtual void visit(List *s) = 0;
    virtual void visit(Type *s) = 0;
    virtual void visit(Session *s) = 0;

    virtual void visit(EmptyStm *s) = 0;
    virtual void visit(CompoundStm *s) = 0;
    virtual void visit(ShowStm *s) = 0;
    virtual void visit(DocumentStm *s) = 0;
    virtual void visit(PlugStm *s) = 0;
    virtual void visit(InputStm *s) = 0;
    virtual void visit(ReceiveStm *s) = 0;
    virtual void visit(ExitStm *s) = 0;
    virtual void visit(ReturnStm *s) = 0;
    virtual void visit(IfStm *s) = 0;
    virtual void visit(WhileStm *s) = 0;
    virtual void visit(ExpStm *s) = 0;

    virtual void visit(Exp *s) = 0;
    virtual void visit(LValExp *s) = 0;
    virtual void visit(BinopExp *s) = 0;
    virtual void visit(UnopExp *s) = 0;
    virtual void visit(TupleopExp *s) = 0;
    virtual void visit(FunctionExp *s) = 0;
    virtual void visit(IntegerExp *s) = 0;
    virtual void visit(TrueExp *s) = 0;
    virtual void visit(FalseExp *s) = 0;
    virtual void visit(StringExp *s) = 0;
    virtual void visit(FieldValExp *s) = 0;
    virtual void visit(TupleExp *s) = 0;
};


class VisitorOptional : public Visitor
{
public:
	~VisitorOptional(){};

    void visit(Service *s) {};
    void visit(Whatever *s) {};
    void visit(Variable *s) {};
    void visit(Function *s) {};
    void visit(Field *s) {};
    void visit(Empty *s) {};
    void visit(HtmlTag *s) {};
    void visit(Argument *s) {};
    void visit(MetaTag *s) {};
    void visit(Schema *s) {};
    void visit(String *s) {};
    void visit(List *s) {};
    void visit(Type *s) {};
    void visit(Session *s) {};

    void visit(EmptyStm *s) {};
    void visit(CompoundStm *s) {};
    void visit(ShowStm *s) {};
    void visit(DocumentStm *s) {};
    void visit(PlugStm *s) {};
    void visit(InputStm *s) {};
    void visit(ReceiveStm *s) {};
    void visit(ExitStm *s) {};
    void visit(ReturnStm *s) {};
    void visit(IfStm *s) {};
    void visit(WhileStm *s) {};
    void visit(ExpStm *s) {};

    void visit(Exp *s) {};
    void visit(LValExp *s) {};
    void visit(BinopExp *s) {};
    void visit(UnopExp *s) {};
    void visit(TupleopExp *s) {};
    void visit(FunctionExp *s) {};
    void visit(IntegerExp *s) {};
    void visit(TrueExp *s) {};
    void visit(FalseExp *s) {};
    void visit(StringExp *s) {};
    void visit(FieldValExp *s) {};
    void visit(TupleExp *s) {};
};

class MultipleVisitors : public VisitorOptional
{
public:
	MultipleVisitors(std::list<Visitor *> *visitors = new std::list<Visitor *>)
		:visitors_(visitors){};
	virtual ~MultipleVisitors() {};

	void visit(Service *service);

private:
	std::list<Visitor *> *visitors_;
};

}

#endif // AST_VISITOR_H
