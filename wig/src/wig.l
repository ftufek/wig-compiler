%{
  extern "C" int yylex();
  #include "tree.h"
  #include "y.tab.h"
%}

%%

"service" return tSERVICE;
