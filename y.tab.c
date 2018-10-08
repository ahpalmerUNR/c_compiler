/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO_tok = 258,
    BREAK_tok = 259,
    CASE_tok = 260,
    CHAR_tok = 261,
    CONST_tok = 262,
    CONTINUE_tok = 263,
    DEFAULT_tok = 264,
    DO_tok = 265,
    DOUBLE_tok = 266,
    ELSE_tok = 267,
    ENUM_tok = 268,
    EXTERN_tok = 269,
    FLOAT_tok = 270,
    FOR_tok = 271,
    GOTO_tok = 272,
    IF_tok = 273,
    INT_tok = 274,
    LONG_tok = 275,
    REGISTER_tok = 276,
    RETURN_tok = 277,
    SHORT_tok = 278,
    SIGNED_tok = 279,
    SIZEOF_tok = 280,
    STATIC_tok = 281,
    STRUCT_tok = 282,
    SWITCH_tok = 283,
    TYPEDEF_tok = 284,
    UNION_tok = 285,
    UNSIGNED_tok = 286,
    VOID_tok = 287,
    VOLATILE_tok = 288,
    WHILE_tok = 289,
    ERROR_tok = 290,
    ID_tok = 291,
    PLUS_tok = 292,
    MINUS_tok = 293,
    STAR_tok = 294,
    SEMI_tok = 295,
    OPEN_BRACKET_tok = 296,
    CLOSE_BRACKET_tok = 297,
    EQUAL_tok = 298,
    COLON_tok = 299,
    COMMA_tok = 300,
    OPEN_PAREN_tok = 301,
    CLOSE_PAREN_tok = 302,
    OPEN_BRACE_tok = 303,
    CLOSE_BRACE_tok = 304,
    QUESTION_MARK_tok = 305,
    BAR_tok = 306,
    CARET_tok = 307,
    AMP_tok = 308,
    GT_tok = 309,
    LT_tok = 310,
    PERCENT_tok = 311,
    TILDA_tok = 312,
    NOT_tok = 313,
    INC_OP_tok = 314,
    DEC_OP_tok = 315,
    INTEGER_CONSTANT_tok = 316,
    FLOATING_CONSTANT_tok = 317,
    CHARACTER_CONSTANT_tok = 318,
    ENUMERATION_CONSTANT_tok = 319,
    STRING_LITERAL_tok = 320,
    PTR_OP_tok = 321,
    LEFT_OP_tok = 322,
    RIGHT_OP_tok = 323,
    LE_OP_tok = 324,
    GE_OP_tok = 325,
    EQ_OP_tok = 326,
    NE_OP_tok = 327,
    AND_OP_tok = 328,
    OR_OP_tok = 329,
    MULT_ASSIGN_tok = 330,
    DIV_ASSIGN_tok = 331,
    MOD_ASSIGN_tok = 332,
    ADD_ASSIGN_tok = 333,
    SUB_ASSIGN_tok = 334,
    LEFT_ASSIGN_tok = 335,
    RIGHT_ASSIGN_tok = 336,
    AND_ASSIGN_tok = 337,
    XOR_ASSIGN_tok = 338,
    OR_ASSIGN_tok = 339,
    TYPEDEF_NAME_tok = 340,
    ELIPSIS_tok = 341,
    DIV_tok = 342,
    PERIOD_tok = 343
  };
#endif
/* Tokens.  */
#define AUTO_tok 258
#define BREAK_tok 259
#define CASE_tok 260
#define CHAR_tok 261
#define CONST_tok 262
#define CONTINUE_tok 263
#define DEFAULT_tok 264
#define DO_tok 265
#define DOUBLE_tok 266
#define ELSE_tok 267
#define ENUM_tok 268
#define EXTERN_tok 269
#define FLOAT_tok 270
#define FOR_tok 271
#define GOTO_tok 272
#define IF_tok 273
#define INT_tok 274
#define LONG_tok 275
#define REGISTER_tok 276
#define RETURN_tok 277
#define SHORT_tok 278
#define SIGNED_tok 279
#define SIZEOF_tok 280
#define STATIC_tok 281
#define STRUCT_tok 282
#define SWITCH_tok 283
#define TYPEDEF_tok 284
#define UNION_tok 285
#define UNSIGNED_tok 286
#define VOID_tok 287
#define VOLATILE_tok 288
#define WHILE_tok 289
#define ERROR_tok 290
#define ID_tok 291
#define PLUS_tok 292
#define MINUS_tok 293
#define STAR_tok 294
#define SEMI_tok 295
#define OPEN_BRACKET_tok 296
#define CLOSE_BRACKET_tok 297
#define EQUAL_tok 298
#define COLON_tok 299
#define COMMA_tok 300
#define OPEN_PAREN_tok 301
#define CLOSE_PAREN_tok 302
#define OPEN_BRACE_tok 303
#define CLOSE_BRACE_tok 304
#define QUESTION_MARK_tok 305
#define BAR_tok 306
#define CARET_tok 307
#define AMP_tok 308
#define GT_tok 309
#define LT_tok 310
#define PERCENT_tok 311
#define TILDA_tok 312
#define NOT_tok 313
#define INC_OP_tok 314
#define DEC_OP_tok 315
#define INTEGER_CONSTANT_tok 316
#define FLOATING_CONSTANT_tok 317
#define CHARACTER_CONSTANT_tok 318
#define ENUMERATION_CONSTANT_tok 319
#define STRING_LITERAL_tok 320
#define PTR_OP_tok 321
#define LEFT_OP_tok 322
#define RIGHT_OP_tok 323
#define LE_OP_tok 324
#define GE_OP_tok 325
#define EQ_OP_tok 326
#define NE_OP_tok 327
#define AND_OP_tok 328
#define OR_OP_tok 329
#define MULT_ASSIGN_tok 330
#define DIV_ASSIGN_tok 331
#define MOD_ASSIGN_tok 332
#define ADD_ASSIGN_tok 333
#define SUB_ASSIGN_tok 334
#define LEFT_ASSIGN_tok 335
#define RIGHT_ASSIGN_tok 336
#define AND_ASSIGN_tok 337
#define XOR_ASSIGN_tok 338
#define OR_ASSIGN_tok 339
#define TYPEDEF_NAME_tok 340
#define ELIPSIS_tok 341
#define DIV_tok 342
#define PERIOD_tok 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 294 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  364

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,   100,   101,   105,   106,   107,   108,
     112,   113,   116,   117,   121,   122,   123,   124,   125,   126,
     130,   131,   132,   133,   134,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   153,   154,   158,
     159,   160,   164,   165,   169,   170,   174,   175,   179,   180,
     184,   188,   189,   190,   191,   195,   196,   200,   201,   202,
     222,   223,   227,   228,   229,   230,   231,   232,   233,   237,
     238,   239,   240,   244,   245,   249,   250,   254,   255,   259,
     260,   261,   265,   266,   270,   271,   272,   276,   277,   281,
     282,   286,   287,   288,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   304,   305,   306,   307,   308,   309,   313,
     314,   315,   319,   320,   324,   325,   326,   327,   331,   332,
     336,   337,   338,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   355,   356,   357,   358,   359,   363,   364,
     368,   369,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   387,   388,   392,   396,   397,   401,   402,
     406,   407,   411,   412,   416,   417,   421,   422,   423,   427,
     428,   429,   430,   431,   435,   436,   437,   441,   442,   443,
     447,   448,   449,   450,   454,   455,   459,   460,   461,   462,
     463,   464,   468,   469,   470,   471,   472,   473,   477,   478,
     479,   480,   481,   482,   483,   484,   488,   489,   490,   491,
     495,   496,   500,   501,   502,   503,   507,   511
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO_tok", "BREAK_tok", "CASE_tok",
  "CHAR_tok", "CONST_tok", "CONTINUE_tok", "DEFAULT_tok", "DO_tok",
  "DOUBLE_tok", "ELSE_tok", "ENUM_tok", "EXTERN_tok", "FLOAT_tok",
  "FOR_tok", "GOTO_tok", "IF_tok", "INT_tok", "LONG_tok", "REGISTER_tok",
  "RETURN_tok", "SHORT_tok", "SIGNED_tok", "SIZEOF_tok", "STATIC_tok",
  "STRUCT_tok", "SWITCH_tok", "TYPEDEF_tok", "UNION_tok", "UNSIGNED_tok",
  "VOID_tok", "VOLATILE_tok", "WHILE_tok", "ERROR_tok", "ID_tok",
  "PLUS_tok", "MINUS_tok", "STAR_tok", "SEMI_tok", "OPEN_BRACKET_tok",
  "CLOSE_BRACKET_tok", "EQUAL_tok", "COLON_tok", "COMMA_tok",
  "OPEN_PAREN_tok", "CLOSE_PAREN_tok", "OPEN_BRACE_tok", "CLOSE_BRACE_tok",
  "QUESTION_MARK_tok", "BAR_tok", "CARET_tok", "AMP_tok", "GT_tok",
  "LT_tok", "PERCENT_tok", "TILDA_tok", "NOT_tok", "INC_OP_tok",
  "DEC_OP_tok", "INTEGER_CONSTANT_tok", "FLOATING_CONSTANT_tok",
  "CHARACTER_CONSTANT_tok", "ENUMERATION_CONSTANT_tok",
  "STRING_LITERAL_tok", "PTR_OP_tok", "LEFT_OP_tok", "RIGHT_OP_tok",
  "LE_OP_tok", "GE_OP_tok", "EQ_OP_tok", "NE_OP_tok", "AND_OP_tok",
  "OR_OP_tok", "MULT_ASSIGN_tok", "DIV_ASSIGN_tok", "MOD_ASSIGN_tok",
  "ADD_ASSIGN_tok", "SUB_ASSIGN_tok", "LEFT_ASSIGN_tok",
  "RIGHT_ASSIGN_tok", "AND_ASSIGN_tok", "XOR_ASSIGN_tok", "OR_ASSIGN_tok",
  "TYPEDEF_NAME_tok", "ELIPSIS_tok", "DIV_tok", "PERIOD_tok", "$accept",
  "translation_unit", "external_declaration", "function_definition",
  "declaration", "declaration_list", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "expression_statement", "compound_statement",
  "statement_list", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "constant_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "unary_operator", "postfix_expression",
  "primary_expression", "argument_expression_list", "constant", "string",
  "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     756,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,    77,   -20,  -178,   415,  -178,  -178,  -178,    87,   495,
     495,   495,  -178,   -23,   867,    14,    22,  -178,  -178,  -178,
      77,   -29,  -178,  -178,  -178,    54,  -178,   790,  -178,  -178,
    -178,   352,   -25,   536,  -178,   867,    87,  -178,  1205,   829,
      14,  -178,  -178,  -178,  -178,   -20,  1235,   867,  -178,   352,
     352,   284,  -178,    99,   352,    17,  1595,    42,    53,  1145,
     118,   110,   132,  1265,  1625,   140,   187,  -178,  -178,  -178,
    -178,   931,  -178,  -178,  -178,  -178,  1655,  1655,  -178,  -178,
    -178,  -178,  -178,   609,  -178,  -178,  -178,  -178,  1021,  -178,
    -178,  -178,    89,  -178,  -178,    39,   166,   198,   205,   209,
      81,     7,   212,    34,   -12,  -178,   114,  1595,     4,  -178,
    -178,  -178,   223,  -178,  -178,   227,  -178,  -178,   232,  -178,
    -178,  -178,   108,   229,   237,  -178,    -4,  -178,  -178,  1235,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  1595,   123,  -178,
     245,   991,  -178,   248,  -178,  1145,   262,  1295,   258,  1595,
    -178,   131,   931,  -178,  1595,  1595,    76,   255,    83,  1595,
    -178,  -178,  -178,  1083,  -178,  -178,  -178,  1595,  1595,  1595,
    1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,  1595,
    1595,  1595,  1595,  1595,  1595,  1595,  1595,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  1595,  -178,
    1595,  1325,  -178,  -178,   110,   110,  1145,  -178,  1355,   672,
    -178,   120,  -178,   138,  -178,   452,   110,  -178,  -178,    62,
    -178,  -178,    99,  1595,  -178,  1145,  -178,   260,  1385,   159,
    -178,   130,  -178,   273,   162,   170,   709,   160,  -178,  1595,
    -178,  -178,  -178,   241,   166,   198,   205,   209,    81,     7,
       7,   212,   212,   212,   212,    34,    34,   -12,   -12,  -178,
    -178,  -178,  -178,    95,  -178,  -178,   171,  -178,  -178,  -178,
    -178,   267,  -178,   274,   275,   138,  1415,   898,  -178,  -178,
    -178,  1175,  -178,  -178,  -178,  -178,  1595,  1445,   163,  1475,
    1145,  -178,  1145,  1145,  -178,  1595,  -178,  1595,  -178,  -178,
    -178,  -178,  -178,   281,  -178,   278,  -178,  -178,   174,  1145,
     175,  1505,  1535,   165,   314,  -178,  -178,  -178,  -178,  -178,
    -178,   287,  -178,  1145,  1145,   201,  1145,   211,  1565,  1145,
    -178,  -178,  -178,  1145,  -178,  1145,  1145,   216,  -178,  -178,
    -178,  -178,  1145,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    26,    37,    31,    35,    23,    30,    28,    29,
      21,    27,    32,    22,    42,    24,    43,    33,    25,    38,
     217,    69,     0,    36,     0,     2,     4,     5,     0,    14,
      16,    18,    34,     0,     0,    60,     0,    62,    73,    71,
      70,     0,     1,     3,    10,     0,    46,    48,    15,    17,
      19,     0,    41,     0,    12,     0,     0,     6,     0,     0,
      61,    74,    72,    63,    11,     0,     0,     0,     8,    51,
      53,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,   193,
     112,     0,   114,   192,   196,   197,     0,     0,   212,   214,
     213,   215,   216,     0,   118,   103,   105,   104,     0,   106,
     107,   108,     0,   138,   140,   153,   156,   158,   160,   162,
     164,   166,   169,   174,   177,   180,   184,     0,   186,   198,
     207,   208,   206,    13,     7,    48,    64,   155,     0,   184,
     206,    66,    80,     0,    75,    77,     0,    82,    47,     0,
      49,    84,     9,    52,    54,    40,    45,     0,     0,    55,
      57,     0,   135,     0,   134,     0,     0,     0,     0,     0,
     136,     0,     0,   190,     0,     0,    89,     0,     0,     0,
     187,   188,   116,     0,   115,   119,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   189,
       0,     0,   204,   205,     0,     0,     0,    65,     0,     0,
      79,    91,    81,    92,    67,     0,     0,    68,    87,     0,
      58,    50,     0,     0,    39,     0,   111,     0,     0,     0,
     133,     0,   137,     0,     0,     0,     0,    91,    90,     0,
     209,   117,   139,     0,   157,   159,   161,   163,   165,   167,
     168,   171,   170,   172,   173,   175,   176,   178,   179,   181,
     183,   182,   141,     0,   200,   210,     0,   203,   202,   109,
      95,     0,    99,     0,     0,    93,     0,     0,    76,    78,
      83,     0,    85,    56,    59,   110,     0,     0,     0,     0,
       0,   191,     0,     0,   185,     0,   199,     0,   201,    96,
     100,    94,    97,     0,   101,     0,    86,    88,     0,     0,
       0,     0,     0,     0,   120,   122,   123,   154,   211,    98,
     102,     0,   125,     0,     0,     0,     0,     0,     0,     0,
     124,   126,   127,     0,   129,     0,     0,     0,   121,   128,
     130,   131,     0,   132
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,   304,  -178,    11,    78,     8,  -178,   -22,   111,
    -178,  -178,   256,  -178,   266,   -57,   -60,  -178,    90,    18,
     -31,    -6,  -178,   -53,  -178,   101,  -178,  -142,  -178,   167,
    -125,  -177,   -78,  -178,  -178,    51,   231,  -178,  -178,  -178,
     -79,   -63,  -178,   -56,   -55,  -178,   146,   147,   149,   150,
     145,    93,    15,   100,   116,   -85,   197,  -178,  -178,  -178,
    -178,  -178,  -178,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    54,    55,    56,    29,    30,    31,
      32,    33,    71,    45,    46,    72,    73,   158,   159,    34,
      35,    36,    40,   293,   144,   145,   146,   150,   239,   177,
     294,   233,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   218,   114,   138,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     286,   130,   131,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      37,   166,   137,   151,   171,    60,   143,   238,    28,   153,
     154,    27,   178,    20,   156,    39,    20,   232,    63,    21,
     137,   163,    37,    74,    37,    51,    22,   204,    37,    69,
     185,   176,    28,    52,    62,    27,    37,    48,    49,    50,
      41,   236,   219,   237,   205,   220,    47,    69,    69,    69,
     221,   258,    69,   132,   295,    58,    37,   162,    20,   147,
      59,   196,   197,   222,   223,    37,   133,   142,    22,    69,
     224,   202,   203,    37,   135,   206,   198,   199,   133,   132,
     295,   168,   164,   135,     3,    57,   151,   246,   249,   188,
     251,   160,   225,   178,    64,   254,   255,   165,    68,    65,
     178,   137,   240,   132,   156,   185,   134,   301,   132,   263,
      19,   302,   176,   189,   133,    21,    21,   228,   152,   279,
     280,   281,   256,    20,   262,    67,    21,    44,   187,   186,
     260,   103,    38,    22,   187,    20,   231,   316,    21,    69,
     187,   283,    37,   157,    20,    22,    20,    21,   289,   228,
      69,    61,   194,   195,   229,   282,    20,   207,   285,   327,
     230,   228,    70,   241,   167,   132,   229,   305,   242,   308,
     257,   252,   137,   291,   314,   187,   187,   310,   169,   296,
      70,    70,    70,   132,   297,    70,   174,   137,   304,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   309,
      60,   228,    70,   331,   187,   348,   256,   187,   187,   312,
     187,   271,   272,   273,   274,   187,   317,   313,   318,   187,
     187,   341,   343,   231,   287,   288,   132,   328,   330,    37,
     333,    37,   334,   175,   335,   336,   300,   142,   151,   190,
     137,   323,    37,   142,   325,   132,   187,    41,   353,   191,
     257,   342,   345,   347,   338,   139,   187,   192,   355,   337,
     160,   187,   193,   362,   142,   351,   352,   226,   354,   357,
      66,   358,    70,   139,   227,   359,   234,   360,   361,   200,
     201,   173,   235,    70,   363,   315,   187,   269,   270,   243,
       2,     3,   245,   180,   181,     4,   247,     5,   250,     7,
     275,   276,   259,     8,     9,   142,   306,    11,    12,   319,
     132,    14,   132,   132,    16,    17,    18,    19,   277,   278,
     311,   320,   321,   339,   139,   340,   349,   350,    43,   132,
     161,   148,   303,   155,   183,   264,   299,   265,   268,   253,
     266,     0,   267,   132,   132,     0,   132,     0,     0,   132,
       0,     0,     0,   132,   139,   132,   132,     0,     2,     3,
       0,     0,   132,     4,     0,     5,     0,     7,     0,    23,
       0,     8,     9,     0,     0,    11,    12,     0,     0,    14,
       0,     0,    16,    17,    18,    19,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     1,     0,
       0,     2,     3,     0,     0,   139,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    23,    11,    12,
     139,    13,    14,     0,    15,    16,    17,    18,    19,     0,
       0,    20,     0,     0,    21,     1,   139,     0,     2,     3,
       0,    22,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,     0,    11,    12,     0,    13,    14,
       0,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     1,     0,
      23,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,   139,     0,     8,     9,    10,     0,    11,    12,
       0,    13,    14,     0,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    23,   298,     1,
      75,    76,     2,     3,    77,    78,    79,     4,     0,     5,
       6,     7,    80,    81,    82,     8,     9,    10,    83,    11,
      12,    84,    13,    14,    85,    15,    16,    17,    18,    19,
      86,     0,    20,    87,    88,    89,    90,     0,     0,     0,
      23,     0,    91,     0,    53,    92,     0,     0,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    75,    76,     2,     3,    77,    78,    79,
       4,    23,     5,     6,     7,    80,    81,    82,     8,     9,
      10,    83,    11,    12,    84,    13,    14,    85,    15,    16,
      17,    18,    19,    86,     0,    20,    87,    88,    89,    90,
       0,     0,     0,     0,     0,    91,     0,    53,   182,     0,
       0,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    23,    11,    12,     0,    13,    14,
       0,    15,    16,    17,    18,    19,     0,     0,    20,     0,
       0,    21,     1,   228,     0,     2,     3,     0,   229,   292,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,     0,    11,    12,     0,    13,    14,     0,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    21,     0,
     228,     0,     0,     0,     0,   256,   292,    23,     0,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,     0,    11,
      12,     0,    13,    14,     0,    15,    16,    17,    18,    19,
       0,     0,    20,     1,    23,    21,     2,     3,     0,     0,
       0,     4,    22,     5,     6,     7,     0,     0,     0,     8,
       9,    10,     0,    11,    12,     0,    13,    14,     0,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    66,     0,     2,     3,     0,    53,     0,
       4,    23,     5,     6,     7,     0,     0,     0,     8,     9,
      10,     0,    11,    12,     0,    13,    14,     0,    15,    16,
      17,    18,    19,     0,     0,    20,     0,     0,     0,     0,
       1,     0,     0,     2,     3,    23,   141,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,     0,
      11,    12,     0,    13,    14,     0,    15,    16,    17,    18,
      19,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,    23,    53,     0,     8,     9,    10,
       0,    11,    12,     0,    13,    14,     0,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,   324,     7,     0,     0,     0,
       8,     9,    23,     0,    11,    12,    84,     0,    14,     0,
       0,    16,    17,    18,    19,     0,     0,    20,    87,    88,
      89,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,    23,    93,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       8,     9,     0,     0,    11,    12,    23,     0,    14,     0,
       0,    16,    17,    18,    19,    75,    76,     0,     0,    77,
      78,    79,     0,     0,     0,     0,     0,    80,    81,    82,
     244,     0,     0,    83,     0,     0,    84,     0,     0,    85,
       0,     0,     0,     0,     0,    86,     0,    20,    87,    88,
      89,    90,     0,     0,     0,     0,     0,    91,     0,    53,
     184,     0,     0,     0,    93,     0,    23,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    75,    76,     0,
       0,    77,    78,    79,     0,     0,     0,     0,     0,    80,
      81,    82,     0,     0,     0,    83,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,    86,     0,    20,
      87,    88,    89,    90,     0,     0,     0,     0,     0,    91,
       0,    53,   261,     0,     0,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    75,
      76,     0,     0,    77,    78,    79,     0,     0,     0,     0,
       0,    80,    81,    82,     0,     0,     0,    83,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,    86,
       0,    20,    87,    88,    89,    90,     0,     0,     0,     0,
       0,    91,     0,    53,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,     0,   149,   326,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,   136,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,     0,   149,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,   170,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,   248,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,   284,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,   290,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,   307,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,   322,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,   329,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,   332,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,   344,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,   346,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,   356,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,    93,     0,
      84,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    20,    87,    88,    89,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102
};

static const yytype_int16 yycheck[] =
{
       0,    79,    58,    66,    83,    36,    59,   149,     0,    69,
      70,     0,    91,    36,    71,    21,    36,   142,    47,    39,
      76,    76,    22,    48,    24,    48,    46,    39,    28,    51,
     108,    91,    24,    33,    40,    24,    36,    29,    30,    31,
      22,    45,   127,    47,    56,    41,    28,    69,    70,    71,
      46,   176,    74,    53,   231,    41,    56,    40,    36,    59,
      46,    54,    55,    59,    60,    65,    55,    59,    46,    91,
      66,    37,    38,    73,    56,    87,    69,    70,    67,    79,
     257,    81,    40,    65,     7,    34,   149,   165,   167,    50,
     169,    73,    88,   172,    40,   174,   175,    44,    47,    45,
     179,   157,   157,   103,   161,   183,    55,    45,   108,   188,
      33,    49,   172,    74,   103,    39,    39,    41,    67,   204,
     205,   206,    46,    36,   187,    47,    39,    40,    45,    40,
      47,    53,    21,    46,    45,    36,   142,    42,    39,   161,
      45,   220,   142,    44,    36,    46,    36,    39,   226,    41,
     172,    40,    71,    72,    46,   218,    36,    43,   221,   301,
     142,    41,    51,    40,    46,   165,    46,   245,    45,   248,
     176,    40,   228,   228,   259,    45,    45,    47,    46,    41,
      69,    70,    71,   183,    46,    74,    46,   243,   243,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    40,
     231,    41,    91,    40,    45,    40,    46,    45,    45,    47,
      45,   196,   197,   198,   199,    45,    45,    47,    47,    45,
      45,    47,    47,   229,   224,   225,   226,   306,   307,   229,
     309,   231,   310,    46,   312,   313,   236,   229,   301,    73,
     296,   296,   242,   235,   297,   245,    45,   229,    47,    51,
     256,   329,   331,   332,   317,    58,    45,    52,    47,   315,
     242,    45,    53,    47,   256,   343,   344,    44,   346,   348,
      43,   349,   161,    76,    42,   353,    47,   355,   356,    67,
      68,    84,    45,   172,   362,    44,    45,   194,   195,    44,
       6,     7,    44,    96,    97,    11,    34,    13,    40,    15,
     200,   201,    47,    19,    20,   297,    46,    23,    24,    42,
     310,    27,   312,   313,    30,    31,    32,    33,   202,   203,
      47,    47,    47,    42,   127,    47,    12,    40,    24,   329,
      74,    65,   242,    49,   103,   189,   235,   190,   193,   172,
     191,    -1,   192,   343,   344,    -1,   346,    -1,    -1,   349,
      -1,    -1,    -1,   353,   157,   355,   356,    -1,     6,     7,
      -1,    -1,   362,    11,    -1,    13,    -1,    15,    -1,    85,
      -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,    -1,
      -1,     6,     7,    -1,    -1,   228,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    85,    23,    24,
     243,    26,    27,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    36,    -1,    -1,    39,     3,   259,    -1,     6,     7,
      -1,    46,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,     3,    -1,
      85,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,   315,    -1,    19,    20,    21,    -1,    23,    24,
      -1,    26,    27,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      85,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    85,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    85,    23,    24,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      -1,    39,     3,    41,    -1,     6,     7,    -1,    46,    47,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,    24,    -1,    26,    27,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    85,    -1,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,    23,
      24,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    36,     3,    85,    39,     6,     7,    -1,    -1,
      -1,    11,    46,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    -1,    23,    24,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    43,    -1,     6,     7,    -1,    48,    -1,
      11,    85,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,    24,    -1,    26,    27,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,    85,    47,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    85,    48,    -1,    19,    20,    21,
      -1,    23,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    47,    15,    -1,    -1,    -1,
      19,    20,    85,    -1,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    85,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    24,    85,    -1,    27,    -1,
      -1,    30,    31,    32,    33,     4,     5,    -1,    -1,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      49,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,
      49,    -1,    -1,    -1,    53,    -1,    85,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     4,
       5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      25,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    23,    24,    26,    27,    29,    30,    31,    32,    33,
      36,    39,    46,    85,    90,    91,    92,    93,    95,    96,
      97,    98,    99,   100,   108,   109,   110,   152,    98,   110,
     111,   108,     0,    91,    40,   102,   103,   108,    95,    95,
      95,    48,   152,    48,    93,    94,    95,   124,    41,    46,
     109,    98,   110,    47,    40,    45,    43,    94,   124,    97,
      98,   101,   104,   105,    48,     4,     5,     8,     9,    10,
      16,    17,    18,    22,    25,    28,    34,    37,    38,    39,
      40,    46,    49,    53,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    94,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   132,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     150,   151,   152,    93,   124,   108,    42,   132,   133,   145,
     152,    47,    95,   112,   113,   114,   115,   152,   103,    48,
     116,   130,   124,   105,   105,    49,   104,    44,   106,   107,
     108,   101,    40,   133,    40,    44,   121,    46,   152,    46,
      40,   129,    46,   145,    46,    46,   105,   118,   129,    46,
     145,   145,    49,   125,    49,   121,    40,    45,    50,    74,
      73,    51,    52,    53,    71,    72,    54,    55,    69,    70,
      67,    68,    37,    38,    39,    56,    87,    43,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   131,   144,
      41,    46,    59,    60,    66,    88,    44,    42,    41,    46,
     108,   110,   119,   120,    47,    45,    45,    47,   116,   117,
     133,    40,    45,    44,    49,    44,   121,    34,    40,   129,
      40,   129,    40,   118,   129,   129,    46,   110,   119,    47,
      47,    49,   130,   129,   135,   136,   137,   138,   139,   140,
     140,   141,   141,   141,   141,   142,   142,   143,   143,   144,
     144,   144,   130,   129,    47,   130,   149,   152,   152,   121,
      42,   133,    47,   112,   119,   120,    41,    46,    86,   114,
     152,    45,    49,   107,   133,   121,    46,    40,   129,    40,
      47,    47,    47,    47,   144,    44,    42,    45,    47,    42,
      47,    47,    42,   133,    47,   112,    49,   116,   129,    47,
     129,    40,    40,   129,   121,   121,   121,   132,   130,    42,
      47,    47,   121,    47,    47,   129,    47,   129,    40,    12,
      40,   121,   121,    47,   121,    47,    47,   129,   121,   121,
     121,   121,    47,   121
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    91,    91,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   132,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   142,
     143,   143,   143,   143,   144,   144,   145,   145,   145,   145,
     145,   145,   146,   146,   146,   146,   146,   146,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   150,   150,   150,   150,   151,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     3,     4,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       3,     1,     2,     1,     2,     1,     3,     1,     2,     3,
       1,     2,     1,     3,     3,     4,     3,     4,     4,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       1,     2,     1,     3,     1,     3,     4,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1,     2,     2,     3,     3,     4,     1,     2,
       5,     7,     5,     5,     7,     6,     7,     7,     8,     7,
       8,     8,     9,     3,     2,     2,     2,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
#line 1941 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 513 "c_compiler.y" /* yacc.c:1906  */


#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
