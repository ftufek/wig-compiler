#include <iostream>
#include "ast.h"
#include "pretty_printer.h"
#include "y.tab.h"

int yyparse();
ast::Service *EXP;
bool success = true;
extern int yylineno;

int main(void){
    yyparse();
    if(success){
        pp::PrettyPrintVisitor *pp = new pp::PrettyPrintVisitor();
        pp->visit(EXP);
    }
}
