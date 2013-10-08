#include <iostream>
#include "ast_argument.h"

namespace ast {

Argument::Argument(Type *type,
                                       std::string id)
    :type_(type), id_(id){}

void Argument::PrettyPrint(){
    type_->PrettyPrint();
    std::cout<<" "<<id_;
}

}
