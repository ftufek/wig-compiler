%{
  #include "y.tab.h"
  extern "C" int yylex();
%}

%%

"service" return tSERVICE;
