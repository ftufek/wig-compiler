OUT = fwig
CC = g++
ODIR = obj
BDIR = build
SDIR = src
CFLAGS = -Wall
INC = -lfl

code: y.tab.o lex.yy.o main.o
	$(CC) lex.yy.o y.tab.o main.o -o fwig -lfl

y.tab.c y.tab.h: wig.y
	bison --yacc --defines wig.y

lex.yy.c: wig.l y.tab.h
	flex wig.l

parser: $(BDIR) $(BDIR)/y.tab.o
lexer: $(BDIR) $(BDIR)/lex.yy.o

$(BDIR)/y.tab.o: $(SDIR)/wig.y
	bison --yacc --defines $(SDIR)/wig.y -o $(SDIR)/y.tab.c
	$(CC) -c $(SDIR)/y.tab.c -o $(BDIR)/y.tab.o

$(BDIR)/lex.yy.o: $(SDIR)/wig.l
	flex -o $(SDIR)/lex.yy.c $(SDIR)/wig.l 
	$(CC) -c $(SDIR)/lex.yy.c -o $(BDIR)/lex.yy.o

$(BDIR)/:
	mkdir $(BDIR)

clean:
	rm -f $(SDIR)/y.tab.c $(SDIR)/y.tab.h;
	rm -f $(SDIR)/lex.yy.c;
	rm -f y.tab.* lex.yy.* *.o fwig;
