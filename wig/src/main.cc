#include <iostream>
#include "ast.h"
#include "y.tab.h"

using namespace std;

int yyparse();
Expression *EXP;
bool success = true;
int lineno = 1;

int main(void){
  yyparse();
  if(success){
    EXP->prettyPrint();
  }
}
