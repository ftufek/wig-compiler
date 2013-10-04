#include <iostream>
#include "tree.h"
#include "y.tab.h"

int yyparse();

Expression *EXP;

int main(void){
  yyparse();
  EXP->pretty();
}
