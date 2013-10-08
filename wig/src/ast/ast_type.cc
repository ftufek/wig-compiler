#include <iostream>
#include "ast_type.h"

TypeExpression::TypeExpression(Type type, std::string tupleID)
    :type(type), tupleID(tupleID) {}

void TypeExpression::prettyPrint() {
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
