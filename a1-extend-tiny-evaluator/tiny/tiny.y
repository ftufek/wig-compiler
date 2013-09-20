%{
#include <stdio.h>
#include "tree.h"

extern char *yytext;
extern EXP *theexpression;

void yyerror() {
   printf ("syntax error before %s\n", yytext); 
}
%}

%union {
   int intconst;
   char *stringconst;
   struct EXP *exp;
}

%token <intconst> tINTCONST
%token <stringconst> tIDENTIFIER
%token tABSOLUTE
%token tPOWER "**"

%type <exp> program exp

%start program

%left '+' '-'
%left '*' '/' '%'
%left UMINUS
%right tPOWER

%% 
program: exp
         { theexpression = $1; }
;

exp : tIDENTIFIER
      { $$ = makeEXPid ($1); }
    | tINTCONST
      { $$ = makeEXPintconst ($1); }
    | exp '*' exp
      { $$ = makeEXPtimes ($1, $3); }
    | exp '/' exp
      { $$ = makeEXPdiv ($1, $3); }
    | exp '%' exp
      { $$ = makeEXPmodulo($1, $3); }
    | exp '+' exp
      { $$ = makeEXPplus ($1, $3); }
    | exp '-' exp
      { $$ = makeEXPminus ($1, $3); }
    | '-' exp %prec UMINUS
      { $$ = makeEXPminus(makeEXPintconst(0), $2); }
    | exp tPOWER exp
      { $$ = makeEXPpower ($1, $3);}
    | tABSOLUTE '(' exp ')'
      { $$ = makeEXPabsolute ($3); }
    | '(' exp ')'
      { $$ = $2; }
;
%%
