%{
  #include <iostream>
  #include <string>
  #include <list>
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
  std::list<Expression *> *list;
  Expression *exp;
}

%token tSERVICE
%token tCONST

%token ttHTML
%token <str> tID

%token tHtmlOpen
%token tHtmlClose

%type <exp> service html
%type <list> htmls

%start service

%%

service: tSERVICE '{' htmls '}'
       { EXP = new ServiceExpression($3); };
     | { EXP = new EmptyExpression(); }

htmls : /* empty */
        { $$ = new list<Expression *>; }
      | html
       { list<Expression *> *l = new list<Expression *>;
         l->push_front($1);
         $$ = l; }
      | htmls html
       { $1->push_back($2);
         $$ = $1; }

html: tCONST ttHTML tID '=' tHtmlOpen tHtmlClose ';'
       { $$ = new VariableExpression($3); }
