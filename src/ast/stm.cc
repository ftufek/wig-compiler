#include "stm.h"
#include "../ast.h"

using namespace std;

namespace ast {

Stm::Stm(){}


EmptyStm::EmptyStm(bool print_semicol):print_semicol_(print_semicol){}
void EmptyStm::accept(class Visitor *v){ v->visit(this); }


CompoundStm::CompoundStm(list<Stm *> *stms, list<Base *> *vars)
    :vars_(vars), stms_(stms){}
CompoundStm::~CompoundStm(){
	for(auto it : *stms_){
		delete(it);
	}
	delete(stms_);

	for(auto it : *vars_){
		delete(it);
	}
	delete(vars_);
}
void CompoundStm::accept(class Visitor *v){ v->visit(this); }


PlugStm::PlugStm(std::string id, Exp *exp):id_(id), exp_(exp){}
PlugStm::~PlugStm(){
	delete(exp_);
}
void PlugStm::accept(Visitor *v) { v->visit(this); }


InputStm::InputStm(string lvalue, string id):lvalue_(lvalue),id_(id){}
void InputStm::accept(Visitor *v) { v->visit(this); }


ShowStm::ShowStm(DocumentStm *doc, Stm *receive):doc_(doc),receive_(receive){}
ShowStm::~ShowStm(){
	delete(doc_);
	delete(receive_);
}
void ShowStm::accept(Visitor *v) { v->visit(this); }


ExitStm::ExitStm(DocumentStm *doc):doc_(doc){}
ExitStm::~ExitStm(){
	delete(doc_);
}
void ExitStm::accept(Visitor *v) { v->visit(this); }


DocumentStm::DocumentStm(std::string id_,
                         bool pluggable_,
                         std::list<PlugStm *> *plugs_)
    :id_(id_), pluggable_(pluggable_), plugs_(plugs_){}
DocumentStm::~DocumentStm(){
	for(auto it : *plugs_){
		delete(it);
	}
	delete(plugs_);
}
void DocumentStm::accept(Visitor *v) { v->visit(this); }


ReceiveStm::ReceiveStm(std::list<Stm *> *inputs):inputs_(inputs){}
ReceiveStm::~ReceiveStm(){
	for(auto it : *inputs_){delete(it);}
	delete(inputs_);
}
void ReceiveStm::accept(Visitor *v) { v->visit(this); }


ReturnStm::ReturnStm(Exp *exp):exp_(exp){}
ReturnStm::~ReturnStm(){
	delete(exp_);
}
void ReturnStm::accept(Visitor *v) { v->visit(this); }


IfStm::IfStm(Exp *condition, Stm *true_stm, Stm *else_stm)
    :condition_(condition), true_stm_(true_stm), else_stm_(else_stm){}
IfStm::~IfStm(){
	delete(condition_);
	delete(true_stm_);
	delete(else_stm_);
}
void IfStm::accept(Visitor *v) { v->visit(this); }


WhileStm::WhileStm(Exp *condition, Stm *stm)
    :condition_(condition), stm_(stm){}
WhileStm::~WhileStm(){
	delete(condition_);
	delete(stm_);
}
void WhileStm::accept(Visitor *v) {v->visit(this);}


ExpStm::ExpStm(Exp *exp) : exp_(exp) {}
ExpStm::~ExpStm(){
	delete(exp_);
}
void ExpStm::accept(Visitor *v) { v->visit(this); }
}
