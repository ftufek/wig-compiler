#include "ast_stm.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

Stm::Stm(){}

EmptyStm::EmptyStm(bool print_semicol):print_semicol_(print_semicol){}
void EmptyStm::accept(class Visitor *v){ v->visit(this); }

CompoundStm::CompoundStm(list<Stm *> *stms, list<Variable *> *vars)
    :vars_(vars), stms_(stms){}
void CompoundStm::accept(class Visitor *v){ v->visit(this); }

}
