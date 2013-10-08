#include <iostream>
#include "ast_type.h"

TypeExpression::TypeExpression(Type type, std::string tupleID)
    :type(type), tupleID(tupleID) {}

void TypeExpression::prettyPrint() {
    switch(type){
    case Type::INT:
        std::cout<<"int";
        break;

    case Type::BOOL:
        std::cout<<"bool";
        break;

    case Type::STRING:
        std::cout<<"string";
        break;

    case Type::VOID:
        std::cout<<"void";
        break;

    case Type::TUPLE:
        std::cout<<"tuple "<<tupleID;
        break;

    case Type::HTML:
        std::cout<<"html";
        break;
    }
}
