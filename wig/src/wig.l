%{
  extern "C" int yylex();
  #include "ast.h"
  #include <string>
  #include "y.tab.h"

  extern int lineno;
%}

ALFA [a-zA-Z]
ALFANUM {ALFA}|[0-9]
IDAUX {ALFANUM}|(_{ALFANUM})
ID {ALFA}{IDAUX}*
WHATEVER [^<>]*

%s SERVICE
%x HTML HTMLCODE METACODE

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
  "<html>" { BEGIN(HTML); return tHtmlOpen; }
}

<HTML>{
  "<!--" { BEGIN(METACODE); return tMetaOpen; }
  "</" { BEGIN(HTMLCODE); return tTagClose; }
  "<[" { BEGIN(HTMLCODE); return tGapOpen; }
  "<" { BEGIN(HTMLCODE); return '<'; }
  "</html>" { BEGIN(SERVICE); return tHtmlClose; }
}

<METACODE>{
  "-->" { BEGIN(HTML); return tMetaClose; }
  "-" return '-';
  [^->]* {yylval.str = new string(yytext);
          return tWHATEVER; }
}

<HTML>{
  {WHATEVER} { yylval.str = new std::string(yytext);
               return tWHATEVER; }
}

<HTMLCODE>{
  ">" { BEGIN(HTML); return '>'; }
  "]>" { BEGIN(HTML); return tGapClose;}
}

<HTMLCODE,INITIAL,SERVICE>{
  {ID} { yylval.str = new std::string(yytext);
         return tID; }
  \n lineno++;
  . /* do nothing for now*/
}
