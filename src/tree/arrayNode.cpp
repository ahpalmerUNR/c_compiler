#include "arrayNode.h"

ArrayNode::ArrayNode(string nodeName) : TreeNode(nodeName,2)
{

	ticketNumber = Variable_counter;
	++Variable_counter;
	ticketNumber2 = Variable_counter;
	++Variable_counter;
	arrayOffset = 1;
	isLHS = false;
	isFirst = false;
	isLast = false;
	//idDataTypes.push_back(INT_TYPE_NODE);
}

ArrayNode::~ArrayNode()
{

}

void ArrayNode::traverse_to_file(FILE* fileout) 
{
	fprintf(fileout, "\t%s [label=\"Left[Right]\"]\n", TreeNodeName.c_str());
	TreeNode::traverse_to_file(fileout);
}
void ArrayNode::ast_to_3ac(FILE* fileout)
{
	children[0]->ast_to_3ac(fileout);
	children[1]->ast_to_3ac(fileout);
	int realArrayOffset = byteSize * arrayOffset;

	nodeDataType t = dType;
	string s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
	if(t == ID_TYPE_NODE)
	{
		t = children[1]->getidDataType();
		s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
	}

	//children[1]->getDataType(typePrint1);
	//cout<<"byteSize:: "<<byteSize << endl;//<<" typePrint1 "<<typePrint1<<endl;
	if(isFirst)
	{
		fprintf(fileout,"ADDR\t%s\t_\t%s\n",rep_3ac_ticket(children[0]->getidDataType(),children[0]->returnTicket()).c_str(),rep_3ac_ticket(t,Variable_counter).c_str());
	}
	fprintf(fileout, "ASSIGN\t(%d)\t_\t%s\n", realArrayOffset,rep_3ac_ticket(t,ticketNumber2).c_str());
	fprintf(fileout,"MULT\t%s\t%s\t%s\n",s2.c_str(),rep_3ac_ticket(t,ticketNumber2).c_str(),s2.c_str() );
	fprintf(fileout,"ADD\t%s\t%s\t%s\n",rep_3ac_ticket(t,Variable_counter).c_str(),s2.c_str(),rep_3ac_ticket(t,Variable_counter).c_str());
	if(isLast && isLHS)
	{
		fprintf(fileout,"STORE\t%s\t_\t%s\n",rep_3ac_ticket(t,Variable_counter).c_str(),rep_3ac_ticket(t,ticketNumber).c_str());
		Variable_counter++;
	}
	else if(isLast)
	{
		fprintf(fileout,"LOAD\t%s\t_\t%s\n",rep_3ac_ticket(t,Variable_counter).c_str(),rep_3ac_ticket(t,ticketNumber).c_str());
		Variable_counter++;
	}
}

nodeDataType ArrayNode::getidDataType()
{
	//cout << "here " << idDataTypes.size() << endl;
	for(int i = 0; i < idDataTypes.size(); i++)
	{
		if(idDataTypes[i] == (FLOAT_TYPE_NODE || INT_TYPE_NODE || CHAR_TYPE_NODE || DOUBLE_TYPE_NODE))
				return idDataTypes[i];
	}

}
void ArrayNode::setidDataTypes(vector<nodeDataType> types)
{
	idDataTypes = types;
	for(int i = 0; i < idDataTypes.size(); i++)
		switch(idDataTypes[i])
		{
			case CHAR_TYPE_NODE:
				byteSize = CHAR_MIPS;
				break;
			case INT_TYPE_NODE:
				byteSize = INT_MIPS;
				break;
			case DOUBLE_TYPE_NODE:
				byteSize = DOUBLE_MIPS;
				break;
			case FLOAT_TYPE_NODE:
				byteSize = FLOAT_MIPS;
				break;
		}
}
int ArrayNode::returnTicket()
{
	return ticketNumber;
}

void ArrayNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}

nodeDataType ArrayNode::getDataType(char * representation)
{
	snprintf(representation,500,"%s",name);
	return dType;
}

void ArrayNode::errorCheck()
{
		
}
void ArrayNode::implicitCastWarning(nodeDataType t1, nodeDataType t2)
{
	
}

void ArrayNode::setArrayOffset(int i)
{
	arrayOffset = i;
}
int ArrayNode::getArrayOffset()
{
	return arrayOffset;
}
void ArrayNode::setTicketNumber(int t)
{
	ticketNumber = t;
}
int ArrayNode::getTicketNumber()
{
	return ticketNumber;
}
void ArrayNode::setFirst()
{
	isFirst = true;
}
void ArrayNode::setLast()
{
	isLast = true;
}
void ArrayNode::storeString(char *s)
{
	snprintf(name,500,"%s",s);
}
bool ArrayNode::isArrayNode()
{
	return true;
}
void ArrayNode::setLHS()
{
	isLHS = true;
}
