#include <iostream>
#include "ast.h"
#include "y.tab.h"

using namespace std;

int yyparse();
ast::Base *EXP;
bool success = true;
extern int yylineno;

int main(void){
  yyparse();
  if(success){
    EXP->PrettyPrint();
  }
}
