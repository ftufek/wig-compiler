#include "list.h"
#include "../ast.h"

namespace ast {

List::List(std::list<Base *> *exps):exps_(exps){}
List::~List(){
	//TODO: for some reason the following lines
	//cause a Segmentation fault, fix when have time!
//	while(!exps_->empty()){
//		delete (exps_->front());
//		exps_->pop_front();
//	}
	delete(exps_);
}

void List::accept(class Visitor *v){ v->visit(this); }

std::list<Base *> *List::getList(){
    return exps_;
}

}
