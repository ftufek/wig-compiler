#include <iostream>
#include "argument.h"
#include "../ast_visitor.h"

namespace ast {

Argument::Argument(Type *type,
                   std::string id)
    :type_(type), id_(id){}

Argument::~Argument(){
	delete(type_);
}

void Argument::accept(class Visitor *v){ v->visit(this); }

}
