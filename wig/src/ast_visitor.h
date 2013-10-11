#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include "ast.h"

namespace ast {

class Visitor
{
public:
    virtual void visit(Base *s) = 0;
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

    virtual void visit(Stm *s) = 0;
    virtual void visit(EmptyStm *s) = 0;
    virtual void visit(CompoundStm *s) = 0;
};


}

#endif // AST_VISITOR_H
