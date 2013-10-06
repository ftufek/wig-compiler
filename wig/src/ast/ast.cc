#include <iostream>
#include "../ast.h"

using namespace std;

Expression::Expression()
  :atLine(yylineno){}

Expression::~Expression(){
}

string typeToStr(Type type){
  return (char *[]){"int","bool","string","void"}[type];
}


