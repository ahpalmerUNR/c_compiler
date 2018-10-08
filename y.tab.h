/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
