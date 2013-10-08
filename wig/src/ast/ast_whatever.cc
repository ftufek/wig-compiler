#include <iostream>
#include "ast_whatever.h"

namespace ast {

Whatever::Whatever(std::string whatever)
  :whatever_(whatever) {}

void Whatever::PrettyPrint(){
  std::cout<<whatever_;
}

}
