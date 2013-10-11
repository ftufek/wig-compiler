#include <iostream>
#include "ast_variable.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

Variable::Variable(string name, Type *type, bool isConst, Base *value):
    name_(name), type_(type), is_const_(isConst), value_(value){}

void Variable::accept(class Visitor *v){ v->visit(this); }

}
