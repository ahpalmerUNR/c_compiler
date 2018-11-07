
/************************************************************************/
/*                                                                      */
/* FILE    : c_compiler.lex                                             */
/* PURPOSE : to cause pain and suffering                                */
/*                                                                      */
/************************************************************************/

%{
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <memory>
#include "../build/c_compiler.tab.hpp"
#include "../src/symboltable.h"

#define MAX_LINE_LENGTH 500

extern YYSTYPE yylval;
extern int lex_debug_level;
extern int symbol_table_debug;
extern int yacc_debug_level;
extern int c_line_lex_debug_level;
extern int c_line_symbol_table_debug;
extern int c_line_yacc_debug_level;
extern int insert_lookup;
extern SymbolTable s;
int line = 1;
int column = 1;
extern FILE *outfile;
extern FILE *out_log;
extern char *logName;
extern FILE *errorText;
extern FILE * tokenFile;
extern FILE * parseFile;
extern char *file_name;
char tmp[MAX_LINE_LENGTH];
extern time_t time_time;
extern clock_t clock_time;
//struct tm * timeinfo;

extern int* levels;

string id;
int idLine;
int idCol;

int send_token(char const* token_name,int token);
void white();
void character();
void mult_line();
void stringVal();
void single_line();
void read_line();
void print_error(char const* error_msg);
void set_debug_level();
void check_int();
int id_token();
void check_float();

extern unique_ptr<Node> variableToInsert; 
%}

/************************************************************************/
/* Regular Definitions                                                  */
/************************************************************************/

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
hexdig	[a-fA-F]
hex		[-+]?(0[xX])?({digit}|{hexdig})+[ulUL]?
int [-+]?{digit}+[ulUL]?
id	({letter}|_+({letter}|{digit}))+({letter}|{digit}|_)*
float	[-+]?{digit}*\.?{digit}+([eE][+-]?[0-9]+)?
character 	\'([^\']|\\.*)\'
string		\"[^\"]*\"
line_comment	"//".*\n
mult_line_comment	"/*"([^*]|\*+[^*/])*"*/"


%%
{ws}		{white();}


"auto"		{return(send_token("AUTO_tok",AUTO_tok));}
			
"break"		{return(send_token("BREAK_tok",BREAK_tok));}
			
"case"		{return(send_token("CASE_tok",CASE_tok));}
			
"char"		{ return(send_token("CHAR_tok",CHAR_tok));}
			
"const"		{return(send_token("CONST_tok",CONST_tok));}
			
"continue"	{return(send_token("CONTINUE_tok",CONTINUE_tok));}
			
"default" 	{return(send_token("DEFAULT_tok",DEFAULT_tok));}
			
"do"		{return(send_token("DO_tok",DO_tok));}
			
"double"	{return(send_token("DOUBLE_tok",DOUBLE_tok));}
			
"else"		{return(send_token("ELSE_tok",ELSE_tok));}
			
"enum"		{return(send_token("ENUM_tok",ENUM_tok));}
			
"extern"	{return(send_token("EXTERN_tok",EXTERN_tok));}
			
"float"		{return(send_token("FLOAT_tok",FLOAT_tok));}
			
"for"		{return(send_token("FOR_tok",FOR_tok));}
			
"goto"		{return(send_token("GOTO_tok",GOTO_tok));}
			
"if"		{return(send_token("IF_tok",IF_tok));}
			
"int"		{return(send_token("INT_tok",INT_tok));}
			
"long"		{return(send_token("LONG_tok",LONG_tok));}
			
"register"	{return(send_token("REGISTER_tok",REGISTER_tok));}
			
"return"	{return(send_token("RETURN_tok",RETURN_tok));}
			
"short"		{return(send_token("SHORT_tok",SHORT_tok));}
			
"signed"	{return(send_token("SIGNED_tok",SIGNED_tok));}
			
"sizeof"	{return(send_token("SIZEOF_tok",SIZEOF_tok));}
			
"static"	{return(send_token("STATIC_tok",STATIC_tok));}
			
"struct"	{return(send_token("STRUCT_tok",STRUCT_tok));}
			
"switch"	{return(send_token("SWITCH_tok",SWITCH_tok));}
			
"typedef"	{return(send_token("TYPEDEF_tok",TYPEDEF_tok));}
			
"union"		{return(send_token("UNION_tok",UNION_tok));}
			
"unsigned"	{return(send_token("UNSIGNED_tok",UNSIGNED_tok));}
			
"void"		{return(send_token("VOID_tok",VOID_tok));}
			
"volatile"	{return(send_token("VOLATILE_tok",VOLATILE_tok));}
			
"while"		{return(send_token("WHILE_tok",WHILE_tok));}

{id}		{return(id_token());}

"+"			{return(send_token("PLUS_tok",PLUS_tok));}
			
"-"			{return(send_token("MINUS_tok",MINUS_tok));}
			
"*"			{return(send_token("STAR_tok",STAR_tok));}
			
"/"			{return(send_token("DIV_tok",DIV_tok));}
			
";"			{return(send_token("SEMI_tok",SEMI_tok));}
			
"["			{return(send_token("OPEN_BRACKET_tok",OPEN_BRACKET_tok));}
			
"]"			{return(send_token("CLOSE_BRACKET_tok",CLOSE_BRACKET_tok));}
			
"="			{return(send_token("EQUAL_tok",EQUAL_tok));}
			
":"			{return(send_token("COLON_tok",COLON_tok));}
			
","			{return(send_token("COMMA_tok",COMMA_tok));}
			
"."			{return(send_token("PERIOD_tok",PERIOD_tok));}
			
"("			{return(send_token("OPEN_PAREN_tok",OPEN_PAREN_tok));}
			
")"			{return(send_token("CLOSE_PAREN_tok",CLOSE_PAREN_tok));}
			
"{"			{return(send_token("OPEN_BRACE_tok",OPEN_BRACE_tok));}
			
"}"			{return(send_token("CLOSE_BRACE_tok",CLOSE_BRACE_tok));}

"?"			{return(send_token("QUESTION_MARK_tok",QUESTION_MARK_tok));}
			
"|"			{return(send_token("BAR_tok",BAR_tok));}
			
"^"			{return(send_token("CARET_tok",CARET_tok));}
			
"&"			{return(send_token("AMP_tok",AMP_tok));}
			
"<"			{return(send_token("GT_tok",GT_tok));}
			
">"			{return(send_token("LT_tok",LT_tok));}
			
"%"			{return(send_token("PERCENT_tok",PERCENT_tok));}

"~"			{return(send_token("TILDA_tok",TILDA_tok));}
			
"!"			{return(send_token("NOT_tok",NOT_tok));}
			
"++"		{return(send_token("INC_OP_tok",INC_OP_tok));}
			
"--"		{return(send_token("DEC_OP_tok",DEC_OP_tok));}

{int}		{check_int();return(send_token("INTEGER_CONSTANT_tok",INTEGER_CONSTANT_tok));}

{hex}		{check_int();return(send_token("INTEGER_CONSTANT_tok",INTEGER_CONSTANT_tok));}

{float}		{check_float();return(send_token("FLOATING_CONSTANT_tok",FLOATING_CONSTANT_tok));}

{character}	{character();return(send_token("CHARACTER_CONSTANT_tok",CHARACTER_CONSTANT_tok));}
				
{string}	{stringVal();return(send_token("STRING_LITERAL_tok",STRING_LITERAL_tok));}


"<-"		{return(send_token("PTR_OP_tok",PTR_OP_tok));}
			
"<<"		{return(send_token("LEFT_OP_tok",LEFT_OP_tok));}
			
">>"		{return(send_token("RIGHT_OP_tok",RIGHT_OP_tok));}
			
"<="		{return(send_token("LE_OP_tok",LE_OP_tok));}
			
">="		{return(send_token("GE_OP_tok",GE_OP_tok));}
			
"=="		{return(send_token("EQ_OP_tok",EQ_OP_tok));}
			
"!="		{return(send_token("NE_OP_tok",NE_OP_tok));}

"&&"		{return(send_token("AND_OP_tok",AND_OP_tok));}
			
"||"		{return(send_token("OR_OP_tok",OR_OP_tok));}

"*="		{return(send_token("MULT_ASSIGN_tok",MULT_ASSIGN_tok));}
			
"/="		{return(send_token("DIV_ASSIGN_tok",DIV_ASSIGN_tok));}
			
"%="		{return(send_token("MOD_ASSIGN_tok",MOD_ASSIGN_tok));}
			
"+="		{return(send_token("ADD_ASSIGN_tok",ADD_ASSIGN_tok));}
			
"-="		{return(send_token("SUB_ASSIGN_tok",SUB_ASSIGN_tok));}
			
"<<="		{return(send_token("LEFT_ASSIGN_tok",LEFT_ASSIGN_tok));}
			
">>="		{return(send_token("RIGHT_ASSIGN_tok",RIGHT_ASSIGN_tok));}
			
"&="		{return(send_token("AND_ASSIGN_tok",AND_ASSIGN_tok));}
			
"^="		{return(send_token("XOR_ASSIGN_tok",XOR_ASSIGN_tok));}
			
"|="		{return(send_token("OR_ASSIGN_tok",OR_ASSIGN_tok));}

"..."		{return(send_token("ELIPSIS_tok",ELIPSIS_tok));}

{mult_line_comment}		{mult_line();}

{line_comment}			{single_line();}

"!!"(L|Y|S)\ {digit}+		{set_debug_level();}

"!!D"			{column+=yyleng;s.writeToFile(out_log); }

.			{print_error("Syntax Error: Not Legal Character.");
				return(send_token("ERROR_tok",ERROR_tok));}



%%
int send_token(char const* token_name,int token)
{
	column+=yyleng;
	//printf("%s\n",tmp);
	time_time = time(NULL);
	clock_time = clock();
	if(lex_debug_level%2==0 || lex_debug_level%3==0 || lex_debug_level%5==0 || lex_debug_level%7==0 )
	{
		fprintf(tokenFile,"%s SCANNER Time::%ld:%ld\t Line: %d\t",file_name, time_time,clock_time,line);
		printf("%s SCANNER Time::%ld:%ld\t",file_name, time_time,clock_time);
	}
	//printf("%ld:%ld ",time_time,clock_time);
	if(lex_debug_level%3==0)
	{
		fprintf(tokenFile,"%s ==> ",yytext);
		printf("%s ==> ",yytext);
	}
	if(lex_debug_level%2==0)
	{
		fprintf(tokenFile,"%s\n",token_name);
		printf("%s\n",token_name);
	}

	return token;
}

void read_line()
{
	char first_80[80];
	int null_ind = -1;
	//int num_buffs = 0;
	fgets(tmp,sizeof tmp, errorText);
	for(int i =0;i<MAX_LINE_LENGTH-1;i++)
	{
		if(i<80)
		{
			first_80[i]=tmp[i];
		}
		if(tmp[i]=='\0')
		{
			null_ind = i;
			break;
		}
	}
	if(null_ind == -1)
	{
		printf("Warning: Large Line! Line %d\n",line);
		
		while(null_ind == -1)
		{
			//num_buffs +=1;
			fgets(tmp,sizeof tmp, errorText);
			for(int i =0;i<MAX_LINE_LENGTH-1;i++)
			{
				if(tmp[i]=='\0')
				{
					null_ind = i;
					break;
				}
			}
		}
	}
	for(int i = 0; i<79;i++)
	{
		tmp[i]=first_80[i];
	}
	tmp[79]='\0';
	fprintf(tokenFile,"\n%s\n",tmp);
	fprintf(parseFile,"\n%s\n",tmp);
}

void white()
{
	//printf("S%sN",yytext);
	for(unsigned int i =0;i<yyleng;i++)
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
			read_line();
			//fprintf()
			//printf("%s",tmp);
			line ++;
			//printf("columns %d\n",column);
			column = 1;
			//printf("Lines = %d, Column = %d\n",line,column);
		}
		else if(yytext[i]==' ')
		{
			//printf("char == space\n");
			column +=1;
		}
	}
	
}

void stringVal()
{
	char* tmp = yytext;
	tmp++;
	tmp[yyleng-2] = '\0';
	printf("%s\n",tmp);
	yylval.lstr = tmp;
}

void character()
{
	int code = 0;
	
	
	if(yytext[1]!='\\' && yytext[1]!='\'')
	{
		yylval.lchar = yytext[1];
	}
	else if(yytext[1]=='\\')
	{
		switch(yytext[2])
		{
			case 'n':
				yylval.lchar = 10;
				break;
			case 't':
				yylval.lchar = 9;
				break;
			case 'v':
				yylval.lchar = 11;
				break;
			case 'b':
				yylval.lchar = 8;
				break;
			case 'r':
				yylval.lchar = 13;
				break;
			case 'f':
				yylval.lchar = 12;
				break;
			case 'a':
				yylval.lchar = 7;
				break;
			case '\\':
				yylval.lchar = 92;
				break;
			case '\?':
				yylval.lchar = 63;
				break;
			case '\'':
				yylval.lchar= 39;
				break;
			case '\"':
				yylval.lchar = 34;
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
				yylval.lchar = code;
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
				yylval.lchar = code;
				break;

			//hex 7F octal 177 max limit
		}
	}
	//printf("%c\t%d\n",yylval,yylval);
	//checks valid chars and reports error 
	
}

void mult_line()
{
	
	//printf("%u\n",yyleng);
	for(unsigned int i=0;i<yyleng;i++)
	{
		//printf("%c",yytext[i]);
		if(yytext[i]=='\n')
		{
			read_line();
			line ++;
			//printf("columns %d\n",column);
			column = 1;
		}
	}
}

void single_line()
{
	
	read_line();
	line++;
	//printf("columns %d\n",column);
	column = 1;
}

void print_error(char const *error_msg)
{	long int offset = ftell(errorText);
	read_line();
	fseek(errorText,offset,SEEK_SET);
	fprintf(stderr,"ERROR: %s:Line: %d Column: %d %s\n",file_name,line,column,error_msg);
	//printf("ERROR: %s:Line: %d Column: %d %s\n",file_name,line,column,error_msg);
	printf("%s",tmp);
	for(int i = column; i>0;i--)
	{
		printf("-");
	}
	printf("^ \n\n");
	
	fprintf(out_log,"ERROR: %s:Line: %d Column: %d %s\n",file_name,line,column,error_msg);
	fprintf(out_log,"%s",tmp);
	for(int i = column; i>0;i--)
	{
		fprintf(out_log,"-");
	}
	fprintf(out_log,"^ \n\n");
	
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
		if(level < c_line_yacc_debug_level)
		{
			yacc_debug_level = c_line_yacc_debug_level;
		}
		else
		{
			yacc_debug_level = level;
		}
	}
	else if(typebug == 'L')
	{
		if(level < c_line_lex_debug_level)
		{
			lex_debug_level = c_line_lex_debug_level;
		}
		else
		{
			lex_debug_level = level;
		}
	}
	else
	{
		if(level < c_line_symbol_table_debug)
		{
			symbol_table_debug = c_line_symbol_table_debug;
		}
		else
		{
			symbol_table_debug = level;
		}
	}
}

void check_int()
{
	
	long int test_int_down = -2147483648;
	long int test_int_up = 2147483647;
	long int test;
	
	if(yytext[1]=='x' || yytext[1]=='X')
	{
		test = strtol(yytext,NULL,16);
	}
	else if(yytext[0]=='0')
	{
		test = strtol(yytext,NULL,8);
	}
	else
	{
		test = atol(yytext);
	}
	
	//printf("Up %ld, Down %ld, Given %ld\n",test_int_up,test_int_down,test);
	
	if(test<test_int_down || test > test_int_up)
	{
		print_error("Syntax Error: Int Value Out Of Range.");
	}
	
	//printf("%d",yylval);
	yylval.lint = test;
	//return INTEGER_CONSTANT_tok;
	
}

void check_float()
{
	double posmax = 3.4E+38;
	double posmin = 1.2E-38;
	double negmin = -3.4E+38;
	double negmax = -1.2E-38;
	
	double result;
	result = atof(yytext);
	
	if(!(result==0.0 ||(result<=posmax && result>=posmin) || (result <=negmax && result >=negmin)))
	{
		print_error("Syntax Error: Float Value Out Of Range.");
	}
	//print_error("Float Value Too Large.");
}

int id_token()
{
	//printf("Entered ID function\n");
	Node * pointsTo = NULL;
	//printf("pointsto made\n");
	int scope;
	int errorcode=0;
	if(yyleng >=32)
	{
		
		print_error("Identifier length too large. Max character length 31.");
		
	}
	//printf("Before Search of symboltable");
	//pointsTo = s.searchAll(yytext,&scope);
	//printf("After Search of symboltable");
	if(insert_lookup == 1)
	//if(pointsTo != NULL)
	{
		pointsTo = s.searchAll(yytext,&scope);
		//pointsTo->print();
		//printf("\n\nID FOUND AND NOW ASSIGNING TYPE\n");
		if(pointsTo == NULL)
		{
			print_error("Variable not declared in this scope.");
			return(send_token("ERROR_tok",ERROR_tok));

		}
		else if(pointsTo->ntype == 1)
		{
			yylval.lnode = pointsTo;
			
			return(send_token("ID_tok",ID_tok));
		}
		else if(pointsTo->ntype==2)
		{
			yylval.lnode = pointsTo;
			
			return(send_token("ENUMERATION_CONSTANT_tok",ENUMERATION_CONSTANT_tok));
		}
		else if(pointsTo->ntype == 3)
		{
			yylval.lnode = pointsTo;
			
			return(send_token("TYPEDEF_NAME_tok",TYPEDEF_NAME_tok));
		}
		//else
		//{
		//	printf("Inserting when found\n");
		//	yylval.lnode = s.insert(yytext,line,INT_TYPE,&errorcode);
		//	
		//	return(send_token("ID_tok",ID_tok));
		//}
		
	}
	
	else
	{
		//printf("\n\nID NOT FOUND AND NOW ADDING\n");
		
		id = yytext;
		
		yylval.lnode = variableToInsert.get();
		variableToInsert->name = id;
		variableToInsert->lineNumber = line;
		variableToInsert->colNumber = column;

		if(errorcode==1)
		{
			char buff[200];
			//printf("%s",buff);
			snprintf(buff,200, "Conflicts with variable in current scope on line : %d",yylval.lnode->lineNumber);
			//char*errormes = err+ buff;
			print_error(buff);
		}
		
		return(send_token("ID_tok",ID_tok));
	}
	
	//printf("Lex debug level %d\n",lex_debug_level);
	
	return(send_token("ID_tok",ID_tok));
}

