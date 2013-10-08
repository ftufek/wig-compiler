#include <iostream>
#include "ast_type.h"

TypeExpression::TypeExpression(Type type, std::string tupleID)
    :type_(type), tuple_id_(tupleID) {}

void TypeExpression::PrettyPrint() {
    switch(type_){
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
        std::cout<<"tuple "<<tuple_id_;
        break;

    case Type::HTML:
        std::cout<<"html";
        break;
    }
}
