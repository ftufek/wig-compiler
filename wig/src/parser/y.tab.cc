/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "wig.y"

  #include <iostream>
  #include <string>
  #include <list>
  #include <map>
  #include "../ast.h"

  extern "C" int yylex();
  extern ast::Base *EXP;
  extern char* yytext;
  extern bool success;
  extern int yylineno;

  void yyerror(const char* str){
    std::cout<<"Error happened on line "<<yylineno<<" : "<<str<<std::endl;
    std::cout<<" before: "<<yytext<<std::endl;
    success = false;
  }

/* Line 371 of yacc.c  */
#line 88 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     tFALSE = 302,
     UMINUS = 303
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
#define UMINUS 303



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 250 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 278 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    52,     2,     2,
      62,    63,    50,    49,    61,    48,    66,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
      54,    56,    55,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    20,    21,    23,    26,    35,    43,
      45,    48,    53,    57,    61,    63,    67,    72,    81,    89,
      91,    94,    98,   102,   104,   105,   107,   109,   112,   114,
     118,   120,   122,   123,   125,   127,   130,   136,   137,   139,
     141,   144,   148,   150,   152,   154,   156,   158,   161,   163,
     166,   170,   172,   176,   177,   179,   181,   184,   191,   192,
     194,   196,   200,   203,   208,   212,   214,   217,   223,   224,
     226,   228,   231,   233,   238,   242,   245,   249,   255,   263,
     269,   271,   274,   276,   282,   284,   288,   292,   293,   298,
     300,   304,   308,   312,   316,   320,   324,   328,   331,   334,
     338,   342,   346,   350,   354,   358,   362,   366,   370,   376,
     380,   386,   391,   393,   395,   397,   399,   404,   408,   409,
     411,   413,   417,   421,   422,   424,   426,   430,   431,   433,
     435,   439,   443,   445
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,     3,    58,    69,    79,    87,    90,    97,
      59,    -1,     3,    58,    69,    79,    90,    97,    59,    -1,
      -1,    70,    -1,    69,    70,    -1,     4,     6,     7,    56,
      12,    71,    13,    60,    -1,     4,     6,     7,    56,    12,
      13,    60,    -1,    72,    -1,    71,    72,    -1,    54,     7,
      75,    55,    -1,    14,     7,    55,    -1,    15,     7,    16,
      -1,     8,    -1,    17,     8,    18,    -1,    54,    19,    73,
      55,    -1,    54,    20,    73,    55,    71,    14,    20,    55,
      -1,    54,    20,    73,    55,    14,    20,    55,    -1,    74,
      -1,    73,    74,    -1,    21,    56,    78,    -1,    22,    56,
      10,    -1,    77,    -1,    -1,    76,    -1,    77,    -1,    76,
      77,    -1,    78,    -1,    78,    56,    78,    -1,     7,    -1,
       9,    -1,    -1,    80,    -1,    81,    -1,    80,    81,    -1,
      23,     7,    58,    82,    59,    -1,    -1,    83,    -1,    84,
      -1,    83,    84,    -1,    85,     7,    60,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    85,    -1,    28,     7,
      -1,    88,    -1,    87,    88,    -1,    86,    89,    60,    -1,
       7,    -1,    89,    61,     7,    -1,    -1,    91,    -1,    92,
      -1,    91,    92,    -1,    86,     7,    62,    93,    63,    96,
      -1,    -1,    94,    -1,    95,    -1,    94,    61,    95,    -1,
      86,     7,    -1,    58,    87,    99,    59,    -1,    58,    99,
      59,    -1,    98,    -1,    97,    98,    -1,     5,     7,    62,
      63,    96,    -1,    -1,   100,    -1,   101,    -1,   100,   101,
      -1,    60,    -1,    29,   102,   105,    60,    -1,    32,   102,
      60,    -1,    33,    60,    -1,    33,   106,    60,    -1,    34,
      62,   106,    63,   101,    -1,    34,    62,   106,    63,   101,
      35,   101,    -1,    36,    62,   106,    63,   101,    -1,    96,
      -1,   106,    60,    -1,     7,    -1,    30,     7,    64,   103,
      65,    -1,   104,    -1,   103,    61,   104,    -1,     7,    56,
     106,    -1,    -1,    31,    64,   112,    65,    -1,   115,    -1,
     115,    56,   106,    -1,   106,    37,   106,    -1,   106,    38,
     106,    -1,   106,    54,   106,    -1,   106,    55,   106,    -1,
     106,    39,   106,    -1,   106,    40,   106,    -1,    48,   106,
      -1,    53,   106,    -1,   106,    49,   106,    -1,   106,    48,
     106,    -1,   106,    50,   106,    -1,   106,    51,   106,    -1,
     106,    52,   106,    -1,   106,    41,   106,    -1,   106,    42,
     106,    -1,   106,    43,   106,    -1,   106,    44,     7,    -1,
     106,    44,    62,    89,    63,    -1,   106,    45,     7,    -1,
     106,    45,    62,    89,    63,    -1,     7,    62,   110,    63,
      -1,    11,    -1,    46,    -1,    47,    -1,     9,    -1,    28,
      58,   107,    59,    -1,    62,   106,    63,    -1,    -1,   108,
      -1,   109,    -1,   108,    61,   109,    -1,     7,    56,   106,
      -1,    -1,   111,    -1,   106,    -1,   111,    61,   106,    -1,
      -1,   113,    -1,   114,    -1,   113,    61,   114,    -1,   115,
      56,     7,    -1,     7,    -1,     7,    66,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   104,   107,   109,   111,   114,   120,   125,
     129,   133,   135,   137,   139,   141,   143,   145,   147,   150,
     152,   155,   157,   159,   163,   164,   167,   169,   172,   174,
     177,   179,   183,   184,   187,   189,   192,   196,   197,   200,
     202,   205,   208,   210,   212,   214,   217,   219,   222,   224,
     227,   239,   241,   246,   247,   250,   252,   255,   259,   260,
     263,   265,   268,   271,   273,   276,   278,   281,   285,   286,
     289,   291,   294,   296,   298,   300,   302,   304,   306,   308,
     310,   312,   315,   317,   320,   322,   325,   329,   330,   333,
     335,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   375,   377,
     380,   382,   384,   386,   388,   390,   392,   394,   398,   399,
     402,   404,   407,   411,   412,   415,   417,   421,   422,   425,
     427,   430,   433,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tSERVICE", "tCONST", "tSESSION",
  "ttHTML", "tID", "tWHATEVER", "tSTR", "tInputType", "tINT", "tHtmlOpen",
  "tHtmlClose", "tTagClose", "tGapOpen", "tGapClose", "tMetaOpen",
  "tMetaClose", "tInput", "tSelect", "tName", "tType", "tSchema", "tInt",
  "tBool", "tString", "tVoid", "tTuple", "tSHOW", "tPLUG", "tRECEIVE",
  "tEXIT", "tRETURN", "tIF", "tELSE", "tWHILE", "tEQ", "tNEQ", "tLEQ",
  "tHEQ", "tLAND", "tLOR", "tTCOMBINE", "tTKEEP", "tTDISCARD", "tTRUE",
  "tFALSE", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'", "'<'", "'>'", "'='",
  "UMINUS", "'{'", "'}'", "';'", "','", "'('", "')'", "'['", "']'", "'.'",
  "$accept", "service", "htmls", "html", "nehtmlbodies", "htmlbody",
  "inputattrs", "inputattr", "attributes", "neattributes", "attribute",
  "attr", "schemas", "neschemas", "schema", "fields", "nefields", "field",
  "simpletype", "type", "nevariables", "variable", "identifiers",
  "functions", "nefunctions", "function", "arguments", "nearguments",
  "argument", "compoundstm", "sessions", "session", "stms", "nestms",
  "stm", "document", "plugs", "plug", "receive", "exp", "fieldvalues",
  "nefieldvalues", "fieldvalue", "exps", "neexps", "inputs", "neinputs",
  "input", "lvalue", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    45,    43,
      42,    47,    37,    33,    60,    62,    61,   303,   123,   125,
      59,    44,    40,    41,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    91,    91,    92,    93,    93,
      94,    94,    95,    96,    96,    97,    97,    98,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103,   104,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     0,     1,     2,     8,     7,     1,
       2,     4,     3,     3,     1,     3,     4,     8,     7,     1,
       2,     3,     3,     1,     0,     1,     1,     2,     1,     3,
       1,     1,     0,     1,     1,     2,     5,     0,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     1,     3,     0,     1,     1,     2,     6,     0,     1,
       1,     3,     2,     4,     3,     1,     2,     5,     0,     1,
       1,     2,     1,     4,     3,     2,     3,     5,     7,     5,
       1,     2,     1,     5,     1,     3,     3,     0,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     3,
       5,     4,     1,     1,     1,     1,     4,     3,     0,     1,
       1,     3,     3,     0,     1,     1,     3,     0,     1,     1,
       3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     1,     0,    32,     5,     0,     0,
       6,    53,    33,    34,     0,     0,    42,    43,    44,    45,
       0,    46,     0,    53,    48,     0,    54,    55,    35,     0,
      37,    47,    51,     0,    49,     0,     0,     0,    65,     0,
      56,     0,     0,    38,    39,     0,    58,    50,     0,     0,
       0,     3,    66,     0,    14,     0,     0,     0,     0,     0,
       0,     9,    36,    40,     0,     0,     0,    59,    60,    52,
       2,     0,     8,     0,     0,     0,    24,     0,     0,     0,
      10,    41,    62,     0,     0,     0,    12,    13,    15,    30,
      31,     0,    25,    26,    28,     0,     0,     0,    19,    23,
       0,     7,    68,    57,    61,    67,    11,    27,     0,     0,
       0,    16,    20,     0,   132,   115,   112,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,    72,     0,     0,
      68,    80,     0,    69,    70,     0,    89,    29,    21,    22,
       0,     0,   123,     0,   118,    82,     0,    87,     0,     0,
      75,     0,     0,     0,    97,    98,     0,    51,     0,    64,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
       0,   125,     0,   124,   133,     0,     0,   119,   120,     0,
       0,     0,    74,    76,     0,     0,   117,    63,    91,    92,
      95,    96,   104,   105,   106,   107,     0,   109,     0,   100,
      99,   101,   102,   103,    93,    94,    90,    18,     0,   111,
       0,     0,   116,     0,     0,   127,    73,     0,     0,     0,
       0,    17,   126,   122,   121,     0,     0,    84,   132,     0,
     128,   129,     0,    77,    79,   108,   110,     0,     0,    83,
      88,     0,     0,     0,    86,    85,   130,   131,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    60,    61,    97,    98,    91,    92,
      99,    94,    11,    12,    13,    42,    43,    44,    21,    22,
      23,    24,    33,    25,    26,    27,    66,    67,    68,   131,
      37,    38,   132,   133,   134,   147,   236,   237,   191,   135,
     186,   187,   188,   182,   183,   239,   240,   241,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -216
static const yytype_int16 yypact[] =
{
      25,   -38,    40,    45,  -216,    81,    12,  -216,    91,    92,
    -216,   163,   118,  -216,    70,    84,  -216,  -216,  -216,  -216,
     140,  -216,   148,   163,  -216,   155,   163,  -216,  -216,   151,
     143,  -216,   111,    -1,  -216,   155,   170,     6,  -216,   171,
    -216,    89,   133,   143,  -216,   194,   163,  -216,   195,    10,
     142,  -216,  -216,   111,  -216,   146,   203,   205,   200,    71,
     131,  -216,  -216,  -216,   153,   207,   152,   156,  -216,  -216,
    -216,   161,  -216,   164,   202,   198,   107,   103,   103,   160,
    -216,  -216,  -216,   167,   163,   167,  -216,  -216,  -216,  -216,
    -216,   172,   107,  -216,   173,   174,   176,    17,  -216,  -216,
      67,  -216,   104,  -216,  -216,  -216,  -216,  -216,   107,   107,
     216,  -216,  -216,    69,     9,  -216,  -216,     5,     7,     7,
      20,   169,   185,  -216,  -216,   175,   175,  -216,   175,   226,
     104,  -216,   177,   147,  -216,   282,   178,  -216,  -216,  -216,
      50,   157,   175,   241,   247,  -216,   250,   204,   199,   217,
    -216,   306,   175,   175,  -216,   400,   201,  -216,   215,  -216,
    -216,   175,   175,   175,   175,   175,   175,   175,     0,     2,
     175,   175,   175,   175,   175,   175,   175,  -216,   175,   206,
      74,   330,   197,   220,  -216,   229,   225,   227,  -216,   222,
     223,   230,  -216,  -216,   228,   255,  -216,  -216,  -216,  -216,
    -216,  -216,   400,   387,    80,  -216,   226,  -216,   226,   349,
     349,   368,   368,   368,  -216,  -216,  -216,  -216,   208,  -216,
     175,   175,  -216,   247,   251,   294,  -216,   147,   147,   -42,
      98,  -216,   330,   330,  -216,   233,    88,  -216,   196,   237,
     252,  -216,   256,   273,  -216,  -216,  -216,   175,   251,  -216,
    -216,   294,   304,   147,   330,  -216,  -216,  -216,  -216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,  -216,   308,   239,   -56,   238,     8,  -216,  -216,
     -58,   -16,  -216,  -216,   303,  -216,  -216,   274,   -13,   -23,
     236,   -21,   -10,   305,  -216,   309,  -216,  -216,   245,   114,
     318,   -24,   209,  -216,  -132,   221,  -216,    93,  -216,  -120,
    -216,  -216,   136,  -216,  -216,  -216,  -216,   112,  -215
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     151,   160,    34,    39,    80,   154,   155,   205,   156,   207,
     242,    36,    31,    52,   145,    36,     5,    45,    93,    48,
       3,   245,   181,    65,    89,    52,    90,   114,     1,   115,
      45,   116,   194,   195,   107,     9,   242,   146,    95,    96,
       4,   198,   199,   200,   201,   202,   203,   204,   149,     5,
     209,   210,   211,   212,   213,   214,   215,    73,   216,    47,
      48,    65,   206,   144,   208,    51,   123,   124,   125,    70,
     179,   142,   111,   126,    89,   143,    90,    54,    76,   129,
     150,    73,   128,   140,    57,    80,    58,     8,    95,    96,
      77,    78,   137,   138,   218,   243,   244,    54,    14,    15,
     232,   233,    55,    56,    57,   112,    58,   129,   112,    34,
      89,   114,    90,   115,    89,   116,    90,   161,   162,   163,
     164,   258,   113,    59,    95,    96,    29,   254,    16,    17,
      18,    19,   117,   118,   175,   176,   119,   120,   121,    54,
     122,     9,    30,    59,    79,    56,    57,    31,    58,   248,
     123,   124,   125,   249,   114,    32,   115,   126,   116,    48,
      36,   246,   102,    41,   127,    54,   128,    16,    17,    18,
      19,   180,    57,    46,    58,   149,   118,    50,    53,   119,
     120,   121,   114,   122,   115,    59,   116,    16,    17,    18,
      19,    20,    62,   123,   124,   125,   229,   103,   230,   105,
     126,    64,    69,   149,    71,   102,    72,   127,    75,   128,
      73,    59,    74,    81,    82,    83,    88,    84,    87,    86,
     101,   123,   124,   125,    85,   102,   139,   106,   126,   108,
     109,   152,   110,   157,   178,   190,   159,   128,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   153,   184,   170,
     171,   172,   173,   174,   185,   175,   176,   189,   235,   192,
     219,   217,   143,   231,   196,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   197,   144,   170,   171,   172,   173,
     174,   220,   175,   176,   222,   221,   224,   225,   223,   247,
     226,   227,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   238,   250,   170,   171,   172,   173,   174,   253,   175,
     176,   257,   252,   251,    10,    28,   100,    63,   228,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    35,   104,
     170,   171,   172,   173,   174,    40,   175,   176,   130,   158,
     148,   255,   177,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   141,    49,   170,   171,   172,   173,   174,   234,
     175,   176,     0,   256,     0,     0,   193,   161,   162,   163,
     164,   165,   166,   167,   168,   169,     0,     0,   170,   171,
     172,   173,   174,     0,   175,   176,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     0,     0,     0,     0,   172,
     173,   174,     0,   175,   176,   161,   162,   163,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,   175,   176,   161,   162,   163,   164,   165,     0,
     167,   168,   169,     0,     0,     0,     0,   161,   162,   163,
     164,   175,   176,   167,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   176
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-216)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     120,   133,    23,    26,    60,   125,   126,     7,   128,     7,
     225,     5,     7,    37,     7,     5,     4,    30,    76,    61,
      58,    63,   142,    46,     7,    49,     9,     7,     3,     9,
      43,    11,   152,   153,    92,    23,   251,    30,    21,    22,
       0,   161,   162,   163,   164,   165,   166,   167,    28,     4,
     170,   171,   172,   173,   174,   175,   176,     7,   178,    60,
      61,    84,    62,    58,    62,    59,    46,    47,    48,    59,
      20,    62,    55,    53,     7,    66,     9,     8,     7,   102,
      60,     7,    62,    14,    15,   141,    17,     6,    21,    22,
      19,    20,   108,   109,    20,   227,   228,     8,     7,     7,
     220,   221,    13,    14,    15,    97,    17,   130,   100,   130,
       7,     7,     9,     9,     7,    11,     9,    37,    38,    39,
      40,   253,    55,    54,    21,    22,    56,   247,    24,    25,
      26,    27,    28,    29,    54,    55,    32,    33,    34,     8,
      36,    23,    58,    54,    13,    14,    15,     7,    17,    61,
      46,    47,    48,    65,     7,     7,     9,    53,    11,    61,
       5,    63,    58,    12,    60,     8,    62,    24,    25,    26,
      27,    14,    15,    62,    17,    28,    29,     7,     7,    32,
      33,    34,     7,    36,     9,    54,    11,    24,    25,    26,
      27,    28,    59,    46,    47,    48,   206,    83,   208,    85,
      53,     7,     7,    28,    62,    58,    60,    60,     8,    62,
       7,    54,     7,    60,     7,    63,    18,    61,    16,    55,
      60,    46,    47,    48,    63,    58,    10,    55,    53,    56,
      56,    62,    56,     7,    56,    31,    59,    62,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    62,     7,    48,
      49,    50,    51,    52,     7,    54,    55,     7,     7,    60,
      63,    55,    66,    55,    63,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    59,    58,    48,    49,    50,    51,
      52,    61,    54,    55,    59,    56,    64,    64,    61,    56,
      60,    63,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     7,    65,    48,    49,    50,    51,    52,    35,    54,
      55,     7,    56,    61,     6,    12,    78,    43,    63,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    23,    84,
      48,    49,    50,    51,    52,    26,    54,    55,   102,   130,
     119,   248,    60,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   113,    35,    48,    49,    50,    51,    52,   223,
      54,    55,    -1,   251,    -1,    -1,    60,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    54,    55,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    54,    55,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    54,    55,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    68,    58,     0,     4,    69,    70,     6,    23,
      70,    79,    80,    81,     7,     7,    24,    25,    26,    27,
      28,    85,    86,    87,    88,    90,    91,    92,    81,    56,
      58,     7,     7,    89,    88,    90,     5,    97,    98,    86,
      92,    12,    82,    83,    84,    85,    62,    60,    61,    97,
       7,    59,    98,     7,     8,    13,    14,    15,    17,    54,
      71,    72,    59,    84,     7,    86,    93,    94,    95,     7,
      59,    62,    60,     7,     7,     8,     7,    19,    20,    13,
      72,    60,     7,    63,    61,    63,    55,    16,    18,     7,
       9,    75,    76,    77,    78,    21,    22,    73,    74,    77,
      73,    60,    58,    96,    95,    96,    55,    77,    56,    56,
      56,    55,    74,    55,     7,     9,    11,    28,    29,    32,
      33,    34,    36,    46,    47,    48,    53,    60,    62,    86,
      87,    96,    99,   100,   101,   106,   115,    78,    78,    10,
      14,    71,    62,    66,    58,     7,    30,   102,   102,    28,
      60,   106,    62,    62,   106,   106,   106,     7,    99,    59,
     101,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      48,    49,    50,    51,    52,    54,    55,    60,    56,    20,
      14,   106,   110,   111,     7,     7,   107,   108,   109,     7,
      31,   105,    60,    60,   106,   106,    63,    59,   106,   106,
     106,   106,   106,   106,   106,     7,    62,     7,    62,   106,
     106,   106,   106,   106,   106,   106,   106,    55,    20,    63,
      61,    56,    59,    61,    64,    64,    60,    63,    63,    89,
      89,    55,   106,   106,   109,     7,   103,   104,     7,   112,
     113,   114,   115,   101,   101,    63,    63,    56,    61,    65,
      65,    61,    56,    35,   106,   104,   114,     7,   101
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 103 "wig.y"
    { EXP = new ast::Service((yyvsp[(3) - (8)].listExp), (yyvsp[(4) - (8)].listExp), (yyvsp[(6) - (8)].listExp), (yyvsp[(7) - (8)].listExp), (yyvsp[(5) - (8)].listExp)); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 105 "wig.y"
    { EXP = new ast::Service((yyvsp[(3) - (7)].listExp), (yyvsp[(4) - (7)].listExp), (yyvsp[(5) - (7)].listExp), (yyvsp[(6) - (7)].listExp)); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 107 "wig.y"
    { yyerror("Error: doesn't contain any service."); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 110 "wig.y"
    { (yyval.listExp) = new ast::List((yyvsp[(1) - (1)].base)); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 112 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].base)); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 115 "wig.y"
    { (yyval.base) = new ast::Variable(*(yyvsp[(3) - (8)].str),
                                      new ast::Type(ast::kType::HTML),
                                      ast::kConstVar,
                                      ast::wrapHtml((yyvsp[(6) - (8)].listExp)));
          delete((yyvsp[(3) - (8)].str)); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 121 "wig.y"
    {(yyval.base) = new ast::Variable(*(yyvsp[(3) - (7)].str), new ast::Type(ast::kType::HTML), ast::kConstVar,
                                    ast::wrapHtml(new ast::List()));
        delete((yyvsp[(3) - (7)].str)); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 126 "wig.y"
    { ast::List *l = new ast::List();
              l->getList()->push_front((yyvsp[(1) - (1)].base));
              (yyval.listExp) = l; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 130 "wig.y"
    { (yyvsp[(1) - (2)].listExp)->getList()->push_back((yyvsp[(2) - (2)].base));
              (yyval.listExp) = (yyvsp[(1) - (2)].listExp); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 134 "wig.y"
    { (yyval.base) = new ast::HtmlTag(*(yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].dict)); delete((yyvsp[(2) - (4)].str)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 136 "wig.y"
    { (yyval.base) = new ast::HtmlTag(*(yyvsp[(2) - (3)].str), ast::emptyMap(), true); delete((yyvsp[(2) - (3)].str)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 138 "wig.y"
    { (yyval.base) = new ast::HtmlTag(*(yyvsp[(2) - (3)].str), ast::emptyMap(), false, true); delete((yyvsp[(2) - (3)].str)); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 140 "wig.y"
    { (yyval.base) = new ast::Whatever(*(yyvsp[(1) - (1)].str)); delete((yyvsp[(1) - (1)].str)); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 142 "wig.y"
    { (yyval.base) = new ast::MetaTag(*(yyvsp[(2) - (3)].str)); delete((yyvsp[(2) - (3)].str)); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 144 "wig.y"
    { (yyval.base) = new ast::HtmlTag("input", (yyvsp[(3) - (4)].dict)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 146 "wig.y"
    { (yyval.base) = ast::wrapAround("select", (yyvsp[(3) - (8)].dict), (yyvsp[(5) - (8)].listExp)); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 148 "wig.y"
    { (yyval.base) = ast::wrapAround("select", (yyvsp[(3) - (7)].dict), new ast::List()); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 151 "wig.y"
    { (yyval.dict) = (yyvsp[(1) - (1)].dict); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 153 "wig.y"
    { (yyval.dict) = ast::mergeMap((yyvsp[(1) - (2)].dict), (yyvsp[(2) - (2)].dict)); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 156 "wig.y"
    { (yyval.dict) = ast::initMap("name", *(yyvsp[(3) - (3)].str)); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 158 "wig.y"
    { (yyval.dict) = ast::initMap("type", *(yyvsp[(3) - (3)].str)); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 160 "wig.y"
    { (yyval.dict) = (yyvsp[(1) - (1)].dict); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 163 "wig.y"
    { (yyval.dict) = ast::emptyMap(); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 165 "wig.y"
    { (yyval.dict) = (yyvsp[(1) - (1)].dict); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 168 "wig.y"
    { (yyval.dict) = (yyvsp[(1) - (1)].dict); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 170 "wig.y"
    { (yyval.dict) = ast::mergeMap((yyvsp[(1) - (2)].dict), (yyvsp[(2) - (2)].dict)); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 173 "wig.y"
    { (yyval.dict) = ast::initMap(*(yyvsp[(1) - (1)].str), ""); delete((yyvsp[(1) - (1)].str)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 175 "wig.y"
    { (yyval.dict) = ast::initMap(*(yyvsp[(1) - (3)].str), *(yyvsp[(3) - (3)].str)); delete((yyvsp[(1) - (3)].str)); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 178 "wig.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 180 "wig.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 183 "wig.y"
    { (yyval.listExp) = new ast::List(); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 185 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (1)].listExp); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 188 "wig.y"
    { (yyval.listExp) = new ast::List((yyvsp[(1) - (1)].base)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 190 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].base)); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 193 "wig.y"
    { (yyval.base) = new ast::Schema(*(yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].listExp)); delete((yyvsp[(2) - (5)].str)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 196 "wig.y"
    { (yyval.listExp) = new ast::List(); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 198 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (1)].listExp); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 201 "wig.y"
    { (yyval.listExp) = new ast::List((yyvsp[(1) - (1)].base)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 203 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].base)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 206 "wig.y"
    { (yyval.base) = new ast::Field(new ast::Type((yyvsp[(1) - (3)].type)), *(yyvsp[(2) - (3)].str)); delete((yyvsp[(2) - (3)].str)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 209 "wig.y"
    { (yyval.type) = ast::kType::INT; }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 211 "wig.y"
    { (yyval.type) = ast::kType::BOOL; }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 213 "wig.y"
    { (yyval.type) = ast::kType::STRING; }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 215 "wig.y"
    { (yyval.type) = ast::kType::VOID; }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 218 "wig.y"
    { (yyval.typeExp) = new ast::Type((yyvsp[(1) - (1)].type)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 220 "wig.y"
    { (yyval.typeExp) = new ast::Type(ast::kType::TUPLE, *(yyvsp[(2) - (2)].str)); delete((yyvsp[(2) - (2)].str)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 223 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (1)].listExp); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 225 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].listExp)); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 228 "wig.y"
    { (yyval.listExp) = new ast::List();
      std::list<std::string>::const_iterator it;
      for(it = (yyvsp[(2) - (3)].strList)->begin(); it != (yyvsp[(2) - (3)].strList)->end(); ++it){
        (yyval.listExp)->AddBack(new ast::Variable(*it,
                         (yyvsp[(1) - (3)].typeExp),
                         ast::kNoConstVar,
                         ast::kNoVal));
      }
      delete((yyvsp[(2) - (3)].strList));
     }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 240 "wig.y"
    { (yyval.strList) = new std::list<std::string>{*(yyvsp[(1) - (1)].str)}; delete((yyvsp[(1) - (1)].str)); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 242 "wig.y"
    { (yyvsp[(1) - (3)].strList)->push_back(*(yyvsp[(3) - (3)].str)); delete((yyvsp[(3) - (3)].str));
      (yyval.strList) = (yyvsp[(1) - (3)].strList); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 246 "wig.y"
    { (yyval.listExp) = new ast::List(new ast::Empty()); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 248 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (1)].listExp); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 251 "wig.y"
    { (yyval.listExp) = new ast::List((yyvsp[(1) - (1)].base)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 253 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].base)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 256 "wig.y"
    { (yyval.base) = new ast::Function((yyvsp[(1) - (6)].typeExp), *(yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].argList), (yyvsp[(6) - (6)].compoundStm)); delete((yyvsp[(2) - (6)].str)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 259 "wig.y"
    { (yyval.argList) = new std::list<ast::Argument*>; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 261 "wig.y"
    { (yyval.argList) = (yyvsp[(1) - (1)].argList); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 264 "wig.y"
    { (yyval.argList) = new std::list<ast::Argument*>{(yyvsp[(1) - (1)].argExp)}; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 266 "wig.y"
    { (yyvsp[(1) - (3)].argList)->push_back((yyvsp[(3) - (3)].argExp)); (yyval.argList) = (yyvsp[(1) - (3)].argList); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 269 "wig.y"
    { (yyval.argExp) = new ast::Argument((yyvsp[(1) - (2)].typeExp), *(yyvsp[(2) - (2)].str)); delete((yyvsp[(2) - (2)].str)); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 272 "wig.y"
    { (yyval.compoundStm) = new ast::CompoundStm((yyvsp[(3) - (4)].stmList), (yyvsp[(2) - (4)].listExp)->getList()); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 274 "wig.y"
    { (yyval.compoundStm) = new ast::CompoundStm((yyvsp[(2) - (3)].stmList)); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 277 "wig.y"
    { (yyval.listExp) = new ast::List((yyvsp[(1) - (1)].base)); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 279 "wig.y"
    { (yyval.listExp) = (yyvsp[(1) - (2)].listExp); (yyvsp[(1) - (2)].listExp)->AddBack((yyvsp[(2) - (2)].base)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 282 "wig.y"
    { (yyval.base) = new ast::Session(*(yyvsp[(2) - (5)].str), (yyvsp[(5) - (5)].compoundStm)); delete((yyvsp[(2) - (5)].str)); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 285 "wig.y"
    { (yyval.stmList) = new std::list<ast::Stm *>{new ast::EmptyStm()}; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 287 "wig.y"
    { (yyval.stmList) = (yyvsp[(1) - (1)].stmList); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 290 "wig.y"
    { (yyval.stmList) = new std::list<ast::Stm *>{(yyvsp[(1) - (1)].stm)}; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 292 "wig.y"
    { (yyvsp[(1) - (2)].stmList)->push_back((yyvsp[(2) - (2)].stm)); (yyval.stmList) = (yyvsp[(1) - (2)].stmList); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 295 "wig.y"
    { (yyval.stm) = new ast::EmptyStm(true); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 297 "wig.y"
    { (yyval.stm) = new ast::ShowStm((yyvsp[(2) - (4)].docStm), (yyvsp[(3) - (4)].stm)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 299 "wig.y"
    { (yyval.stm) = new ast::ExitStm((yyvsp[(2) - (3)].docStm)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 301 "wig.y"
    { (yyval.stm) = new ast::ReturnStm(); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 303 "wig.y"
    { (yyval.stm) = new ast::ReturnStm((yyvsp[(2) - (3)].exp)); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 305 "wig.y"
    { (yyval.stm) = new ast::IfStm((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stm)); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 307 "wig.y"
    { (yyval.stm) = new ast::IfStm((yyvsp[(3) - (7)].exp), (yyvsp[(5) - (7)].stm), (yyvsp[(7) - (7)].stm)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 309 "wig.y"
    { (yyval.stm) = new ast::WhileStm((yyvsp[(3) - (5)].exp), (yyvsp[(5) - (5)].stm)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 311 "wig.y"
    { (yyval.stm) = (yyvsp[(1) - (1)].compoundStm); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 313 "wig.y"
    { (yyval.stm) = new ast::ExpStm((yyvsp[(1) - (2)].exp)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 316 "wig.y"
    { (yyval.docStm) = new ast::DocumentStm(*(yyvsp[(1) - (1)].str)); delete((yyvsp[(1) - (1)].str)); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 318 "wig.y"
    { (yyval.docStm) = new ast::DocumentStm(*(yyvsp[(2) - (5)].str), true, (yyvsp[(4) - (5)].plugList)); delete((yyvsp[(2) - (5)].str)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 321 "wig.y"
    { (yyval.plugList) = new std::list<ast::PlugStm *>{(yyvsp[(1) - (1)].plugStm)}; }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 323 "wig.y"
    { (yyvsp[(1) - (3)].plugList)->push_back((yyvsp[(3) - (3)].plugStm)); (yyval.plugList) = (yyvsp[(1) - (3)].plugList); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 326 "wig.y"
    { (yyval.plugStm) = new ast::PlugStm(*(yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].exp)); delete((yyvsp[(1) - (3)].str)); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 329 "wig.y"
    { (yyval.stm) = new ast::EmptyStm(); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 331 "wig.y"
    { (yyval.stm) = new ast::ReceiveStm((yyvsp[(3) - (4)].stmList)); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 334 "wig.y"
    { (yyval.exp) = new ast::LValExp(*(yyvsp[(1) - (1)].str)); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 336 "wig.y"
    { (yyval.exp) = new ast::BinopExp(new ast::LValExp(*(yyvsp[(1) - (3)].str)),
                             ast::kBinopType::Assignment,
                             (yyvsp[(3) - (3)].exp)); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 340 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Equals, (yyvsp[(3) - (3)].exp)); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 342 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::NotEquals, (yyvsp[(3) - (3)].exp)); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 344 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::LowerThan, (yyvsp[(3) - (3)].exp)); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 346 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::HigherThan, (yyvsp[(3) - (3)].exp)); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 348 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::LowerEquals, (yyvsp[(3) - (3)].exp)); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 350 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::HigherEquals, (yyvsp[(3) - (3)].exp)); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 352 "wig.y"
    { (yyval.exp) = new ast::UnopExp(ast::kUnopType::Minus, (yyvsp[(2) - (2)].exp)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 354 "wig.y"
    { (yyval.exp) = new ast::UnopExp(ast::kUnopType::LogicNegate, (yyvsp[(2) - (2)].exp)); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 356 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Add, (yyvsp[(3) - (3)].exp)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 358 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Sub, (yyvsp[(3) - (3)].exp)); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 360 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Mult, (yyvsp[(3) - (3)].exp)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 362 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Div, (yyvsp[(3) - (3)].exp)); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 364 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Mod, (yyvsp[(3) - (3)].exp)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 366 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::And, (yyvsp[(3) - (3)].exp)); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 368 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Or, (yyvsp[(3) - (3)].exp)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 370 "wig.y"
    { (yyval.exp) = new ast::BinopExp((yyvsp[(1) - (3)].exp), ast::kBinopType::Combine, (yyvsp[(3) - (3)].exp)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 372 "wig.y"
    { (yyval.exp) = new ast::TupleopExp((yyvsp[(1) - (3)].exp),
                               ast::kTupleopType::Keep,
                               new std::list<std::string>{*(yyvsp[(3) - (3)].str)}); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 376 "wig.y"
    { (yyval.exp) = new ast::TupleopExp((yyvsp[(1) - (5)].exp), ast::kTupleopType::Keep, (yyvsp[(4) - (5)].strList)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 378 "wig.y"
    { (yyval.exp) = new ast::TupleopExp((yyvsp[(1) - (3)].exp), ast::kTupleopType::Discard,
                                   new std::list<std::string>{*(yyvsp[(3) - (3)].str)}); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 381 "wig.y"
    { (yyval.exp) = new ast::TupleopExp((yyvsp[(1) - (5)].exp), ast::kTupleopType::Discard, (yyvsp[(4) - (5)].strList)); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 383 "wig.y"
    { (yyval.exp) = new ast::FunctionExp(*(yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].expList)); delete((yyvsp[(1) - (4)].str)); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 385 "wig.y"
    { (yyval.exp) = new ast::IntegerExp((yyvsp[(1) - (1)].integer)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 387 "wig.y"
    { (yyval.exp) = new ast::TrueExp(); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 389 "wig.y"
    { (yyval.exp) = new ast::FalseExp(); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 391 "wig.y"
    { (yyval.exp) = new ast::StringExp(*(yyvsp[(1) - (1)].str)); delete((yyvsp[(1) - (1)].str)); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 393 "wig.y"
    { (yyval.exp) = new ast::TupleExp((yyvsp[(3) - (4)].expList)); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 395 "wig.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 398 "wig.y"
    { (yyval.expList) = new std::list<ast::Exp *>{new ast::Exp()}; }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 400 "wig.y"
    { (yyval.expList) = (yyvsp[(1) - (1)].expList); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 403 "wig.y"
    { (yyval.expList) = new std::list<ast::Exp *>{(yyvsp[(1) - (1)].exp)}; }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 405 "wig.y"
    { (yyvsp[(1) - (3)].expList)->push_back((yyvsp[(3) - (3)].exp)); (yyval.expList) = (yyvsp[(1) - (3)].expList); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 408 "wig.y"
    { (yyval.exp) = new ast::FieldValExp(*(yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].exp)); delete((yyvsp[(1) - (3)].str)); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 411 "wig.y"
    { (yyval.expList) = new std::list<ast::Exp *>{new ast::Exp()}; }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 413 "wig.y"
    { (yyval.expList) = (yyvsp[(1) - (1)].expList); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 416 "wig.y"
    { (yyval.expList) = new std::list<ast::Exp *>{(yyvsp[(1) - (1)].exp)}; }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 418 "wig.y"
    { (yyvsp[(1) - (3)].expList)->push_back((yyvsp[(3) - (3)].exp)); (yyval.expList) = (yyvsp[(1) - (3)].expList); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 421 "wig.y"
    { (yyval.stmList) = new std::list<ast::Stm *>{new ast::EmptyStm()}; }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 423 "wig.y"
    { (yyval.stmList) = (yyvsp[(1) - (1)].stmList); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 426 "wig.y"
    { (yyval.stmList) = new std::list<ast::Stm *>{(yyvsp[(1) - (1)].stm)}; }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 428 "wig.y"
    { (yyvsp[(1) - (3)].stmList)->push_back((yyvsp[(3) - (3)].stm)); (yyval.stmList) = (yyvsp[(1) - (3)].stmList); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 431 "wig.y"
    { (yyval.stm) = new ast::InputStm(*(yyvsp[(1) - (3)].str), *(yyvsp[(3) - (3)].str)); delete((yyvsp[(1) - (3)].str)); delete((yyvsp[(3) - (3)].str)); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 434 "wig.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 436 "wig.y"
    { (yyval.str) = new std::string(*(yyvsp[(1) - (3)].str)+"."+*(yyvsp[(3) - (3)].str)); delete((yyvsp[(1) - (3)].str)); delete((yyvsp[(3) - (3)].str)); }
    break;


/* Line 1787 of yacc.c  */
#line 2565 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


