%{
#include <iostream>

extern "C" int yylex();

void yyerror(const char* str){
  std::cout<<"Error happened!\n";
}
%}

%token tSERVICE

%start service

%%

service: exp
       { };

exp: tSERVICE
   { std::cout<<"HELLO!"<<std::endl; }
