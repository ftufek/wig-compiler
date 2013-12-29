#include "empty.h"
#include "../ast.h"

namespace ast{

Empty::Empty (){}

void Empty::accept(class Visitor *v){
    v->visit(this);
}

}
