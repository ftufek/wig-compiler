%{
  #include <iostream>
  #include <string>
  #include "ast.h"

  extern "C" int yylex();
  extern Expression *EXP;
  extern bool success;

  void yyerror(const char* str){
    std::cout<<"Error happened: "<<str<<std::endl;
    success = false;
  }
%}

%union{
  std::string *str;
  Expression *exp;
}

%token tSERVICE
%token tCONST

%token tHTML
%token <str> tID

%type <exp> service html

%start service

%%

service: tSERVICE '{' html '}'
       { EXP = new ServiceExpression($3); };
     | { EXP = new EmptyExpression(); }

html: tCONST tHTML tID '='
       { $$ = new VariableExpression($3); }
