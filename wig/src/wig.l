%{
extern "C" int yylex();
#include "ast.h"
#include <string>
#include "y.tab.h"
%}

ALFA [a-zA-Z]
ALFANUM {ALFA}|[0-9]
IDAUX {ALFANUM}|(_{ALFANUM})
ID {ALFA}{IDAUX}*
INT 0|([1-9][0-9]*)
LVALUE [a-zA-Z0-9.]
WHATEVER [^<>]*
STR				\"((\\\")|([^\"\n\t]))*\"

%s SERVICE
%x HTML HTMLCODE METACODE GAPCODE

%option noyywrap
%option never-interactive
%option yylineno
%option nounput
%%

"{" return '{';
"}" return '}';
"(" return '(';
")" return ')';
"[" return '[';
"]" return ']';
"," return ',';
"." return '.';
"!" return '!';
"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"%" return '%';
"==" return tEQ;
"!=" return tNEQ;
"<=" return tLEQ;
">=" return tHEQ;
"&&" return tLAND;
"||" return tLOR;
"<<" return tTCOMBINE;
"\\+" return tTKEEP;
"\\-" return tTDISCARD;
"<" return '<';
">" return '>';

<INITIAL>{
    "service" { BEGIN(SERVICE); return tSERVICE; }
}

<SERVICE>{
    "const" return tCONST;
    "html" return ttHTML;
    "=" return '=';
    ";" return ';';
    "<html>" { BEGIN(HTML); return tHtmlOpen; }
    "schema" return tSchema;
    "int" return tInt;
    "bool" return tBool;
    "string" return tString;
    "void" return tVoid;
    "tuple" return tTuple;

    "show" return tSHOW;
    "plug" return tPLUG;
    "receive" return tRECEIVE;
    "exit" return tEXIT;
    "return" return tRETURN;
    "if" return tIF;
    "else" return tELSE;
    "while" return tWHILE;

    "true" return tTRUE;
    "false" return tFALSE;
    "session" return tSESSION;
}

<HTML>{
    "<!--" { BEGIN(METACODE); return tMetaOpen; }
    "</" { BEGIN(HTMLCODE); return tTagClose; }
    "<[" { BEGIN(GAPCODE); return tGapOpen; }
    "<" { BEGIN(HTMLCODE); return '<'; }
    "</html>" { BEGIN(SERVICE); return tHtmlClose; }
}

<METACODE>{
    [-]{2,}">" { BEGIN(HTML); return tMetaClose; }
    [^->]* {yylval.str = new std::string(yytext);
        return tWHATEVER; }
}

<HTML>{
    {WHATEVER} { yylval.str = new std::string(yytext);
        return tWHATEVER; }
}

<GAPCODE>{
    "]>" { BEGIN(HTML); return tGapClose;}
}

<HTMLCODE>{
    "=" return '=';
    "input" return tInput;
    "select" return tSelect;
    "name" return tName;
    "type" return tType;
    "\"text\""|"\"radio\"" { yylval.str = new std::string(yytext);
        return tInputType; }
    ">" { BEGIN(HTML); return '>'; }
    {IDAUX}* { /* this is for the case where the html attribute is like:
                      size=2 border=2,
                  integers are not recognized as ID... */
        yylval.str = new std::string(yytext);
        return tID; }
}

<HTMLCODE,GAPCODE,INITIAL,SERVICE>{
    {ID} { yylval.str = new std::string(yytext);
        return tID; }
    {STR} { yylval.str = new std::string(yytext);
        return tSTR; }
    {INT} { yylval.integer = atoi(yytext); return tINT; }
    \n /* do nothing */
             . /* do nothing for now*/
}
