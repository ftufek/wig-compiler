#include <iostream>
#include "ast_argument.h"

ArgumentExpression::ArgumentExpression(TypeExpression *type,
                                       std::string id)
    :type_(type), id_(id){}

void ArgumentExpression::PrettyPrint(){
    type_->PrettyPrint();
    std::cout<<" "<<id_;
}
