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
  extern int yylineno;

  using namespace std;

  void yyerror(const char* str){
    cout<<"Error happened on line "<<yylineno<<" : "<<str<<endl;
    cout<<" before: "<<str<<endl;
    success = false;
  }
%}

%union{
  string *str;
  map<string, string> *dict;
  Expression *exp;
  ExpressionList *listExp;
  Type type;
}

%token tSERVICE
%token tCONST

%token ttHTML
%token <str> tID tWHATEVER tSTR tInputType


/* HTML RELATED TOKENS */
%token tHtmlOpen /* "<html>" */
%token tHtmlClose /* "</html>" */
%token tTagClose /* "</" */
%token tGapOpen /* "<[" */
%token tGapClose /* "]>" */
%token tMetaOpen
%token tMetaClose
%token tInput
%token tSelect
%token tName
%token tType
/* END OF HTML RELATED TOKENS */

%token tSchema
%token tInt
%token tBool
%token tString
%token tVoid

%type <exp> service html htmlbody schema field
%type <listExp> htmls nehtmlbodies schemas neschemas fields nefields
%type <dict> attributes neattributes attribute inputattr inputattrs
%type <str> attr
%type <type> simpletype

%start service
%%

service: tSERVICE '{' htmls schemas '}'
       { EXP = new ServiceExpression($3, $4); }
     | { EXP = new EmptyExpression(); }

htmls : html
       { $$ = initList($1); }
      | htmls html
       { $$ = addBack($1, $2); }

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
        | tWHATEVER
        { $$ = new WhateverExpression(*$1); }
        | tMetaOpen tWHATEVER tMetaClose
        { $$ = new MetaTagExpression(*$2); }
        | '<' tInput inputattrs '>'
        { $$ = new HtmlTagExpression("input", $3); }
        | '<' tSelect inputattrs '>' nehtmlbodies tTagClose tSelect '>'
        { $$ = wrapAround("select", $3, $5); }         
        | '<' tSelect inputattrs '>' tTagClose tSelect '>'
        { $$ = wrapAround("select", $3, new ExpressionList()); }

inputattrs: inputattr
        { $$ = $1; }
        | inputattrs inputattr
        { $$ = mergeMap($1, $2); }

inputattr: tName '=' attr
         { $$ = initMap("name", *$3); }
         | tType '=' tInputType
         { $$ = initMap("type", *$3); }
         | attribute
         { $$ = $1; }

attributes: /* emtpy */
          { $$ = emptyMap(); }
          | neattributes
          { $$ = $1; }

neattributes: attribute
            { $$ = $1; }
            | neattributes attribute
            { $$ = mergeMap($1, $2); }

attribute: attr
         { $$ = initMap(*$1, ""); }
         | attr '=' attr
         { $$ = initMap(*$1, *$3); }

attr: tID
    { $$ = $1; }
    | tSTR
    { $$ = $1; }

schemas: /* empty */
       { $$ = new ExpressionList(); }
       | neschemas
       { $$ = $1; }

neschemas: schema
         { $$ = initList($1); }
         | neschemas schema
         { $$ = addBack($1, $2); }

schema: tSchema tID '{' fields '}'
      { $$ = new SchemaExpression(*$2, $4); }

fields: /* empty */
      { $$ = new ExpressionList(); }
      | nefields
      { $$ = $1; }

nefields: field
        { $$ = initList($1); }
        | nefields field
        { $$ = addBack($1, $2); }

field: simpletype tID ';'
     { $$ = new FieldExpression($1, *$2); }

simpletype: tInt
           { $$ = INT; }
           | tBool
           { $$ = BOOL; }
           | tString
           { $$ = STRING; }
           | tVoid
           { $$ = VOID; }
