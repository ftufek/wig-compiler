#include "ast_stm.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

Stm::Stm(){}
void Stm::accept(class Visitor *v){
    v->visit(this);
}

EmptyStm::EmptyStm(bool print_semicol):print_semicol_(print_semicol){}
void EmptyStm::accept(class Visitor *v){
    v->visit(this);
}
//void EmptyStm::PrettyPrint(){
//    if(print_semicol_){
//        cout<<";"<<endl;
//    }
//}

CompoundStm::CompoundStm(list<Stm *> *stms, list<Variable *> *vars)
    :vars_(vars), stms_(stms){}
void CompoundStm::accept(class Visitor *v){
    v->visit(this);
}
//void CompoundStm::PrettyPrint(){
//    cout<<" { "<<endl;
//    for(auto const &var : *vars_){
//        var->PrettyPrint();
//    }
//    for(auto const &stm : *stms_){
//        stm->PrettyPrint();
//    }
//    cout<<"}";
//}

}
