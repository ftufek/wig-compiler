#ifndef AST_TYPE_H
#define AST_TYPE_H

#include "ast.h"

enum Type{
  INT, BOOL, STRING, VOID, TUPLE, HTML
};

class TypeExpression : public Expression
{
public:
    TypeExpression(Type type, std::string tupleID = "");
    void prettyPrint();
protected:
    Type type;
    std::string tupleID;
};

#endif // AST_TYPE_H
