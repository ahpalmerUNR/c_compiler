
/************************************************************************/
/*                                                                      */
/* FILE    : c_compiler.lex                                             */
/* PURPOSE : to cause pain and suffering                                */
/*                                                                      */
/************************************************************************/

%{
#include <stdio.h>
#include "c_compiler_tokens.h"
#include "symboltable.cpp"

extern int lex_debug_level;
extern int symbol_table_debug;
extern int yacc_debug_level;
%}

/************************************************************************/
/* Regular Definitions                                                  */
/************************************************************************/

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
int [-+]?{digit}+
id	({letter}|_+({letter}|{digit}))+({letter}|{digit}|_)*
float	[-+]?{digit}*\.?{digit}+([eE][+-]?[0-9]+)?
character 	\'([^\']|\\.*)\'
string		\"[^\"]*\"
line_comment	"//".*\n
mult_line_comment	"/*"([^*]|\*+[^*/])*"*/"


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

{id}		{return(ID_tok);}

"+"			{return(PLUS_tok);}
"-"			{return(MINUS_tok);}
"*"			{return(STAR_tok);}
"/"			{return(DIV_tok)}
";"			{return(SEMI_tok);}
"["			{return(OPEN_BRACKET_tok);}
"]"			{return(CLOSE_BRACKET_tok);}
"="			{return(EQUAL_tok);}
":"			{return(COLON_tok);}
","			{return(COMMA_tok);}
"."			{return(PERIOD_tok);}
"("			{return(OPEN_PAREN_tok);}
")"			{return(CLOSE_PAREN_tok);}
"{"			{return(OPEN_BRACE_tok);}
"}"			{return(CLOSE_BRACE_tok);}

"?"			{return(QUESTION_MARK_tok);}
"|"			{return(BAR_tok);}
"^"			{return(CARET_tok);}
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
{character}	{if(lex_debug_level >= 2){printf("%ld\n",sizeof(yytext));}return(CHARACTER_CONSTANT_tok);}
{string}	{return(STRING_LITERAL_tok);}


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

{mult_line_comment}		{printf("%s",yytext);}
{line_comment}			{printf("%s",yytext);}


.			{return(ERROR_tok);}



%%
void white()
{
	//count the lines and columns for errors
}

char character()
{
	//checks valid chars and reports error or returns char
	
}

int main(int argc, char *argv)
{
	int tok;
	SymbolTable s;
	//s.insert("KEY",Data);
	s.pushEmptyBST();
	s.popBST();
	//s.searchTop("KEY");//returns pointer to node
	//s.searchAll("KEY");//returns pointer
	//s.writeToFile();//dumps table to file
	while(tok = yylex())
	{
	
		printf("%d\n",tok);
	}
	return 0;	
}