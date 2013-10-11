#include <iostream>
#include "ast_argument.h"
#include "../ast_visitor.h"

namespace ast {

Argument::Argument(Type *type,
                   std::string id)
    :type_(type), id_(id){}
void Argument::accept(class Visitor *v){
    v->visit(this);
}

//void Argument::PrettyPrint(){
//    type_->PrettyPrint();
//    std::cout<<" "<<id_;
//}

}
