/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tSERVICE = 258,
     tCONST = 259,
     tSESSION = 260,
     ttHTML = 261,
     tID = 262,
     tWHATEVER = 263,
     tSTR = 264,
     tInputType = 265,
     tINT = 266,
     tHtmlOpen = 267,
     tHtmlClose = 268,
     tTagClose = 269,
     tGapOpen = 270,
     tGapClose = 271,
     tMetaOpen = 272,
     tMetaClose = 273,
     tInput = 274,
     tSelect = 275,
     tName = 276,
     tType = 277,
     tSchema = 278,
     tInt = 279,
     tBool = 280,
     tString = 281,
     tVoid = 282,
     tTuple = 283,
     tSHOW = 284,
     tPLUG = 285,
     tRECEIVE = 286,
     tEXIT = 287,
     tRETURN = 288,
     tIF = 289,
     tELSE = 290,
     tWHILE = 291,
     tEQ = 292,
     tNEQ = 293,
     tLEQ = 294,
     tHEQ = 295,
     tLAND = 296,
     tLOR = 297,
     tTCOMBINE = 298,
     tTKEEP = 299,
     tTDISCARD = 300,
     tTRUE = 301,
     tFALSE = 302
   };
#endif
/* Tokens.  */
#define tSERVICE 258
#define tCONST 259
#define tSESSION 260
#define ttHTML 261
#define tID 262
#define tWHATEVER 263
#define tSTR 264
#define tInputType 265
#define tINT 266
#define tHtmlOpen 267
#define tHtmlClose 268
#define tTagClose 269
#define tGapOpen 270
#define tGapClose 271
#define tMetaOpen 272
#define tMetaClose 273
#define tInput 274
#define tSelect 275
#define tName 276
#define tType 277
#define tSchema 278
#define tInt 279
#define tBool 280
#define tString 281
#define tVoid 282
#define tTuple 283
#define tSHOW 284
#define tPLUG 285
#define tRECEIVE 286
#define tEXIT 287
#define tRETURN 288
#define tIF 289
#define tELSE 290
#define tWHILE 291
#define tEQ 292
#define tNEQ 293
#define tLEQ 294
#define tHEQ 295
#define tLAND 296
#define tLOR 297
#define tTCOMBINE 298
#define tTKEEP 299
#define tTDISCARD 300
#define tTRUE 301
#define tFALSE 302



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 21 "wig.y"

  int integer;
  std::string *str;
  std::map<std::string, std::string> *dict;
  std::list<std::string> *strList;
  std::list<ast::Argument*> *argList;
  std::list<ast::PlugStm*> *plugList;
  ast::Stm *stm;
  ast::Exp *exp;
  std::list<ast::Stm*> *stmList;
  std::list<ast::Exp*> *expList;
  ast::CompoundStm *compoundStm;
  ast::DocumentStm *docStm;
  ast::PlugStm *plugStm;
  ast::ReceiveStm *receiveStm;
  ast::Base *base;
  ast::List *listExp;
  ast::Type *typeExp;
  ast::Argument *argExp;
  ast::kType type;


/* Line 2053 of yacc.c  */
#line 174 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
