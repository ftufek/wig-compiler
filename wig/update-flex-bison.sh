#!/bin/bash

cd src/;
bison -d -t -y wig.y && mv y.tab.c y.tab.cc;
flex wig.l && mv lex.yy.c lex.yy.cc;
