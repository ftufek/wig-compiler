#include <iostream>
#include "schema.h"
#include "../ast.h"

namespace ast {

Schema::Schema(std::string id, List *fields)
    :id_(id), fields_(fields){}

Schema::~Schema(){
	delete(fields_);
}

void Schema::accept(class Visitor *v){ v->visit(this); }

}
