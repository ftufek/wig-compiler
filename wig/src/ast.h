#ifndef __AST_H
#define __AST_H

extern int yylineno;

#include <list>
#include <map>
#include <iostream>
#include "ast/ast.h"
#include "ast/type.h"
#include "ast/empty.h"
#include "ast/list.h"
#include "ast/service.h"
#include "ast/session.h"
#include "ast/variable.h"
#include "ast/html.h"
#include "ast/meta.h"
#include "ast/string.h"
#include "ast/whatever.h"
#include "ast/schema.h"
#include "ast/field.h"
#include "ast/helpers.h"
#include "ast/function.h"
#include "ast/stm.h"

#include "ast_visitor.h"

#endif
