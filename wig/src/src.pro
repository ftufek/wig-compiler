TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cc \
    ast/ast_whatever.cc \
    ast/ast_variable.cc \
    ast/ast_string.cc \
    ast/ast_service.cc \
    ast/ast_schema.cc \
    ast/ast_meta.cc \
    ast/ast_list.cc \
    ast/ast_html.cc \
    ast/ast_helpers.cc \
    ast/ast_field.cc \
    ast/ast_empty.cc \
    ast/ast.cc \

HEADERS += \
    ast_helpers.h \
    ast.h \
    ast/ast.h \
    ast/ast_empty.h \
    ast/ast_list.h \
    ast/ast_service.h \
    ast/ast_variable.h \
    ast/ast_html.h \
    ast/ast_meta.h \
    ast/ast_string.h \
    ast/ast_whatever.h \
    ast/ast_schema.h \
    ast/ast_field.h

OTHER_FILES += wig.l \
    wig.y

LIBS += -lfl -ly

#CONFIG += lex
#LEXSOURCES += wig.l
#QMAKE_YACC=bison
#CONFIG += yacc
#YACCSOURCES += wig.y
#lex.CONFIG += target_predeps
#yacc_impl.CONFIG += target_predeps
#yacc_decl.CONFIG += target_predeps

FLEXSOURCES = wig.l
BISONSOURCES = wig.y

flex.commands = flex ${QMAKE_FILE_IN} && mv lex.yy.c lex.yy.cc
flex.input = FLEXSOURCES
flex.output = lex.yy.cc
flex.variable_out = SOURCES
flex.depends = y.tab.h
flex.name = flex
QMAKE_EXTRA_COMPILERS += flex

bison.commands = bison -d -t -y ${QMAKE_FILE_IN} && mv y.tab.c y.tab.cc
bison.input = BISONSOURCES
bison.output = y.tab.cc
bison.variable_out = SOURCES
bison.name = bison
QMAKE_EXTRA_COMPILERS += bison

bisonheader.commands = @true
bisonheader.input = BISONSOURCES
bisonheader.output = y.tab.h
bisonheader.variable_out = HEADERS
bisonheader.name = bison header
bisonheader.depends = y.tab.cc
QMAKE_EXTRA_COMPILERS += bisonheader
