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
%type <dict> attributes neattributes attribute
%type <str> attr

%start service

%%

service: tSERVICE '{' htmls '}'
       { EXP = new ServiceExpression($3); }
     | { EXP = new EmptyExpression(); }

htmls : html
       { ExpressionList *l = new ExpressionList();
         l->getList()->push_front($1);
         $$ = l; }
      | htmls html
       { $1->getList()->push_back($2);
         $$ = $1; }

html: tCONST ttHTML tID '=' tHtmlOpen tHtmlClose ';'
       {$$ = new VariableExpression(*$3, "html", true,
                                    wrapHtml(new ExpressionList())); }
    | tCONST ttHTML tID '=' tHtmlOpen nehtmlbodies tHtmlClose ';'
       { $$ = new VariableExpression(*$3, 
                                      "html", 
                                      true,
                                      wrapHtml($6)); }

nehtmlbodies: htmlbody
            { ExpressionList *l = new ExpressionList();
              l->getList()->push_front($1);
              $$ = l; }
            | nehtmlbodies htmlbody
            { $1->getList()->push_back($2);
              $$ = $1; }

htmlbody: '<' tID attributes '>' 
        { $$ = new HtmlTagExpression(*$2, $3);}
        | tTagClose tID '>' /* "</tID>" */
        { $$ = new HtmlTagExpression(*$2, emptyMap(), true); }
        | tGapOpen tID tGapClose
        { $$ = new HtmlTagExpression(*$2, emptyMap(), false, true); }
        | tMetaOpen tWHATEVER tMetaClose
        { $$ = new MetaTagExpression(*$2); }
        | tWHATEVER
        { $$ = new WhateverExpression(*$1); }

attributes: /* emtpy */
          { $$ = emptyMap(); }
          | neattributes
          { $$ = $1; }

neattributes: attribute
            { $$ = $1; }
            | neattributes attribute
            { $1->insert($2->begin(), $2->end());
              $$ = $1; }

attribute: attr
         { map<string, string> *a = emptyMap();
           a->insert(pair<string, string>(*$1, ""));
           $$ = a; }
         | attr '=' attr
         { map<string, string> *a = emptyMap();
           a->insert(pair<string, string>(*$1, *$3));
           $$ = a; }

attr: tID
    { $$ = $1; }
    | tSTR
    { $$ = $1; }
