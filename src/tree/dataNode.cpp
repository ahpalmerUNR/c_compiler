#include"dataNode.h"

DataNode::DataNode(int nodeNumber, string nodeName, int ticket) : TreeNode(nodeNumber,nodeName,0)
{
	ticketNumber = ticket;
}

DataNode::~DataNode()
{

}

void DataNode::traverse_to_file(FILE* fileout) 
{
	fprintf(fileout, "\t%s [label=\"DataLiteral\"]\n", TreeNodeName.c_str());
}
void DataNode::ast_to_3ac(FILE* fileout)
{

}

void DataNode::storeChar(char c)
{
	data.dchar = c;
}
void DataNode::storeInt(int i)
{
	data.dint = i;
}
void DataNode::storeDouble(double d)
{
	data.ddoub = d;
}
void DataNode::storeString(char *s)
{
	data.dstr = s;
}

int DataNode::returnTicket()
{
	return ticketNumber;
}
