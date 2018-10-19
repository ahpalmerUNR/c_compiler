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

## Contributions

git pull origin andrew
git merge andrew
git commit
git push
