#include "list.h"
#include "../ast.h"

namespace ast {

List::List(Base *e){
	exps_ = new std::list<Base *>;
    getList()->push_front(e);
}

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


void List::AddBack(Base *exp){
    getList()->push_back(exp);
}

std::list<Base *> *List::getList(){
    return exps_;
}

}
