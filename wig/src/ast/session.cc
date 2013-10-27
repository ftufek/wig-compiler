#include "session.h"
#include "../ast.h"

namespace ast {

Session::Session(std::string id, CompoundStm *stm):id_(id), stm_(stm){}
Session::~Session(){
	delete(stm_);
}
void Session::accept(Visitor *v) { v->visit(this); }

}
