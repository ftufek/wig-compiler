#include "../ast.h"

WhateverExpression::WhateverExpression(string whatever)
  :whatever(whatever) {}

void WhateverExpression::prettyPrint(){
  cout<<whatever;
}
