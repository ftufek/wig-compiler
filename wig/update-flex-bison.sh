#!/bin/bash

cd src/parser/;
bison -d -y wig.y && mv y.tab.c y.tab.cc;
flex wig.l && mv lex.yy.c lex.yy.cc;
