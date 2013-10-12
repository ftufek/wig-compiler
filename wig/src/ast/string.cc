#include <iostream>
#include "string.h"
#include "../ast_visitor.h"

namespace ast {

String::String(std::string content)
    :content_(content){}

void String::accept(class Visitor *v){ v->visit(this); }

}
