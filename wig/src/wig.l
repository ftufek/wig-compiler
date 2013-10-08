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
}

<HTML>{
  "<!--" { BEGIN(METACODE); return tMetaOpen; }
  "</" { BEGIN(HTMLCODE); return tTagClose; }
  "<[" { BEGIN(GAPCODE); return tGapOpen; }
  "<" { BEGIN(HTMLCODE); return '<'; }
  "</html>" { BEGIN(SERVICE); return tHtmlClose; }
}

<METACODE>{
  "-->" { BEGIN(HTML); return tMetaClose; }
  "-" return '-';
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
}

<HTMLCODE,GAPCODE,INITIAL,SERVICE>{
  {ID} { yylval.str = new std::string(yytext);
         return tID; }
  {STR} { yylval.str = new std::string(yytext);
         return tSTR; }
  \n /* do nothing */
  . /* do nothing for now*/
}
