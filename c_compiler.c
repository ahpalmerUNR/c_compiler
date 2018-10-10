/*
* @Author: ahpalmerUNR
* @Date:   2018-10-10 15:37:38
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-10 15:42:54

*/
#include <stdio.h>
#include <stdlib.h>
#include "c_compiler.tab.hpp"
#include "symbtable.h"

int lex_debug_level;
int symbol_table_debug;
int yacc_debug_level;
int c_line_lex_debug_level;
int c_line_symbol_table_debug;
int c_line_yacc_debug_level;
int insert_lookup;
SymbolTable s;
extern char yytext[];
extern int column;
extern int line;

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
	out_log = fopen(logName,"a");
	
	
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
				logName = argv[i+1];
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
	//int tok;
	
	lex_debug_level = c_line_lex_debug_level;
	symbol_table_debug = c_line_symbol_table_debug;
	yacc_debug_level = c_line_yacc_debug_level;
	
	printf("%d\n",lex_debug_level);
	//logName = "compilerLog.txt";

	//s.insert("KEY",Data);
	//s.pushEmptyBST();
	//s.popBST();
	//s.searchTop("KEY");//returns pointer to node
	//s.searchAll("KEY");//returns pointer
	//s.writeToFile();//dumps table to file
	//lex_debug_level = 1;
	//symbol_table_debug = 1;
	//yacc_debug_level = 1;
	yyparse();
	//while((tok = yylex()))
	//{
	
		//printf("%d\n",tok);
	//}
	fclose(out_log);
	fclose(outfile);
	fclose(errorText);
	return 0;	
}