
#include "castNode.h"

CastNode::CastNode(int nodeNumber, string nodeName, int ticket,int line,int col, string source): TreeNode(nodeNumber,nodeName,1,line,col,source)
{
	ticketNumber = ticket;
}

CastNode::~CastNode()
{

}

void CastNode::traverse_to_file(FILE* fileout)
{
	char typePrint[500];
	switch(dType)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint, 500,"Char");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint, 500,"Int");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint, 500,"Float");
			break;
	}
	fprintf(fileout, "\t%s [label=\"Cast(%s)\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
			
}

void CastNode::ast_to_3ac(FILE* fileout)
{

}

int CastNode::returnTicket()
{
	return ticketNumber;
}

void CastNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}