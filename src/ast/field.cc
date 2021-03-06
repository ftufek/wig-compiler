#include "../ast.h"

using namespace std;

namespace ast {

Field::Field(Type *type, string id)
    :type_(type), id_(id){}
Field::~Field(){
	delete(type_);
}

void Field::accept(class Visitor *v){ v->visit(this); }

}
