%{
  extern "C" int yylex();
  #include "y.tab.h"
%}

%%

"service" return tSERVICE;
