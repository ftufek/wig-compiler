#include <iostream>
#include "ast.h"
#include "y.tab.h"

using namespace std;

int yyparse();
Expression *EXP;

int main(void){
  yyparse();
  EXP->pretty();
}
