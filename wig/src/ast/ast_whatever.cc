#include "../ast.h"

WhateverExpression::WhateverExpression(std::string whatever)
  :whatever(whatever) {}

void WhateverExpression::prettyPrint(){
  std::cout<<whatever;
}
