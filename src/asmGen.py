# -*- coding: utf-8 -*-
# @Author: ahpalmerUNR
# @Date:   2018-12-16 22:22:02
# @Last Modified by:   ahpalmerUNR
# @Last Modified time: 2018-12-18 14:58:26
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
inuseticks = []

commanddict = {}
floatcommanddict = {}

reginfotable={}#Start line, endline, where current found, istemp, isparam, memory location,  varsize,block endline
reginfotable['ret']={"curloc":"$v0","startline":-1, "isparam":False,"varsize":intsize,"istemp":True,"endline":-1}

regOrder = [[False,'$t0'],[False,'$t1'],[False,'$t2'],[False,'$t3'],[False,'$t4'],[False,'$t5'],[False,'$t6'],[False,'$t7'],[False,'$t8'],[False,'$t9'],[False,'$s0'],[False,'$s1'],[False,'$s2'],[False,'$s3'],[False,'$s4'],[False,'$s5'],[False,'$s6'],[False,'$s7'],[False,'$a0'],[False,'$a1'],[False,'$a2'],[False,'$a3']]
floatregOrder = [[False,'$f0'],[False,'$f2'],[False,'$f4'],[False,'$f6'],[False,'$f8'],[False,'$f10'],[False,'$f12'],[False,'$f14'],[False,'$f16'],[False,'$f18'],[False,'$fs0'],[False,'$f22'],[False,'$f24'],[False,'$f26'],[False,'$f28'],[False,'$f30']]

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
	#10 raw arg1
	#11 raw arg2
	#12 raw arg3 
	global commanddict,floatcommanddict
	commanddict["#"] = ("#%s\n",(0,))
	commanddict["BR"] = ("\tb\t%s\t\t\t#%s\n",(12,0))
	commanddict["EQ"] = ("\tseq\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["NE"] = ("\tsne\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["GT"] = ("\tsgt\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["GE"] = ("\tsge\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["LT"] = ("\tsge\t%s,\t%s,\t%s\t#%s\n\tnot\t%s\t%s\n",(3,1,2,0,3,3))
	commanddict["LE"] = ("\tsle\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["PROCENTRY"] = ("%s:\t\t\t\t\t#%s\n\taddi\t$sp,\t$sp,\t-%s\n\tsw\t$ra,\t0($sp)\n",(10,0,8))
	commanddict["ENDPROC"] = ("\tjr\t$ra\t\t\t#%s\n",(0,))
	commanddict["CALL"] = ("\tjal\t%s\t\t\t#%s\n",(10,0))
	commanddict["REFOUT"] = ("#%s\n",(0,))
	commanddict["VALOUT"] = ("#%s\n",(0,))
	commanddict["ARGS"] = ("#%s\n",(0,))
	commanddict["LABEL"] = ("%s:\t\t\t\t\t#%s\n",(10,0))
	commanddict["BREQ"] = ("\tbeq\t%s,\t%s,\t%s\t#%s\n",(1,2,12,0))
	commanddict["BRNE"] = ("\tbne\t%s,\t%s,\t%s\t#%s\n",(1,2,12,0))
	commanddict["ADDR"] = ("\tadd\t%s,\t$sp,\t%s\t#%s\n",(3,4,0))
	commanddict["DIV"] = ("\tdiv\t%s,\t%s\t\t#%s\n\tmflo\t%s\n",(1,2,0,3))
	commanddict["MOD"] = ("\tdiv\t%s,\t%s\t\t#%s\n\tmfhi\t%s\n",(1,2,0,3))
	commanddict["SUB"] = ("\tsub\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["MULT"] = ("\tmult\t%s,\t%s\t\t#%s\n\tmflo\t%s\n",(1,2,0,3))
	commanddict["ADD"] = ("\tadd\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	commanddict["ALLOC"] = ("#%s\n",(0,))
	commanddict["ASSIGN"] = ("\tmove\t%s,\t%s\t\t#%s\n",(3,1,0))
	commanddict["LOAD"] = ("\tlw\t%s,\t%s($sp)\t\t#%s\n",(3,6,0))
	commanddict["STORE"] = ("\tsw\t%s,\t%s($sp)\t\t#%s\n",(3,6,0))
	commanddict["CAST"] = ("#%s\n",(0,))
	commanddict["RETURN"] = ("\tlw\t$ra,\t0($sp)\t\t#%s\n\taddi\t$sp,\t$sp,\t%s\n\tjr\t$ra\n",(0,7))
	commanddict["LEFT"] = ("#%s\n",(0,))
	commanddict["RIGHT"] = ("#%s\n",(0,))
	commanddict["OR"] = ("#%s\n",(0,))
	commanddict["XOR"] = ("#%s\n",(0,))
	commanddict["AND"] = ("#%s\n",(0,))
	
	floatcommanddict["BREQ"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1t\t%s\n",(1,2,0,12))
	floatcommanddict["BRNE"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1f\t%s\n",(1,2,0,12))
	floatcommanddict["EQ"] = ("\tc.eq.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli.d\t%s,\t0.0\n\tb\tlindown%s\nlinup%s:\n\tli.d\t%s,\t1.0\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LT"] = ("\tc.lt.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli.d\t%s,\t0.0\n\tb\tlindown%s\nlinup%s:\n\tli.d\t%s,\t1.0\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LE"] = ("\tc.le.d\t%s,\t%s\t\t#%s\n\tbc1t\tlinup%s\n\tli.d\t%s,\t0.0\n\tb\tlindown%s\nlinup%s:\n\tli.d\t%s,\t1.0\nlindown%s:\n",(1,2,0,9,3,9,9,3,9))
	floatcommanddict["LOAD"] = ("\tl.d\t%s,\t%s($sp)\t\t#%s\n",(3,6,0))
	floatcommanddict["STORE"] = ("\ts.d\t%s,\t%s($sp)\t\t#%s\n",(3,6,0))
	floatcommanddict["DIV"] = ("\tdiv.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["ADD"] = ("\tadd.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["SUB"] = ("\tsub.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["MULT"] = ("\tmul.d\t%s,\t%s,\t%s\t#%s\n",(3,1,2,0))
	floatcommanddict["ASSIGN"] = ("\tmov.d\t%s,\t%s\t\t\t#%s\n",(3,1,0))


def castfunc(ticket1,ticket2,fout):
	if (ticket1[0]=='i' and ticket2[0]=='f') or (ticket1[0]=='c' and ticket2[0]=='f'):
		fout.write("\tcvt.d.w\t%s\t%s\n"%(reginfotable[ticket2]['curloc'],reginfotable[ticket1]['curloc']))
	elif (ticket1[0]=='f' and ticket2[0]=='i') or (ticket1[0]=='f' and ticket2[0]=='c'):
		fout.write("\tcvt.w.d\t%s\t%s\n"%(reginfotable[ticket2]['curloc'],reginfotable[ticket1]['curloc']))
	
def allocfunc(ticket1,memoffset):
	pass
	
def callfunc(argtup,fout):
	cumulative = 0
	sizetoask = 0
	# ask for space on stack equal to size of params
	for x in argtup:
		sizetoask = sizetoask + reginfotable[x]['varsize']
	
	# print(reginfotable[argtup[0]],"THIS IS THE ARGTUPLE")
	fout.write("\taddi\t$sp,\t$sp,\t-%d\n"%(sizetoask))	
	# iterate over param registers and save in stack 
	for x in argtup:
		fout.write("\tsw\t%s,\t%s($sp)\t\t#%s\n"%(reginfotable[x]['curloc'],cumulative," "))
		cumulative = cumulative + reginfotable[x]['varsize']

def getreg(ticket):
	global regOrder,reginfotable,inuseticks
	found = -1
	for x in regOrder:
		if x[0] == False:
			found = x[1]
			x[0] = True
			break
	reginfotable[ticket]['curloc'] = found
	inuseticks.append(ticket)

def returnreg(ticket):
	global regOrder, reginfotable,inuseticks
	found = reginfotable[ticket]['curloc']
	for x in regOrder:
		if x[1] == found:
			reginfotable[ticket]['curloc'] = -1
			x[0] = False
			break
	inuseticks.remove(ticket)
	
def getfloatreg(ticket):
	global floatregOrder,reginfotable,inuseticks
	found = -1
	for x in floatregOrder:
		if x[0] == False:
			found = x[1]
			x[0] = True
			break
	reginfotable[ticket]['curloc'] = found
	inuseticks.append(ticket)
	
def returnfloatreg(ticket):
	global floatregOrder, reginfotable,inuseticks
	found = reginfotable[ticket]['curloc']
	for x in floatregOrder:
		if x[1] == found:
			reginfotable[ticket]['curloc'] = -1
			x[0] = False
			break	
			
	inuseticks.remove(ticket)
			
def getouttup(tuporder,ticket1,ticket2,ticket3,stacksize,localsize,linenum,lineprint):
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
	#10 raw arg1
	#11 raw arg2
	#12 raw arg3 
	global reginfotable
	outorder = []
	for x in tuporder:
		if x == 0:
			outorder.append(lineprint)
		elif x == 1:
			if reginfotable[ticket1]['curloc'] ==-1:
				if ticket1[0]=='i' or ticket1[0]=='c':
					getreg(ticket1)
				elif ticket1[0]=='f':
					getfloatreg(ticket1)
			outorder.append(reginfotable[ticket1]['curloc'])
		elif x == 2:
			if reginfotable[ticket2]['curloc'] ==-1:
				if ticket2[0]=='i' or ticket2[0]=='c':
					getreg(ticket2)
				elif ticket2[0]=='f':
					getfloatreg(ticket2)
			outorder.append(reginfotable[ticket2]['curloc'])
		elif x == 3:
			if reginfotable[ticket3]['curloc'] ==-1:
				if ticket3[0]=='i' or ticket3[0]=='c':
					getreg(ticket3)
				elif ticket3[0]=='f':
					getfloatreg(ticket3)
			outorder.append(reginfotable[ticket3]['curloc'])
		elif x == 4:
			outorder.append(str(reginfotable[ticket1]['memloc']))
		elif x == 5:
			outorder.append(str(reginfotable[ticket2]['memloc']))
		elif x == 6:
			outorder.append(str(reginfotable[ticket3]['memloc']))
		elif x == 7:
			outorder.append(str(stacksize))
		elif x == 8:
			outorder.append(str(localsize))
		elif x == 9:
			outorder.append(str(linenum))
		elif x == 10:
			outorder.append(ticket1)
		elif x == 11:
			outorder.append(ticket2)
		elif x == 12:
			outorder.append(ticket3)
			
	return tuple(outorder)

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
	sizetmp = 0
	if inlist[0]=="PROCENTRY":
		procParamSize = getLiteral(inlist[2],'i')
		procLocalSize = getLiteral(inlist[3],'i')
		# print(procParamSize,procLocalSize)
		
	elif inlist[0]=="ALLOC":
		if procParamSize - getLiteral(inlist[1],'i') >= 0:
			procParamSize = procParamSize - getLiteral(inlist[1],'i')
			reginfotable[inlist[3]]={"curloc":-1,"startline":linenum, "isparam":True,"varsize":getLiteral(inlist[1],'i'),"istemp":False,"endline":linenum}
		else:
			procLocalSize = procLocalSize - getLiteral(inlist[1],'i')
			reginfotable[inlist[3]]={"curloc":-1,"startline":linenum, "isparam":False,"varsize":getLiteral(inlist[1],'i'),"istemp":False,"endline":linenum}
		if inlist[3]!='_':
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
					reginfotable[x]={"curloc":-1,"startline":linenum, "isparam":False,"varsize":sizetmp,"istemp":True,"endline":linenum}
					if inlist[3]!='_':
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
	
		fin.close()
	# print(reginfotable)
	# 
def printreadwrite(fout):
	with open("src/asm-lib/ReadInt.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);
			
	with open("src/asm-lib/ReadFloat.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);
			
	with open("src/asm-lib/ReadChar.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);
			
			
	with open("src/asm-lib/WriteInt.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);
			
	with open("src/asm-lib/WriteInt.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);
			
			
	with open("src/asm-lib/WriteInt.asm",'r') as ffin:
		for line in ffin:
			fout.write(line);

	
	
def genAsm():
	#when using a param, it will add the size of local to the $sp and then get offset from table for the param, this will make it so that the function can unalocate the params at the end.
	#
	#regOrder is the order of importance for registers we will use for variables, when all are used, we save off to the stack 
	global regOrder,floatregOrder,commanddict,floatcommanddict,procParamSize, procLocalSize,reginfotable,inuseticks
	
	argsum = 0
	callargs = []
	
	fin = open(infile,'r')
	with open(outfile,'w') as fout:
		for count, line in enumerate(fin):
			line = line.rstrip()
			incount = count + 1
			spots = line.split('\t')
			if spots[0]=='CAST':
				if reginfotable[spots[3]]['curloc']==-1:
					if spots[3][0]=='i' or spots[3][0]=='c':
						getreg(spots[3])
					elif spots[3][0]=='f':
						getfloatreg(spots[3])
				fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
				castfunc(spots[1],spots[3],fout)
			elif spots[0]=="ASSIGN":
				if spots[1][0]=='(':
					if reginfotable[spots[3]]['curloc']==-1:
						if spots[3][0]=='i' or spots[3][0]=='c':
							getreg(spots[3])
						elif spots[3][0]=='f':
							getfloatreg(spots[3])
					if spots[3][0]=='f':
						fout.write('\tli.d\t%s,\t%s\t\t#%s\n'%(reginfotable[spots[3]]['curloc'],getLiteral(spots[1],spots[3][0]),line))
					else:
						fout.write('\tli\t%s,\t%s\t\t#%s\n'%(reginfotable[spots[3]]['curloc'],getLiteral(spots[1],spots[3][0]),line))
				elif spots[1][0]=='f':
					# if reginfotable[spots[3]]['curloc']==-1:
					# 	getfloatreg(spots[3])
					fout.write(floatcommanddict[spots[0]][0]%getouttup(floatcommanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
				else:
					# if reginfotable[spots[3]]['curloc']==-1:
					# 	getreg(spots[3])
					fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
				if reginfotable[spots[3]]['istemp']==False:
					fout.write(commanddict["STORE"][0]%getouttup(commanddict['STORE'][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
					
			elif spots[0]=="ALLOC":
				if reginfotable[spots[3]]['isparam']:
					reginfotable[spots[3]]['memloc']=argsum+procLocalSize
					if spots[3][0]=='f':
						fout.write(floatcommanddict["LOAD"][0]%getouttup(floatcommanddict['LOAD'][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
					else:
						fout.write(commanddict["LOAD"][0]%getouttup(commanddict['LOAD'][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
					argsum = argsum + getLiteral(spots[1],'i')
					if argsum == procParamSize:
						argsum = 0
				else:
					reginfotable[spots[3]]['memloc']=argsum + 4
					argsum = argsum + getLiteral(spots[1],'i')
					if argsum + 4 == procLocalSize:
						argsum = 0
				
			elif spots[0] == "PROCENTRY":
				procParamSize = getLiteral(spots[2],'i')
				procLocalSize = getLiteral(spots[3],'i') + 4
				fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
				# argsum = procParamSize
			# elif spots[0]=="ARGS":
			# 	# callargs = [0 for a in range(getLiteral(spots[1],'i'))]
			# 	fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
			elif spots[0]=="REFOUT" or spots[0]=="VALOUT":
				callargs.append(spots[1])
				fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
			elif spots[0]=="CALL":
				callfunc(callargs,fout)
				fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
			elif spots[0][0]=="#":
				fout.write(commanddict["#"][0]%(line));
			else:
				if spots[1][0]=='f':
					fout.write(floatcommanddict[spots[0]][0]%getouttup(floatcommanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
				else:
					fout.write(commanddict[spots[0]][0]%getouttup(commanddict[spots[0]][1],spots[1],spots[2],spots[3],procParamSize+procLocalSize,procLocalSize,incount,line))
			for tick in inuseticks:
				if reginfotable[tick]['endline']==incount and reginfotable[tick]['istemp']==True:
					if tick[0]=='f':
						returnfloatreg(tick)
					else:
						returnreg(tick)
				elif reginfotable[tick]['blockendline']==incount and reginfotable[tick]['istemp']==False:
					if tick[0]=='f':
						returnfloatreg(tick)
					else:
						returnreg(tick)
			# if spots[0][0]=="#":
			# 	pass
			# else:
			# 	decode(spots,incount)
		printreadwrite(fout)
		
	fin.close()
	
	




if __name__ == '__main__':
	infile = sys.argv[1]
	outfile = sys.argv[2]
	populateCommands()
	registerLife()
	genAsm()
	

