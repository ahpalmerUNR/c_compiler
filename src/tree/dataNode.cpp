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
	fprintf(fileout, "\t%s [label=\"%s\\n%d\\n%c\\n%f\"]\n", TreeNodeName.c_str(),data.dstr,data.dint,data.dchar,data.ddoub);
}
void DataNode::ast_to_3ac(FILE* fileout)
{

}

void DataNode::storeChar(char c)
{
	data.dchar = c;
	dType = CHAR_TYPE_NODE;
}
void DataNode::storeInt(int i)
{
	data.dint = i;
	dType = INT_TYPE_NODE;
}
void DataNode::storeDouble(double d)
{
	data.ddoub = d;
	dType = DOUBLE_TYPE_NODE;
}
void DataNode::storeString(char *s)
{
	data.dstr = s;
	dType = STRING_TYPE_NODE;
}

int DataNode::returnTicket()
{
	return ticketNumber;
}
