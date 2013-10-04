%{
#include <iostream>
#include "tree.h"

extern "C" int yylex();
extern Expression *EXP;

void yyerror(const char* str){
  std::cout<<"Error happened!\n";
}
%}

%union{
  Expression *exp;
}

%token tSERVICE

%type <exp> service exp
%start service

%%

service: exp
       { EXP = $1; };

exp: tSERVICE
   { $$ = new ServiceExpression(); };
