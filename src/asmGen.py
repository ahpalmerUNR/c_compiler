# -*- coding: utf-8 -*-
# @Author: ahpalmerUNR
# @Date:   2018-12-16 22:22:02
# @Last Modified by:   ahpalmerUNR
# @Last Modified time: 2018-12-16 23:05:04
import sys

infile = ""
outfile = ""

commanddict = {}

def populateCommands():
	commanddict["#"] = "#%s"
	commanddict["BR"] = ""
	commanddict["EQ"] = ""
	commanddict["NE"] = ""
	commanddict["GT"] = ""
	commanddict["GE"] = ""
	commanddict["LT"] = ""
	commanddict["LE"] = ""
	commanddict["PROCENTRY"] = ""
	commanddict["ENDPROC"] = ""
	commanddict["CALL"] = ""
	commanddict["REFOUT"] = ""
	commanddict["VALOUT"] = ""
	commanddict["ARGS"] = ""
	commanddict["LABEL"] = "%s:\t\t\t\t\t%s"
	commanddict["BREQ"] = ""
	commanddict["BRNE"] = ""
	commanddict["ADDR"] = ""
	commanddict["DIV"] = ""
	commanddict["MOD"] = ""
	commanddict["SUB"] = ""
	commanddict["MULT"] = ""
	commanddict["ADD"] = ""
	commanddict["ALLOC"] = ""
	commanddict["ASSIGN"] = ""
	commanddict["LOAD"] = ""
	commanddict["STORE"] = ""
	commanddict["CAST"] = ""
	commanddict["RETURN"] = ""
	commanddict["LEFT"] = ""
	commanddict["RIGHT"] = ""
	commanddict["OR"] = ""
	commanddict["XOR"] = ""
	commanddict["AND"] = ""

def castfunc(ticket1,ticket2):
	pass


def registerLife():
	with open(outfile,'w') as fout:
		fout.write("This is a test call.")
	
	
def genAsm():
	pass




if __name__ == '__main__':
	infile = sys.argv[1]
	outfile = sys.argv[2]
	registerLife()
	genAsm()

