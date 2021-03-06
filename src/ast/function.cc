#include <iostream>
#include "function.h"
#include "../ast.h"

using namespace std;

namespace ast {

Function::Function(Type *type,
                   std::string id,
                   std::list<Argument *> *args,
                   CompoundStm *stm)
    :type_(type), id_(id), args_(args), stm_(stm){}
Function::~Function(){
	delete(type_);
	for(auto it:*args_){
		delete(it);
	}
	delete(args_);
	delete(stm_);
}

void Function::accept(class Visitor *v){ v->visit(this); }

}
