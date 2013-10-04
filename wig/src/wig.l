%{
  extern "C" int yylex();
  #include "ast.h"
  #include "y.tab.h"
%}

%%

"service" return tSERVICE;
