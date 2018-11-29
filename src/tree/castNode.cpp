
#include "castNode.h"

CastNode::CastNode(string nodeName): TreeNode(nodeName,1)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}

CastNode::~CastNode()
{

}
nodeDataType CastNode::getDataType(char *c)
{
	return dType;
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
		case FLOAT_TYPE_NODE:
			snprintf(typePrint, 500,"Float");
			break;
		default:
			snprintf(typePrint, 500,"Error probably with id");
			break;
	}
	fprintf(fileout, "\t%s [label=\"Cast(%s)\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
			
}

void CastNode::ast_to_3ac(FILE* fileout)
{
	children[0]->ast_to_3ac(fileout);
	char typePrint[500];
	char typePrint2[500];
	char typePrint3[500];
	switch(dType)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint, 500,"(Char)");
			snprintf(typePrint2, 500,"c");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint, 500,"(Int)");
			snprintf(typePrint2, 500,"i");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint, 500,"(Float)");
			snprintf(typePrint2, 500,"f");
			break;
		case FLOAT_TYPE_NODE:
			snprintf(typePrint, 500,"(Float)");
			snprintf(typePrint2, 500,"f");
			break;
		default:
			snprintf(typePrint2, 500,"Error probably with id");
			break;
	}
	nodeDataType t = children[0]->getDataType(typePrint3);
	if(t == ID_TYPE_NODE)
		t = children[0]->getidDataType();
	switch(t)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint3, 500,"c");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint3, 500,"i");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint3, 500,"f");
			break;
		case FLOAT_TYPE_NODE:
			snprintf(typePrint3, 500,"f");
			break;
		default:
			snprintf(typePrint3, 500,"Error probably with id");
			break;
	}
	fprintf(fileout,"CAST\t%s%i\t_\t%s\n",typePrint3,children[0]->returnTicket(),rep_3ac_ticket(dType,ticketNumber).c_str());
}

int CastNode::returnTicket()
{
	return ticketNumber;
}

void CastNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}
