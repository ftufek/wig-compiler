#include "ast_empty.h"
#include "../ast_visitor.h"

namespace ast{

Empty::Empty (){}

void Empty::accept(class Visitor *v){
    v->visit(this);
}

}
