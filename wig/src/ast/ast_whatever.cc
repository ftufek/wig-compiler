#include <iostream>
#include "ast_whatever.h"

WhateverExpression::WhateverExpression(std::string whatever)
  :whatever_(whatever) {}

void WhateverExpression::PrettyPrint(){
  std::cout<<whatever_;
}
