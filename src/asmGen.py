# -*- coding: utf-8 -*-
# @Author: ahpalmerUNR
# @Date:   2018-12-16 22:22:02
# @Last Modified by:   ahpalmerUNR
# @Last Modified time: 2018-12-17 15:36:36
import sys

infile = ""
outfile = ""

currentBlock = 0

commanddict = {}
floatcommanddict = {}

reginfotable={}#Start line, endline, where current found, istemp, isparam, memory location, block scope

def populateCommands():
	#0 is 3ac code line
	#1 is arg 1
	#2 is arg 2
	#3 is arg 3
	#4 is memory location of arg1
	#5 is memory location of arg2
	#6 is memory location or arg3
	#7 is stacksize for current scope
	#8 is stacksize for locals of current scope
	#9 is current line number
	commanddict["#"] = ("#%s\n",(0))
	commanddict["BR"] = ("\tb\t%s\t\t\t#%s\n",(3,0))
	commanddict["EQ"] = ("\tseq\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["NE"] = ("\tsne\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["GT"] = ("\tsgt\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["GE"] = ("\tsge\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["LT"] = ("\tsge\t%s,\t%s,\t%s\t#%s\n\tnot\t%s\t%s\n",(3,1,2,0,3,3))
	commanddict["LE"] = ("\tsle\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["PROCENTRY"] = ("%s:\t\t\t\t\t#%s\n\taddi\t$sp,\t$sp,\t-%s\n\tsw\t$ra,\t0($sp)\n",(1,0,8))
	commanddict["ENDPROC"] = ("#%s\n",(0))
	commanddict["CALL"] = ("\tjal\t%s\t\t\t#%s\n",(1,0))
	commanddict["REFOUT"] = ("#%s\n",(0))
	commanddict["VALOUT"] = ("#%s\n",(0))
	commanddict["ARGS"] = ("#%s\n",(0))
	commanddict["LABEL"] = ("%s:\t\t\t\t\t#%s\n",(1,0))
	commanddict["BREQ"] = ("\tbeq\t%s,\t%s,\t%s\t#%s\n",(1,2,3,0))
	commanddict["BRNE"] = ("\tbne\t%s,\t%s,\t%s\t#%s\n",(1,2,3,0))
	commanddict["ADDR"] = ("\tadd\t%s,\t$sp,\t%s\t#%s\n",(3,4,0))
	commanddict["DIV"] = ("\tdiv\t%s,\t%s\t\t#%s\n\tmflo\t%s\n",(1,2,0,3))
	commanddict["MOD"] = ("\tdiv\t%s,\t%s\t\t#%s\n\tmfhi\t%s\n",(1,2,0,3))
	commanddict["SUB"] = ("\tsub\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["MULT"] = ("\tmult\t%s,\t%s\t\t#%s\n\tmflo\t%s\n",(1,2,0,3))
	commanddict["ADD"] = ("\tadd\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["ALLOC"] = ("#%s\n",(0))
	commanddict["ASSIGN"] = ("\tmove\t%s,\t%s\t\t#%s\n",(3,1,0))
	commanddict["LOAD"] = ("\tlw\t%s,\t%s($sp)\t\t#%s\n",(3,4,0))
	commanddict["STORE"] = ("\tsw\t%s,\t%s($sp)\t\t#%s\n",(3,4,0))
	commanddict["CAST"] = ("#%s\n",(0))
	commanddict["RETURN"] = ("\tlw\t$ra,\t0($sp)\t\t#%s\n\taddi\t$sp,\t$sp,\t%s\n\tjr\t$ra\n",(0,7))
	commanddict["LEFT"] = ("#%s\n",(0))
	commanddict["RIGHT"] = ("#%s\n",(0))
	commanddict["OR"] = ("#%s\n",(0))
	commanddict["XOR"] = ("#%s\n",(0))
	commanddict["AND"] = ("#%s\n",(0))
	
	floatcommanddict["BREQ"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1t\t%s\n",(1,2,0,3))
	floatcommanddict["BRNE"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1f\t%s\n",(1,2,0,3))
	floatcommanddict["EQ"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli\t%s,\t0\n\tb\tlindown%s\nlinup%s:\n\tli\t%s,\t1\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LT"] = ("\tc.lt.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli\t%s,\t0\n\tb\tlindown%s\nlinup%s:\n\tli\t%s,\t1\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LE"] = ("\tc.le.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli\t%s,\t0\n\tb\tlindown%s\nlinup%s:\n\tli\t%s,\t1\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LOAD"] = ("\tl.d\t%s,\t%s($sp)\t\t#%s\n",(3,4,0))
	floatcommanddict["STORE"] = ("\ts.d\t%s,\t%s($sp)\t\t#%s\n",(3,4,0))
	floatcommanddict["DIV"] = ("\tdiv.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["ADD"] = ("\tadd.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["SUB"] = ("\tsub.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["MULT"] = ("\tmul.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["ASSIGN"] = ("\tmov.d\t%s,\t%s\t\t\t#%s\n",(3,1,0))
	

def castfunc(ticket1,ticket2):
	pass


def registerLife():
	#Ret is always $v0 for ints, chars, and addresses and $v0 upper $v1 lower on doubles
	with open(outfile,'w') as fout:
		fout.write("\t.data\n")
		fout.write("Pi:\t .double\t3.1415926535897924\n")
		fout.write("Rad:\t .double\t12.3444444\n")
		fout.write("\t.text\n")
		
		fout.write("main:\n\tl.d\t$f0,\tPi\t#load pi\n")
		fout.write("\tl.d\t$f4,\tRad\t#load rad\n")
		fout.write("\tc.eq.d\t1\t$f0,\t$f4\t#compare to find flag\n")
		fout.write("\tbc1f\tmain\ntest:\n")
	
	
def genAsm():
	#when using a param, it will add the size of local to the $sp and then get offset from table for the param, this will make it so that the function can unalocate the params at the end.
	pass




if __name__ == '__main__':
	infile = sys.argv[1]
	outfile = sys.argv[2]
	registerLife()
	genAsm()

