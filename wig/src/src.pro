TEMPLATE = app
CONFIG -= app_bundle qt gui core
LIBS -= -lQtGui -lQtCore
QMAKE_CXXFLAGS += -std=c++11 -std=gnu++11

SOURCES += \
    main.cc \
    ast/ast.cc \
    pretty_printer.cc \
    ast/argument.cc \
    ast/empty.cc \
    ast/whatever.cc \
    ast/variable.cc \
    ast/type.cc \
    ast/string.cc \
    ast/stm.cc \
    ast/service.cc \
    ast/schema.cc \
    ast/meta.cc \
    ast/list.cc \
    ast/html.cc \
    ast/helpers.cc \
    ast/function.cc \
    ast/field.cc \
    ast/exp.cc

HEADERS += \
    ast.h \
    ast/ast.h \
    pretty_printer.h \
    ast_visitor.h \
    ast/argument.h \
    ast/empty.h \
    ast/exp.h \
    ast/field.h \
    ast/function.h \
    ast/helpers.h \
    ast/html.h \
    ast/list.h \
    ast/meta.h \
    ast/schema.h \
    ast/service.h \
    ast/stm.h \
    ast/string.h \
    ast/type.h \
    ast/variable.h \
    ast/whatever.h

OTHER_FILES += wig.l \
    wig.y

LIBS += -lfl -ly

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
