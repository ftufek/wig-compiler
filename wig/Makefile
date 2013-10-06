OUT = fwig
CC = g++
ODIR = obj
BDIR = build
SDIR = src
CFLAGS = -Wall
INC = -lfl

OBJ_FILES = y.tab.o lex.yy.o main.o \
						ast/ast.o ast/ast_service.o ast/ast_empty.o \
						ast/ast_variable.o ast/ast_html.o ast/ast_helpers.o \
						ast/ast_list.o
OBJS = $(patsubst %,$(BDIR)/%,$(OBJ_FILES))

code: bf $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(INC)

$(BDIR)/%.o: $(SDIR)/%.cc bf
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(BDIR)/y.tab.o: $(SDIR)/wig.y $(SDIR)/wig.l
	bison --yacc --defines $(SDIR)/wig.y -o $(SDIR)/y.tab.c
	$(CC) -c $(SDIR)/y.tab.c -o $(BDIR)/y.tab.o

$(BDIR)/lex.yy.o: $(SDIR)/wig.l $(SDIR)/wig.y
	flex -o $(SDIR)/lex.yy.c $(SDIR)/wig.l 
	$(CC) -c $(SDIR)/lex.yy.c -o $(BDIR)/lex.yy.o

bf:
	@bash -c 'mkdir -p $(BDIR)/{ast,a}'

clean:
	rm -f $(SDIR)/y.tab.c $(SDIR)/y.tab.h;
	rm -f $(SDIR)/lex.yy.c;
	rm -rf $(BDIR);
	rm -f $(OUT);
