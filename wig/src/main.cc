#include <iostream>
#include <stdio.h>
#include <boost/program_options.hpp>
#include "ast.h"
#include "pretty_printer.h"
#include "y.tab.h"

int yyparse();
ast::Service *EXP;
bool success = true;

using namespace std;

int main(void){
    yyparse();
    if(success){
        pp::PrettyPrintVisitor *pp = new pp::PrettyPrintVisitor();
        pp->visit(EXP);
    }
}
