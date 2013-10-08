#include <iostream>
#include "ast_function.h"

using namespace std;

FunctionExpression::FunctionExpression(TypeExpression *type,
                                       std::string id,
                                       std::list<ArgumentExpression *> *args)
    :type_(type), id_(id), args_(args){}

void FunctionExpression::PrettyPrint(){
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
