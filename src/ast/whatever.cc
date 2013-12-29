#include <iostream>
#include "whatever.h"
#include "../ast.h"

namespace ast {

Whatever::Whatever(std::string whatever) :whatever_(whatever) {}
void Whatever::accept(class Visitor *v){
    v->visit(this);
}

}
