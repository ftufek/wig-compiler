#include "session.h"
#include "../ast_visitor.h"

namespace ast {

Session::Session(std::string id, CompoundStm *stm):id_(id), stm_(stm){}
void Session::accept(Visitor *v) { v->visit(this); }

}
