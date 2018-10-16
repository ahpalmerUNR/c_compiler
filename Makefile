CC=gcc
CPP=g++
CFLAGS=-Wall -std=c99
CPPFLAGS = -Wall -std=c++11
LEX=flex
OBJ= lex.yy.o c_compiler.tab.hpp symboltable.o -lfl
YACC=bison
YFLAGS=-d

c_compiler: $(OBJ)
	$(CPP) $(CPPFLAGS) -o c_compiler  c_compiler.tab.cpp $(OBJ)

c_compiler.tab.hpp: c_compiler.ypp symboltable.o
	$(YACC) $(YFLAGS) c_compiler.ypp

lex.yy.o: flex_out symboltable.o
	$(CPP) $(CPPFLAGS) -c lex.yy.c -lfl

flex_out: c_compiler.lex
	$(LEX) c_compiler.lex

symboltable.o: symboltable.cpp
	$(CPP) $(CPPFLAGS) -c symboltable.cpp

clean:
	-rm -f lex.yy.* c_compiler.tab.* *.o
