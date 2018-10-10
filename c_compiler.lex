
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
#include "c_compiler_tokens.h"

extern int yylval;
extern int lex_debug_level;
extern int symbol_table_debug;
extern int yacc_debug_level;
extern int c_line_lex_debug_level;
extern int c_line_symbol_table_debug;
extern int c_line_yacc_debug_level;
extern int insert_lookup;
extern SymbolTable s;
int line = 1;
int column = 0;
FILE *outfile;
FILE *out_log;
FILE *errorText;
char *file_name;
char tmp[80];

int levels[4];

int send_token(char* token_name,int token);
void white();
void character();
void mult_line();
void single_line();
void print_error(char* error_msg);
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


"auto"		{return(send_token("AUTO_tok",AUTO_tok));}
			
"break"		{return(send_token("BREAK_tok",BREAK_tok));}
			
"case"		{return(send_token("CASE_tok",CASE_tok));}
			
"char"		{return(send_token("CHAR_tok",CHAR_tok));}
			
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

{id}		{column+=yyleng;return(id_token());}

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

{int}		{column+=yyleng;check_int();return(INTEGER_CONSTANT_tok);}

{float}		{column+=yyleng;check_float();return(FLOATING_CONSTANT_tok);}

{character}	{column+=yyleng;character();return(CHARACTER_CONSTANT_tok);}
				
{string}	{return(send_token("STRING_LITERAL_tok",STRING_LITERAL_tok));}


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

"!!D"			{column+=yyleng;s.writeToFile(); }

.			{column+=yyleng;print_error("Syntax Error: Not Legal Character.");
				return(ERROR_tok);}



%%
int send_token(char* token_name,int token)
{
	column+=yyleng;
	//printf("%d\n",lex_debug_level);
	if(lex_debug_level%5==0)
	{
		printf("%s ==>",yytext);
	}
	if(lex_debug_level%2==0)
	{
		printf("%s\n",token_name);
	}
	return token;
}


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
	//printf("%c\t%d\n",yylval,yylval);
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
	Node * pointsTo = NULL;
	int scope;
	pointsTo = s.searchAll(yytext,&scope);
	if(pointsTo->ntype == 1)
	{
		yylval = pointsTo;
		return(ID_tok);
	}
	else if(pointsTo->ntype==2)
	{
		yylval = pointsTo;
		return(ENUMERATION_CONSTANT_tok);
	}
	else if(pointsTo->ntype == 3)
	{
		yylval = pointsTo;
		return(TYPEDEF_NAME_tok);
	}
	else
	{
		yylval = s.insert(yytext,line,INT_TYPE);
		return(ID_tok);
	}
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
	int scan_count = 0;
	int lex_count = 0;
	int yacc_count = 0;
	
	c_line_symbol_table_debug =1;
	c_line_lex_debug_level=1;
	c_line_yacc_debug_level=1;
	
	
	levels[0] = 2;
	levels[1] = 3;
	levels[2] = 5;
	levels[3] = 7;
	
	outfile = fopen("out.s","w");
	out_log = fopen("compilerLog.txt","a");
	
	
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
			if(argv[i][0]=='-' && argv[i][1]=='o')
			{
				fclose(outfile);
				printf("%s\n",argv[i+1]);
				outfile = fopen(argv[i+1],"w");
			}
			
			if(argv[i][0]=='-' && argv[i][1]=='l')
			{
				fclose(out_log);
				out_log = fopen(argv[i+1],"a");
			}
			if(argv[i][0]=='-' && argv[i][1]=='d')
			{
				for(int p = 2;argv[i][p]!='\0';p++)
				{
					switch(argv[i][p])
					{
						case 'l':
							lex_count+=1;
							if(lex_count <= 4)
							{
								c_line_lex_debug_level *= levels[lex_count-1];
							}
							break;
						case 's':
							scan_count+=1;
							if(scan_count <= 4)
							{
								c_line_symbol_table_debug *= levels[scan_count-1];
							}
							break;
						case 'y':
							yacc_count+=1;
							if(yacc_count <= 4)
							{
								c_line_yacc_debug_level*=levels[yacc_count-1];
							}
							break;
					}
				}
				//printf("Lex Count: %d, Scan Count: %d\n",lex_count,scan_count);
				printf("Lex Debug level: %d\nYacc Debug level: %d\nScanner Debug level: %d\n",c_line_lex_debug_level,c_line_yacc_debug_level,c_line_symbol_table_debug);
				
			}
			
			
		}
	}
	int tok;
	
	lex_debug_level = c_line_lex_debug_level;
	symbol_table_debug = c_line_symbol_table_debug;
	yacc_debug_level = c_line_yacc_debug_level;
	
	printf("%d\n",lex_debug_level);
	

	//s.insert("KEY",Data);
	//s.pushEmptyBST();
	//s.popBST();
	//s.searchTop("KEY");//returns pointer to node
	//s.searchAll("KEY");//returns pointer
	//s.writeToFile();//dumps table to file
	//lex_debug_level = 1;
	//symbol_table_debug = 1;
	//yacc_debug_level = 1;
	while((tok = yylex()))
	{
	
		//printf("%d\n",tok);
	}
	fclose(out_log);
	fclose(outfile);
	fclose(errorText);
	return 0;	
}