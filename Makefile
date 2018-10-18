CC=gcc
CPP=g++
CFLAGS=-std=c99
CPPFLAGS = -std=c++11
LEX=flex
OBJ= c_compiler.tab.hpp lex.yy.o symboltable.o -lfl
BUILDOBJ= build/c_compiler.tab.hpp lex.yy.o symboltable.o -lfl
YACC=bison
YFLAGS=-d -v -t

all: c_compiler

c_compiler: $(OBJ)
	$(CPP) $(CPPFLAGS) -o build/c_compiler  build/c_compiler.tab.cpp $(BUILDOBJ)
	
c_compiler.tab.hpp: symboltable.o
	$(YACC) $(YFLAGS) --file-prefix=build/c_compiler src/c_compiler.ypp
	
lex.yy.o: flex_out symboltable.o
	$(CPP) $(CPPFLAGS) -c build/lex.yy.c -lfl
	
flex_out: src/symboltable.h
	$(LEX) --outfile=build/lex.yy.c src/c_compiler.lex src/symboltable.h
	
symboltable.o: src/symboltable.h
	$(CPP) $(CPPFLAGS) -c src/symboltable.cpp 

clean:
	-rm -f build/lex.yy.* build/c_compiler.tab.* build/*.o build/*.s build/c_compiler build/c_compiler.output