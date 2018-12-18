# -*- coding: utf-8 -*-
# @Author: ahpalmerUNR
# @Date:   2018-12-16 22:22:02
# @Last Modified by:   ahpalmerUNR
# @Last Modified time: 2018-12-17 20:08:29
import sys

infile = ""
outfile = ""

intsize = 4
charsize = 4
floatsize = 8
doublesize = 8

currentBlock = 0

procParamSize = 0
procLocalSize = 0
scopeParamLocal = []

commanddict = {}
floatcommanddict = {}

reginfotable={}#Start line, endline, where current found, istemp, isparam, memory location,  varsize,block endline

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
	commanddict["ENDPROC"] = ("\tjr\t$ra\t\t\t#%s\n",(0))
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
	
def allocfunc(ticket1):
	pass
	
def callfunc(argtup,fout):
	pass

def getLiteral(instring,outType):
	instring = instring.strip("(").strip(")")
	# print(instring)
	if outType == 'i':
		return int(instring)
	elif outType == 'f':
		return float(instring)
	elif outType == 'c':
		return ord(instring)

def decode(inlist,linenum):
	# i,f,c,l are ticket prefixes
	global procParamSize, procLocalSize,scopeParamLocal
	if inlist[0]=="PROCENTRY":
		procParamSize = getLiteral(inlist[2],'i')
		procLocalSize = getLiteral(inlist[3],'i')
		# print(procParamSize,procLocalSize)
		
	elif inlist[0]=="ALLOC":
		if procParamSize - getLiteral(inlist[1],'i') >= 0:
			procParamSize = procParamSize - getLiteral(inlist[1],'i')
			reginfotable[inlist[3]]={"startline":linenum, "isparam":True,"varsize":getLiteral(inlist[1],'i'),"istemp":False,"endline":linenum}
		else:
			procLocalSize = procLocalSize - getLiteral(inlist[1],'i')
			reginfotable[inlist[3]]={"startline":linenum, "isparam":False,"varsize":getLiteral(inlist[1],'i'),"istemp":False,"endline":linenum}
		scopeParamLocal.append(inlist[3])
		
	elif inlist[0]=="ENDPROC":
		for x in scopeParamLocal:
			reginfotable[x]["blockendline"] = linenum
		scopeParamLocal = []
			
	else:
		for x in inlist[1:]:
			if x != 'ret' and x[0]!='(' and x[0]!='l' and x[0]!='_':
				if x in reginfotable:
					reginfotable[x]["endline"]=linenum
				else:
					# print(x[0],"firstchar_____________")
					if x[0]=='i':
						sizetmp = intsize
					elif x[0]=='f':
						sizetmp = floatsize
					elif x[0]=='c':
						sizetmp = charsize
					reginfotable[x]={"startline":linenum, "isparam":False,"varsize":sizetmp,"istemp":True,"endline":linenum}
					scopeParamLocal.append(inlist[3])
	# print(inlist,linenum)
	pass

def registerLife():
	#Ret is always $v0 for ints, chars, and addresses and $v0 upper $v1 lower on doubles
	# registers = {"ret":"$v0",""}
	with open(infile,'r') as fin:
		for count, line in enumerate(fin):
			line = line.rstrip()
			incount = count + 1
			spots = line.split('\t')
			if spots[0][0]=="#":
				pass
			else:
				decode(spots,incount)
	# print(reginfotable)
	
	
def genAsm():
	#when using a param, it will add the size of local to the $sp and then get offset from table for the param, this will make it so that the function can unalocate the params at the end.
	#
	#the following is just to test output to mips
	with open(outfile,'w') as fout:
		fout.write("\t.data\n")
		fout.write("Pi:\t .double\t3.1415926535897924\n")
		fout.write("Rad:\t .double\t12.3444444\n")
		fout.write("\t.text\n")
		
		fout.write("main:\n\tl.d\t$f0,\tPi\t#load pi\n")
		fout.write("\tl.d\t$f4,\tRad\t#load rad\n")
		fout.write("\tc.eq.d\t1\t$f0,\t$f4\t#compare to find flag\n")
		fout.write("\tbc1f\tmain\ntest:\n")
	




if __name__ == '__main__':
	infile = sys.argv[1]
	outfile = sys.argv[2]
	registerLife()
	genAsm()

