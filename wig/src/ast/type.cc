#include <iostream>
#include "type.h"
#include "../ast_visitor.h"

namespace ast {

Type::Type(kType type, std::string tupleID)
    :type_(type), tuple_id_(tupleID) {}

void Type::accept(class Visitor *v){ v->visit(this); }

}
