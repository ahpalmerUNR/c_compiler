CC=gcc
CPP=g++
CFLAGS=-Wall -std=c99
CPPFLAGS = -Wall
LEX=flex
OBJ=scanner.o bison_out.o symbol_table.o c_compiler.tabl.c -lfl
YACC=bison
YFLAGS=-d

c_compiler: $(OBJ)
	$(CC) $(CFLAGS) c_compiler $(OBJ)
	
bison_out: c_compiler.ypp symbol_table.o
	$(YACC) $(YFLAGS) c_compiler.ypp
	
scanner: flex_out symbol_table.o
	$(CPP) $(CPPFLAGS) -c $@ lex.yy.cc -lfl
	
flex_out: c_compiler.lex
	$(LEX) c_compiler.lex
	
symbol_table: symboltable.cpp 
	$(CPP) $(CPPFLAGS) -c symboltable.cpp 

clean:
	-rm -f lex.yy.* c_compiler.tab.* *.o