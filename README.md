# c_compiler
c_compiler for UNR Compilers CS 660. This program takes in a .c file and returns a MIPS program. The MIPS program is intended to be passed into the SPIM program for execution. This repository was created to compile and run on a Linux machine with SPIM, g++, flex, and bison.

## Table Of Contents

[Installation](#installation)

[Usage](#usage)

[Team Mate Contributions](#contributions)

## Installation
Installation is done through the terminal.

If you do not have SPIM, g++, flex, or bison, perform a sudo apt-get install.
```
sudo apt-get install qt-sdk qtspim 
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
## Contributions

git pull origin andrew
git merge andrew
git commit
git push
