
/************************************************************************/
/*                                                                      */
/* FILE    : c_compiler.lex                                             */
/* PURPOSE : to cause pain and suffering                                */
/*                                                                      */
/************************************************************************/

%{
#include <stdio.h>
#include "c_compiler_tokens.h"
%}

/************************************************************************/
/* Regular Definitions                                                  */
/************************************************************************/

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
int [-+]?{digit}+
id	{letter}|_({letter}|{digit}|_)*
float	[-+]?{digit}*\.?{digit}+([eE][+-]?[0-9]+)?
char {letters}+
%%
{ws}		{}
"auto"		{return(AUTO_tok);}
"break"		{return(BREAK_tok);}
"case"		{return(CASE_tok);}
"char"		{return(CHAR_tok);}
"const"		{return(CONST_tok);}
"continue"	{return(CONTINUE_tok);}
"default" 	{return(DEFAULT_tok);}
"do"		{return(DO_tok);}
"double"	{return(DOUBLE_tok);}
"else"		{return(ELSE_tok);}
"enum"		{return(ENUM_tok);}
"extern"	{return(EXTERN_tok);}
"float"		{return(FLOAT_tok);}
"for"		{return(FOR_tok);}
"goto"		{return(GOTO_tok);}
"if"		{return(IF_tok);}
"int"		{return(INT_tok);}
"long"		{return(LONG_tok);}
"register"	{return(REGISTER_tok);}
"return"	{return(RETURN_tok);}
"short"		{return(SHORT_tok);}
"signed"	{return(SIGNED_tok);}
"sizeof"	{return(SIZEOF_tok);}
"static"	{return(STATIC_tok);}
"struct"	{return(STRUCT_tok);}
"switch"	{return(SWITCH_tok);}
"typedef"	{return(TYPEDEF_tok);}
"union"		{return(UNION_tok);}
"unsigned"	{return(UNSIGNED_tok);}
"void"		{return(VOID_tok);}
"volatile"	{return(VOLATILE_tok);}
"while"		{return(WHILE_tok);}

"+"			{return(PLUS_tok);}
"-"			{return(MINUS_tok);}
"*"			{return(STAR_tok);}
";"			{return(SEMI_tok);}
"["			{return(OPEN_BRACKET_tok);}
"]"			{return(CLOSE_BRACKET_tok);}
"="			{return(EQUAL_tok);}
":"			{return(COLON_tok);}
","			{return(COMMA_tok);}
"("			{return(OPEN_PAREN_tok);}
")"			{return(CLOSE_PAREN_tok);}
"{"			{return(OPEN_BRACE_tok);}
"}"			{return(CLOSE_BRACE_tok);}

"?"			{return(QUESTION_MARK_tok);}
"|"			{return(BAR_tok);}
"^"			{return(CARROT_tok);}
"&"			{return(AMP_tok);}
"<"			{return(GT_tok);}
">"			{return(LT_tok);}
"%"			{return(PERCENT_tok);}

"~"			{return(TILDA_tok);}
"!"			{return(NOT_tok);}
"++"		{return(INC_OP_tok);}
"--"		{return(DEC_OP_tok);}

{int}		{return(INTEGER_CONSTANT_tok);}
{float}		{return(FLOATING_CONSTANT_tok);}


"<-"		{return(PTR_OP_tok);}
"<<"		{return(LEFT_OP_tok);}
">>"		{return(RIGHT_OP_tok);}
"<="		{return(LE_OP_tok);}
">="		{return(GE_OP_tok);}
"=="		{return(EQ_OP_tok);}
"!="		{return(NE_OP_tok);}

"&&"		{return(AND_OP_tok);}
"||"		{return(OR_OP_tok);}

"*="		{return(MULT_ASSIGN_tok);}
"/="		{return(DIV_ASSIGN_tok);}
"%="		{return(MOD_ASSIGN_tok);}
"+="		{return(ADD_ASSIGN_tok);}
"-="		{return(SUB_ASSIGN_tok);}
"<<="		{return(LEFT_ASSIGN_tok);}
">>="		{return(RIGHT_ASSIGN_tok);}
"&="		{return(AND_ASSIGN_tok);}
"^="		{return(XOR_ASSIGN_tok);}
"|="		{return(OR_ASSIGN_tok);}

"..."		{return(ELIPSIS_tok);}



%%
