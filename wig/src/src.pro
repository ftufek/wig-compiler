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
    y.tab.cc \
    lex.yy.cc


HEADERS += \
    ast_helpers.h \
    ast.h \
    y.tab.hh

LIBS += -lfl -ly

FLEXSOURCES = wig.l
BISONSOURCES = wig.y

OTHER_FILES +=  \
    $$FLEXSOURCES \
    $$BISONSOURCES
