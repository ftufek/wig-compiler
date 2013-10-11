#include <iostream>
#include "ast_type.h"
#include "../ast_visitor.h"

namespace ast {

Type::Type(kType type, std::string tupleID)
    :type_(type), tuple_id_(tupleID) {}

void Type::accept(class Visitor *v){
    v->visit(this);
}

//void Type::PrettyPrint() {
//    switch(type_){
//    case kType::INT:
//        std::cout<<"int";
//        break;

//    case kType::BOOL:
//        std::cout<<"bool";
//        break;

//    case kType::STRING:
//        std::cout<<"string";
//        break;

//    case kType::VOID:
//        std::cout<<"void";
//        break;

//    case kType::TUPLE:
//        std::cout<<"tuple "<<tuple_id_;
//        break;

//    case kType::HTML:
//        std::cout<<"html";
//        break;
//    }
//}

}
