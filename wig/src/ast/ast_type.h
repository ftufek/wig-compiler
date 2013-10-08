#ifndef AST_TYPE_H
#define AST_TYPE_H

#include "ast.h"

enum Type{
  INT, BOOL, STRING, VOID, TUPLE, HTML
};

class TypeExpression : public Expression
{
public:
    TypeExpression(Type type, std::string tupleID = "")
        :type(type), tupleID(tupleID) {}
    void prettyPrint() {
        switch(type){
        case INT:
            std::cout<<"int";
            break;

        case BOOL:
            std::cout<<"bool";
            break;

        case STRING:
            std::cout<<"string";
            break;

        case VOID:
            std::cout<<"void";
            break;

        case TUPLE:
            std::cout<<"tuple "<<tupleID;
            break;

        case HTML:
            std::cout<<"html";
            break;
        }
    }
protected:
    Type type;
    std::string tupleID;
};

#endif // AST_TYPE_H
