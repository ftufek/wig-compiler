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
	virtual ~VisitorOptional(){};

    virtual void visit(Service *s) {};
    virtual void visit(Whatever *s) {};
    virtual void visit(Variable *s) {};
    virtual void visit(Function *s) {};
    virtual void visit(Field *s) {};
    virtual void visit(Empty *s) {};
    virtual void visit(HtmlTag *s) {};
    virtual void visit(Argument *s) {};
    virtual void visit(MetaTag *s) {};
    virtual void visit(Schema *s) {};
    virtual void visit(String *s) {};
    virtual void visit(List *s) {};
    virtual void visit(Type *s) {};
    virtual void visit(Session *s) {};

    virtual void visit(EmptyStm *s) {};
    virtual void visit(CompoundStm *s) {};
    virtual void visit(ShowStm *s) {};
    virtual void visit(DocumentStm *s) {};
    virtual void visit(PlugStm *s) {};
    virtual void visit(InputStm *s) {};
    virtual void visit(ReceiveStm *s) {};
    virtual void visit(ExitStm *s) {};
    virtual void visit(ReturnStm *s) {};
    virtual void visit(IfStm *s) {};
    virtual void visit(WhileStm *s) {};
    virtual void visit(ExpStm *s) {};

    virtual void visit(Exp *s) {};
    virtual void visit(LValExp *s) {};
    virtual void visit(BinopExp *s) {};
    virtual void visit(UnopExp *s) {};
    virtual void visit(TupleopExp *s) {};
    virtual void visit(FunctionExp *s) {};
    virtual void visit(IntegerExp *s) {};
    virtual void visit(TrueExp *s) {};
    virtual void visit(FalseExp *s) {};
    virtual void visit(StringExp *s) {};
    virtual void visit(FieldValExp *s) {};
    virtual void visit(TupleExp *s) {};
};

class MultipleVisitors : public VisitorOptional
{
public:
	MultipleVisitors(std::list<Visitor *> *visitors = new std::list<Visitor *>)
		:visitors_(visitors){};
	virtual ~MultipleVisitors();

	void visit(Service *service);

private:
	std::list<Visitor *> *visitors_;
};

}

#endif // AST_VISITOR_H
