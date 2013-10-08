#include <iostream>
#include "ast.h"
#include "y.tab.h"

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
