#include <iostream>
#include "ast_whatever.h"
#include "../ast_visitor.h"

namespace ast {

Whatever::Whatever(std::string whatever) :whatever_(whatever) {}
void Whatever::accept(class Visitor *v){
    v->visit(this);
}

}
