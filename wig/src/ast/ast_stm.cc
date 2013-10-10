#include "ast_stm.h"

using namespace std;

namespace ast {

Stm::Stm(){}

EmptyStm::EmptyStm(){}
void EmptyStm::PrettyPrint(){
    cout<<";"<<endl;
}

CompoundStm::CompoundStm(list<Variable *> *vars, list<Stm *> *stms)
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
