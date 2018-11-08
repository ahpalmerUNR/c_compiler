#include"relationNode.h"

RelationNode::RelationNode( string nodeName) : TreeNode(nodeName,2)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}

RelationNode::~RelationNode()
{

}

void RelationNode::traverse_to_file(FILE *fileout)
{
	char typePrint[500];
	char operatorPrint[500];
	switch(dType)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint, 500,"Char: ");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint, 500,"Int: ");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint, 500,"Float: ");
			break;
		
	}
	switch(oType)
	{
		case EQ_OP:
			snprintf(operatorPrint, 500,"Left == Right");
			break;
		case NE_OP:
			snprintf(operatorPrint, 500,"Left != Right");
			break;
		case GT_OP:
			snprintf(operatorPrint, 500,"Left > Right");
			break;
		case GE_OP:
			snprintf(operatorPrint, 500,"Left >= Right");
			break;
		case LT_OP:
			snprintf(operatorPrint, 500,"Left < Right");
			break;
		case LE_OP:
			snprintf(operatorPrint, 500,"Left <= Right");
			break;
	}
	fprintf(fileout, "\t%s [label=\"%s %s\"]\n", TreeNodeName.c_str(),typePrint, operatorPrint);
	TreeNode::traverse_to_file(fileout);
}

void RelationNode::ast_to_3ac(FILE *fileout)
{

}

int RelationNode::returnTicket()
{
	return ticketNumber;
}

void RelationNode::setOperator(OperatorType op)
{
	oType = op;
}
void RelationNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}
