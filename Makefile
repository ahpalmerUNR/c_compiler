CC=gcc
CFLAGS=-Wall -std=c99
LEX=flex
OBJ=lex.yy.c c_compiler.tabl.c -lfl
YACC=bison
YFLAGS=-d

c_compiler: $(OBJ)
	$(CC) $(CFLAGS) c_compiler $(OBJ)
	
bison_out: c_compiler.y
	$(YACC) $(YFLAGS) c_compiler.y
	
scanner: flex_out
	$(CC) $(CFLAGS) -o $@ lex.yy.c -lfl
	
flex_out: c_compiler.lex
	$(LEX) c_compiler.lex

clean:
	-rm -f lex.yy.* c_compiler.tab.* *.o