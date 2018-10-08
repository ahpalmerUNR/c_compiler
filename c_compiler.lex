
/************************************************************************/
/*                                                                      */
/* FILE    : c_compiler.lex                                             */
/* PURPOSE : to cause pain and suffering                                */
/*                                                                      */
/************************************************************************/

%{
#include <stdio.h>
#include <stdlib.h>
#include "c_compiler_tokens.h"
//#include "symboltable.cpp"

extern int yylval;
extern int lex_debug_level;
extern int symbol_table_debug;
extern int yacc_debug_level;
extern int insert_lookup;
int line = 1;
int column = 0;
FILE *errorText;
char *file_name;
char tmp[80];

void white();
void character();
void mult_line();
void single_line();
void print_error();
void set_debug_level();
void check_int();
int id_token();
void check_float();
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
{ws}		{white();}


"auto"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("AUTO_tok\n");}return(AUTO_tok);}
			
"break"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("BREAK_tok\n");}return(BREAK_tok);}
			
"case"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CASE_tok\n");}return(CASE_tok);}
			
"char"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CHAR_tok\n");}return(CHAR_tok);}
			
"const"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CONST_tok\n");}return(CONST_tok);}
			
"continue"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CONTINUE_tok\n");}return(CONTINUE_tok);}
			
"default" 	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DEFAULT_tok\n");}return(DEFAULT_tok);}
			
"do"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DO_tok\n");}return(DO_tok);}
			
"double"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DOUBLE_tok\n");}return(DOUBLE_tok);}
			
"else"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("ELSE_tok\n");}return(ELSE_tok);}
			
"enum"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("ENUM_tok\n");}return(ENUM_tok);}
			
"extern"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("EXTERN_tok\n");}return(EXTERN_tok);}
			
"float"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("FLOAT_tok\n");}return(FLOAT_tok);}
			
"for"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("FOR_tok\n");}return(FOR_tok);}
			
"goto"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("GOTO_tok\n");}return(GOTO_tok);}
			
"if"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("IF_tok\n");}return(IF_tok);}
			
"int"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("INT_tok\n");}return(INT_tok);}
			
"long"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("LONG_tok\n");}return(LONG_tok);}
			
"register"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("REGISTER_tok\n");}return(REGISTER_tok);}
			
"return"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("RETURN_tok\n");}return(RETURN_tok);}
			
"short"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SHORT_tok\n");}return(SHORT_tok);}
			
"signed"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SIGNED_tok\n");}return(SIGNED_tok);}
			
"sizeof"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SIZEOF_tok\n");}return(SIZEOF_tok);}
			
"static"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("STATIC_tok\n");}return(STATIC_tok);}
			
"struct"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("STRUCT_tok\n");}return(STRUCT_tok);}
			
"switch"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SWITCH_tok\n");}return(SWITCH_tok);}
			
"typedef"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("TYPEDEF_tok\n");}return(TYPEDEF_tok);}
			
"union"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("UNION_tok\n");}return(UNION_tok);}
			
"unsigned"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("UNSIGNED_tok\n");}return(UNSIGNED_tok);}
			
"void"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("VOID_tok\n");}return(VOID_tok);}
			
"volatile"	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("VOLATILE_tok\n");}return(VOLATILE_tok);}
			
"while"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("WHILE_tok\n");}return(WHILE_tok);}

{id}		{column+=yyleng;return(id_token());}

"+"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("PLUS_tok\n");}return(PLUS_tok);}
			
"-"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("MINUS_tok\n");}return(MINUS_tok);}
			
"*"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("STAR_tok\n");}return(STAR_tok);}
			
"/"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DIV_tok\n");}return(DIV_tok);}
			
";"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SEMI_tok\n");}return(SEMI_tok);}
			
"["			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("OPEN_BRACKET_tok\n");}return(OPEN_BRACKET_tok);}
			
"]"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CLOSE_BRACKET_tok\n");}return(CLOSE_BRACKET_tok);}
			
"="			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("EQUAL_tok\n");}return(EQUAL_tok);}
			
":"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("COLON_tok\n");}return(COLON_tok);}
			
","			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("COMMA_tok\n");}return(COMMA_tok);}
			
"."			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("PERIOD_tok\n");}return(PERIOD_tok);}
			
"("			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("OPEN_PAREN_tok\n");}return(OPEN_PAREN_tok);}
			
")"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CLOSE_PAREN_tok\n");}return(CLOSE_PAREN_tok);}
			
"{"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("OPEN_BRACE_tok\n");}return(OPEN_BRACE_tok);}
			
"}"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CLOSE_BRACE_tok\n");}return(CLOSE_BRACE_tok);}

"?"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("QUESTION_MARK_tok\n");}return(QUESTION_MARK_tok);}
			
"|"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("BAR_tok\n");}return(BAR_tok);}
			
"^"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("CARET_tok\n");}return(CARET_tok);}
			
"&"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("AMP_tok\n");}return(AMP_tok);}
			
"<"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("GT_tok\n");}return(GT_tok);}
			
">"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("LT_tok\n");}return(LT_tok);}
			
"%"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("PERCENT_tok\n");}return(PERCENT_tok);}

"~"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("TILDA_tok\n");}return(TILDA_tok);}
			
"!"			{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("NOT_tok\n");}return(NOT_tok);}
			
"++"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("INC_OP_tok\n");}return(INC_OP_tok);}
			
"--"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DEC_OP_tok\n");}return(DEC_OP_tok);}

{int}		{column+=yyleng;check_int();return(INTEGER_CONSTANT_tok);}

{float}		{column+=yyleng;check_float();return(FLOATING_CONSTANT_tok);}

{character}	{column+=yyleng;character();return(CHARACTER_CONSTANT_tok);}
				
{string}	{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("STRING_LITERAL_tok\n");}return(STRING_LITERAL_tok);}


"<-"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("PTR_OP_tok\n");}return(PTR_OP_tok);}
			
"<<"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("LEFT_OP_tok\n");}return(LEFT_OP_tok);}
			
">>"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("RIGHT_OP_tok\n");}return(RIGHT_OP_tok);}
			
"<="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("LE_OP_tok\n");}return(LE_OP_tok);}
			
">="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("GE_OP_tok\n");}return(GE_OP_tok);}
			
"=="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("EQ_OP_tok\n");}return(EQ_OP_tok);}
			
"!="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("NE_OP_tok\n");}return(NE_OP_tok);}

"&&"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("AND_OP_tok\n");}return(AND_OP_tok);}
			
"||"		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("OR_OP_tok\n");}return(OR_OP_tok);}

"*="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("MULT_ASSIGN_tok\n");}return(MULT_ASSIGN_tok);}
			
"/="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("DIV_ASSIGN_tok\n");}return(DIV_ASSIGN_tok);}
			
"%="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("MOD_ASSIGN_tok\n");}return(MOD_ASSIGN_tok);}
			
"+="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("ADD_ASSIGN_tok\n");}return(ADD_ASSIGN_tok);}
			
"-="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("SUB_ASSIGN_tok\n");}return(SUB_ASSIGN_tok);}
			
"<<="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("LEFT_ASSIGN_tok\n");}return(LEFT_ASSIGN_tok);}
			
">>="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("RIGHT_ASSIGN_tok\n");}return(RIGHT_ASSIGN_tok);}
			
"&="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("AND_ASSIGN_tok\n");}return(AND_ASSIGN_tok);}
			
"^="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("XOR_ASSIGN_tok\n");}return(XOR_ASSIGN_tok);}
			
"|="		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("OR_ASSIGN_tok\n");}return(OR_ASSIGN_tok);}

"..."		{column+=yyleng;if(lex_debug_level%5==0){
			printf("%s ==>",yytext);}if(lex_debug_level%2==0){
			printf("ELIPSIS_tok\n");}return(ELIPSIS_tok);}

{mult_line_comment}		{mult_line();}

{line_comment}			{single_line();}

"!!"(L|Y)\ {digit}+		{set_debug_level();}

"!!S"			{column+=yyleng; }

.			{column+=yyleng;print_error("Syntax Error: Not Legal Character.");
				return(ERROR_tok);}



%%
void white()
{
	//printf("S%sN",yytext);
	for(int i =0;i<yyleng;i++)
	{
		//count the lines and columns for errors
		if(yytext[i]=='\t')
		{
			//printf("char == tab \n");
			column += 7;
		}
		else if(yytext[i]=='\n')
		{
			//printf("char == new line\n");
			fgets(tmp,sizeof tmp, errorText);
			//printf("%s",tmp);
			line ++;
			//printf("columns %d\n",column);
			column = 0;
			//printf("Lines = %d, Column = %d\n",line,column);
		}
		else if(yytext[i]==' ')
		{
			//printf("char == space\n");
			column +=1;
		}
	}
	
}

void character()
{
	int code = 0;
	if(lex_debug_level%5==0)
	{
		printf("%s ==>",yytext);
	}
		
	if(lex_debug_level%2==0)
	{
		printf("CHARACTER_CONSTANT_tok\n");
	}
	
	if(yytext[1]!='\\' && yytext[1]!='\'')
	{
		yylval = yytext[1];
	}
	else if(yytext[1]=='\\')
	{
		switch(yytext[2])
		{
			case 'n':
				yylval = 10;
				break;
			case 't':
				yylval = 9;
				break;
			case 'v':
				yylval = 11;
				break;
			case 'b':
				yylval = 8;
				break;
			case 'r':
				yylval = 13;
				break;
			case 'f':
				yylval = 12;
				break;
			case 'a':
				yylval = 7;
				break;
			case '\\':
				yylval = 92;
				break;
			case '\?':
				yylval = 63;
				break;
			case '\'':
				yylval = 39;
				break;
			case '\"':
				yylval = 34;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				for(int j = 2; j<5 ;j++)
				{
					//printf("%d\t%d\n",yytext[j],j);
					if(!(yytext[j]>=48 && yytext[j]<56))
					{
						print_error("Octal character error.");
					}
					else
					{
						code = (code * 8) + (yytext[j] - 48);
					}
				}
				if(code>127)
				{
					print_error("Octal character out of range.");
				}
				//printf("%d",code);
				yylval = code;
				break;
			case 'x':
				for(int j = 3; j<5 ;j++)
				{
					if((yytext[j]>=48 && yytext[j]<58))
					{
						code = (code * 16) + (yytext[j] - 48);
					}
					else if((yytext[j]>=65 && yytext[j]<71))
					{
						code = (code * 16) + (yytext[j] - 55);
					}
					else
					{
						print_error("Hex character error.");
					}
				}
				if(code>127)
				{
					print_error("Hex character out of range.");
				}
				//printf("%d",code);
				yylval = code;
				break;

			//hex 7F octal 177 max limit
		}
	}
	printf("%c\t%d\n",yylval,yylval);
	//checks valid chars and reports error 
	
}

void mult_line()
{
	
	//printf("%u\n",yyleng);
	for(int i=0;i<yyleng;i++)
	{
		//printf("%c",yytext[i]);
		if(yytext[i]=='\n')
		{
			fgets(tmp,sizeof tmp, errorText);
			line ++;
			//printf("columns %d\n",column);
			column = 0;
		}
	}
}

void single_line()
{
	
	fgets(tmp,sizeof tmp, errorText);
	line++;
	//printf("columns %d\n",column);
	column = 0;
}

void print_error(char *error_msg)
{	long int offset = ftell(errorText);
	fgets(tmp,sizeof tmp, errorText);
	fseek(errorText,offset,SEEK_SET);
	printf("ERROR: %s:Line: %d Column: %d %s\n",file_name,line,column,error_msg);
	printf("%s",tmp);
	for(int i = column; i>0;i--)
	{
		printf("-");
	}
	printf("^ \n\n");
	//printf("columns %d, lines %d\n",column,line);
}

void set_debug_level()
{
	//printf("set Debug");
	column+=yyleng;
	
	//char* stringFrom = yytext+'\n';
	char typebug='L';
	char num[4];
	int level=0;
	//printf("%s\n",yytext);
	typebug = yytext[2];
	for(int i = 0; i < 4; i++)
	{
		num[i]=yytext[i+4];
	}
	level = atoi(num);
	//sscanf(yytext+'\n',"!!%c %d",&typebug,&level);
	//printf("Debug %c set to %d\n",typebug,level);
	if(typebug == 'Y')
	{
		yacc_debug_level = level;
	}
	else
	{
		lex_debug_level = level;
	}
}

void check_int()
{
	if(lex_debug_level%5==0)
	{
		printf("%s ==>",yytext);
	}
		
	if(lex_debug_level%2==0)
	{
		printf("INTEGER_CONSTANT_tok\n");
	}
	
	long int test_int_down = -2147483648;
	long int test_int_up = 2147483647;
	long int test = atol(yytext);
	
	//printf("Up %ld, Down %ld, Given %ld\n",test_int_up,test_int_down,test);
	
	if(test<test_int_down || test > test_int_up)
	{
		print_error("Syntax Error: Int Value Out Of Range.");
	}
	
	//printf("%d",yylval);
	yylval = test;
	//return INTEGER_CONSTANT_tok;
	
}

void check_float()
{
	if(lex_debug_level%5==0)
	{
		printf("%s ==>",yytext);
	}
		
	if(lex_debug_level%2==0)
	{
		printf("FLOATING_CONSTANT_tok\n");
	}
	//print_error("Float Value Too Large.");
}

int id_token()
{
	// pointsTo = NULL;
	// pointsTo = s.searchAll(yytext);
	// if(pointsTo.ntype == 1)
	// {
	// 	yylval = pointsTo;
	// 	return(ID_tok);
	// }
	// else if(pointsTo.ntype==2)
	// {
	// 	yylval = pointsTo;
	// 	return(ENUMERATION_CONSTANT_tok);
	// }
	// else if(pointsTo.ntype == 3)
	// {
	// 	yylval = pointsTo;
	// 	return(TYPEDEF_NAME_tok);
	// }
	// else
	// {
	// 	yylval = s.insert(yytext);
	// 	return(ID_tok);
	// }
	if(lex_debug_level%5==0)
	{
		printf("%s ==>",yytext);
	}
	if(lex_debug_level%2==0)
	{
		printf("ID_tok\n");
	}
	return(ID_tok);
}

int main(int argc, char **argv)
{
	if(argc==1)
	{
		printf("No File Provided. Pass file in command line.");
	}
	else
	{
		if(!(yyin=fopen(argv[argc-1],"r")))
		{
			perror(argv[argc-1]);
			return(1);
		}
		file_name=argv[argc-1];
		errorText = fopen(argv[argc-1],"r");
		for(int i=argc-1; i>=1; i--)
		{
			//add to debug levels
			
		}
	}
	int tok;
	//SymbolTable s;
	//s.insert("KEY",Data);
	//s.pushEmptyBST();
	//s.popBST();
	//s.searchTop("KEY");//returns pointer to node
	//s.searchAll("KEY");//returns pointer
	//s.writeToFile();//dumps table to file
	lex_debug_level = 1;
	symbol_table_debug = 1;
	yacc_debug_level = 1;
	while((tok = yylex()))
	{
	
		//printf("%d\n",tok);
	}
	return 0;	
}