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


PlugStm::PlugStm(std::string id, Exp *exp):id_(id), exp_(exp){}
void PlugStm::accept(Visitor *v) { v->visit(this); }


InputStm::InputStm(string lvalue, string id):lvalue_(lvalue),id_(id){}
void InputStm::accept(Visitor *v) { v->visit(this); }


ShowStm::ShowStm(DocumentStm *doc, Stm *receive):doc_(doc),receive_(receive){}
void ShowStm::accept(Visitor *v) { v->visit(this); }


DocumentStm::DocumentStm(std::string id_,
                         bool pluggable_,
                         std::list<PlugStm *> *plugs_)
    :id_(id_), pluggable_(pluggable_), plugs_(plugs_){}
void DocumentStm::accept(Visitor *v) { v->visit(this); }


ReceiveStm::ReceiveStm(std::list<Stm *> *inputs):inputs_(inputs){}
void ReceiveStm::accept(Visitor *v) { v->visit(this); }

}
