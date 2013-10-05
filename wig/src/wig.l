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

%s SERVICE

%option noyywrap
%option never-interactive
%%

"{" return '{';
"}" return '}';

<INITIAL>{
  "service" { BEGIN(SERVICE); return tSERVICE; }
}

<SERVICE>{
  "const" return tCONST;
  "html" return ttHTML;
  "=" return '=';
  ";" return ';';
  "<html>" return tHtmlOpen;
  "</html>" return tHtmlClose;
}

{ID} { yylval.str = new std::string(yytext);
       return tID; }

.|\n /* do nothing */
