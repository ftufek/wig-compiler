#include <iostream>
#include "../ast.h"

using namespace std;

Expression::Expression()
  :atLine(yylineno){}

Expression::~Expression(){
}


