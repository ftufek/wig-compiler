#include <iostream>
#include "variable.h"
#include "../ast.h"

using namespace std;

namespace ast {

Variable::Variable(string name, Type *type, bool isConst, Base *value):
    name_(name), type_(type), is_const_(isConst), value_(value){}

Variable::~Variable(){
	delete(type_);
	delete(value_);
}

void Variable::accept(class Visitor *v){ v->visit(this); }

}
