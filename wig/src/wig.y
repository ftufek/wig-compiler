%{
  #include <iostream>
  #include <string>
  #include <list>
  #include "ast.h"
  #include "ast_helpers.h"

  extern "C" int yylex();
  extern Expression *EXP;
  extern bool success;

  using namespace std;

  void yyerror(const char* str){
    std::cout<<"Error happened: "<<str<<std::endl;
    success = false;
  }
%}

%union{
  std::string *str;
  Expression *exp;
  ExpressionList *listExp;
}

%token tSERVICE
%token tCONST

%token ttHTML
%token <str> tID

%token tHtmlOpen
%token tHtmlClose

%type <exp> service html htmlbody 
%type <listExp> htmls

%start service

%%

service: tSERVICE '{' htmls '}'
       { EXP = new ServiceExpression($3); }
     | { EXP = new EmptyExpression(); }

htmls : /* empty */
        { $$ = new ExpressionList(); }
      | html
       { ExpressionList *l = new ExpressionList();
         l->getList()->push_front($1);
         $$ = l; }
      | htmls html
       { $1->getList()->push_back($2);
         $$ = $1; }

html: tCONST ttHTML tID '=' tHtmlOpen tHtmlClose ';'
       { $$ = new VariableExpression(*$3, 
                                      "html", 
                                      true,
                                      new EmptyExpression()); }
    | tCONST ttHTML tID '=' tHtmlOpen htmlbody tHtmlClose ';'
       { $$ = new VariableExpression(*$3, 
                                      "html", 
                                      true,
                                      $6); }

htmlbody: '<' tID '>' 
        { $$ = new HtmlTagExpression(*$2);}
