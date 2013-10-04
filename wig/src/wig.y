%{
#include <iostream>
%}

%token tSERVICE

%start service

%%

service: exp
       { };

exp: tSERVICE
   { std::cout<<"HELLO!"<<endl; }
