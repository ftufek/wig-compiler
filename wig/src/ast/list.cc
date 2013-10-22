#include "list.h"
#include "../ast_visitor.h"

namespace ast {

List::List(std::list<Base *> *exps):exps_(exps){}
List::~List(){
	for(auto it : *exps_){
		delete(it);
	}
	delete(exps_);
}

void List::accept(class Visitor *v){ v->visit(this); }

std::list<Base *> *List::getList(){
    return exps_;
}

}
