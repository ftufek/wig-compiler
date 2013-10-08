#include <iostream>
#include "ast_function.h"

using namespace std;

namespace ast {

Function::Function(Type *type,
                                       std::string id,
                                       std::list<ast::Argument *> *args)
    :type_(type), id_(id), args_(args){}

void Function::PrettyPrint(){
    type_->PrettyPrint();
    cout<<" "<<id_<<"(";
    auto iter = args_->begin();
    if(iter != args_->end()){
        (*iter)->PrettyPrint();
        ++iter;
    }
    for(;iter != args_->end(); ++iter){
        cout<<", ";
        (*iter)->PrettyPrint();
    }
    cout<<") {"<<endl;
    cout<<"}"<<endl;
}

}
