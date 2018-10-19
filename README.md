# c_compiler
c_compiler for UNR Compilers CS 660. This program takes in a .c file and returns a MIPS program. The MIPS program is intended to be passed into the SPIM program for execution. This repository was created to compile and run on a Linux machine with SPIM, g++, flex, and bison.

## Table Of Contents

[Installation](#installation)

[Usage](#usage)

[Team Mate Contributions](#contributions)

## Installation
Installation is done through the terminal.

If you do not have SPIM you can get it [here](https://sourceforge.net/projects/spimsimulator/files/).

To install g++, flex, or bison, perform a sudo apt-get install.
```
sudo apt-get install flex bison g++
```
First, navigate to the intended destination for the repo folder. By default, we use the Desktop.
```
cd ~/Desktop
```
The just copy the repo, and navigate into it.
```
git clone https://github.com/ahpalmerUNR/c_compiler.git
cd c_compiler
```
## Usage
To make the compiler, just type make in the top folder of the repository. 
```
make
```
You can optionally clear out the build folder via:
```
make clean
```

To compile a c program, run the program with the last argument the source file.
```
./build/c_compiler [args] testCases/t1.c
```
The above code would compile the t1.c test case. All resulting files are saved alongside the testcases.

The c_compiler excepts commandline arguments.
```
	-o [filename] sets the output file name. Defaults to out.s 
	Note: currently -o creates the parse file and defaults to parseFile.txt
	
	-t [filename] sets the token file name. Defaults to tokenFile.txt
	-l [filename] sets the log file name. Defaults to compilerLog.txt
	Note: currently log file only holds symbol table dumps.
	
	-d[lsy]* sets the debug levels for scanner, symbol table, and parser.
	
```

The following are the commandline debug levels.
*Symbol:

   : no debug (1)
   s: print current scope (2)
   ss: enter and leave scopes (3)
   sss: search keys (5)

*Lex:

   : no debug (1)
   l: print token (2)
   ll: print yytext (3)
   lll: print symbol table commands (5)**In Progress

*Yacc:
	: no debug (1)
	y: print productions (2)
	yy: print $$,$1,$2... (3)**In Progress
	yyy: set yydebug=1 for built in debug (5)
	yyyy: print 3 address code (7)**In Progress
	yyyyy: print parse tree passing (11)**In Progress

## Contributions

git pull origin andrew
git merge andrew
git commit
git push
