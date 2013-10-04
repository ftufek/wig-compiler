CC = g++
CFLAGS = -Wall

code: y.tab.o lex.yy.o main.o
	$(CC) lex.yy.o y.tab.o main.o -o fwig -lfl


y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

clean:
	rm -f y.tab.* lex.yy.* *.o fwig;
