#include "ast.h"
#include "../ast_visitor.h"

namespace ast{

Base::Base() :at_line_(yylineno){}
Base::~Base(){}

void Base::accept(class Visitor *v){
    v->visit(this);
}

}
