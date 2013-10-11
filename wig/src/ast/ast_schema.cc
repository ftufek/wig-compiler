#include <iostream>
#include "ast_schema.h"
#include "../ast_visitor.h"

namespace ast {

Schema::Schema(std::string id, List *fields)
    :id_(id), fields_(fields){}
void Schema::accept(class Visitor *v){
    v->visit(this);
}

//void Schema::PrettyPrint(){
//    std::cout<<"schema "<<id_<<" {"<<std::endl;
//    fields_->PrettyPrint();
//    std::cout<<"}"<<std::endl;
//}

}
