CC=gcc
CPP=g++
CFLAGS=-std=c99
CPPFLAGS = -std=c++11
LEX=flex
OBJ= c_compiler.tab.hpp lex.yy.o symboltable.o tree.o  -lfl
BUILDOBJ= build/c_compiler.tab.hpp lex.yy.o symboltable.o tree.o -lfl
NODES= labelNode.o emptyNode.o iteration_statement.o dataNode.o jumpNode.o selectionNode.o
YACC=bison
YFLAGS=-d -v -t

all: c_compiler

c_compiler: $(OBJ) $(NODES)
	$(CPP) $(CPPFLAGS) -o build/c_compiler  build/c_compiler.tab.cpp $(BUILDOBJ) $(NODES)
	
c_compiler.tab.hpp: symboltable.o tree.o $(NODES)
	$(YACC) $(YFLAGS) --file-prefix=build/c_compiler src/c_compiler.ypp
	
lex.yy.o: flex_out symboltable.o
	$(CPP) $(CPPFLAGS) -c build/lex.yy.c -lfl
	
flex_out: src/symboltable.h
	$(LEX) --outfile=build/lex.yy.c src/c_compiler.lex src/symboltable.h
	
symboltable.o: src/symboltable.cpp src/symboltable.h
	$(CPP) $(CPPFLAGS) -c src/symboltable.cpp

tree.o: src/tree/tree.cpp src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/tree.cpp

labelNode.o: src/tree/labelNode.cpp src/tree/labelNode.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/labelNode.cpp

jumpNode.o: src/tree/jumpNode.cpp src/tree/jumpNode.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/jumpNode.cpp
	
emptyNode.o: src/tree/emptyNode.cpp src/tree/emptyNode.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/emptyNode.cpp
	
iteration_statement.o: src/tree/iteration_statement.cpp src/tree/iteration_statement.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/iteration_statement.cpp
	
selectionNode.o: src/tree/selectionNode.cpp src/tree/selectionNode.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/selectionNode.cpp

dataNode.o: src/tree/dataNode.cpp src/tree/dataNode.h src/tree/tree.h
	$(CPP) $(CPPFLAGS) -c src/tree/dataNode.cpp

clean:
	-rm -f build/lex.yy.* build/c_compiler.tab.* build/*.o build/*.s build/c_compiler build/c_compiler.output 
