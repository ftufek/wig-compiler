#include <iostream>
#include "ast_function.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

Function::Function(Type *type,
                   std::string id,
                   std::list<Argument *> *args,
                   CompoundStm *stm)
    :type_(type), id_(id), args_(args), stm_(stm){}
void Function::accept(class Visitor *v){
    v->visit(this);
}

//void Function::PrettyPrint(){
//    type_->PrettyPrint();
//    cout<<" "<<id_<<"(";
//    auto iter = args_->begin();
//    if(iter != args_->end()){
//        (*iter)->PrettyPrint();
//        ++iter;
//    }
//    for(;iter != args_->end(); ++iter){
//        cout<<", ";
//        (*iter)->PrettyPrint();
//    }
//    cout<<")";
//    stm_->PrettyPrint();
//    cout<<endl;
//}

}
