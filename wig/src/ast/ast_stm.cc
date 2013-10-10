#include "ast_stm.h"

using namespace std;

namespace ast {

Stm::Stm(){}

EmptyStm::EmptyStm(bool print_semicol):print_semicol_(print_semicol){}
void EmptyStm::PrettyPrint(){
    if(print_semicol_){
        cout<<";"<<endl;
    }
}

CompoundStm::CompoundStm(list<Stm *> *stms, list<Variable *> *vars)
    :vars_(vars), stms_(stms){}
void CompoundStm::PrettyPrint(){
    cout<<" { "<<endl;
    for(auto const &var : *vars_){
        var->PrettyPrint();
    }
    for(auto const &stm : *stms_){
        stm->PrettyPrint();
    }
    cout<<"}";
}

}
