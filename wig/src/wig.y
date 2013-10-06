%{
  #include <iostream>
  #include <string>
  #include <list>
  #include <map>
  #include "ast.h"
  #include "ast_helpers.h"

  extern "C" int yylex();
  extern Expression *EXP;
  extern char* yytext;
  extern bool success;
  extern int lineno;

  using namespace std;

  void yyerror(const char* str){
    cout<<"Error happened on line "<<lineno<<" before: "<<yytext<<endl;
    success = false;
  }
%}

%union{
  string *str;
  map<string, string> *dict;
  Expression *exp;
  ExpressionList *listExp;
}

%token tSERVICE
%token tCONST

%token ttHTML
%token <str> tID tWHATEVER tSTR

%token tHtmlOpen /* "<html>" */
%token tHtmlClose /* "</html>" */
%token tTagClose /* "</" */
%token tGapOpen /* "<[" */
%token tGapClose /* "]>" */
%token tMetaOpen
%token tMetaClose

%type <exp> service html htmlbody 
%type <listExp> htmls nehtmlbodies
%type <dict> attributes

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

html: tCONST ttHTML tID '=' tHtmlOpen nehtmlbodies tHtmlClose ';'
       { $$ = new VariableExpression(*$3, 
                                      "html", 
                                      true,
                                      wrapHtml($6)); }

nehtmlbodies: /* empty */
            { $$ = new ExpressionList(); }
            |  htmlbody
            { ExpressionList *l = new ExpressionList();
              l->getList()->push_front($1);
              $$ = l; }
            | nehtmlbodies htmlbody
            { $1->getList()->push_back($2);
              $$ = $1; }

htmlbody: '<' tID attributes '>' 
        { $$ = new HtmlTagExpression(*$2);}
        | tTagClose tID '>' /* "</tID>" */
        { $$ = new HtmlTagExpression(*$2, emptyMap(), true); }
        | tGapOpen tID tGapClose
        { $$ = new HtmlTagExpression(*$2, emptyMap(), false, true); }
        | tWHATEVER
        { $$ = new WhateverExpression(*$1); }
        | tMetaOpen tWHATEVER tMetaClose
        { $$ = new MetaTagExpression(*$2); }

attributes: /* emtpy */
          { $$ = emptyMap(); }
