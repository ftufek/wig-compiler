CC = g++
CFLAGS = -Wall

code: parser lexer


y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lexer: wig.l y.tab.h
	flex wig.l
	$(CC) lex.yy.c 

clean:
	rm -f y.tab.* lex.yy.* *.o;
