#include "ast_list.h"

namespace ast {

List::List(std::list<Base *> *exps):exps_(exps){}

void List::PrettyPrint(){
  for(auto const &exp : *exps_){
      exp->PrettyPrint();
  }
}

std::list<Base *> *List::getList(){
  return exps_;
}

}
