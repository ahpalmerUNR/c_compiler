#include "operatorNode.h"

OperatorNode::OperatorNode(string nodeName, OperatorType2 t, int numChildren) : TreeNode(nodeName,numChildren)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
	oType = t;
}

OperatorNode::~OperatorNode()
{

}
nodeDataType OperatorNode::getDataType(char *c)
{
	return dType;
}
void OperatorNode::traverse_to_file(FILE* fileout) 
{
	char typePrint[500];
	
	switch(oType)
	{
		case AMP_op:
			snprintf(typePrint, 500,"&");
			break;
		case STAR_op:
			snprintf(typePrint, 500,"*");
			break;
		case PLUS_op:
			snprintf(typePrint, 500,"+");
			break;
		case MINUS_op:
			snprintf(typePrint, 500,"-");
			break;
		case TILDA_op:
			snprintf(typePrint, 500,"~");
			break;
		case NOT_op:
			snprintf(typePrint, 500,"!");
			break;
		case INC_op:
			snprintf(typePrint, 500,"++");
			break;
		case DEC_op:
			snprintf(typePrint, 500,"--");
			break;
	}
	// cout<<"Data Node "<<TreeNodeName<<endl;
	fprintf(fileout, "\t%s [label=\"%s\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
}
void OperatorNode::ast_to_3ac(FILE* fileout)
{
	children[0]->ast_to_3ac(fileout);
	char typePrint[500];
	char typePrint2[500];
	dType = children[0]->getDataType(typePrint);
	if(dType == ID_TYPE_NODE)
		dType = children[0]->getidDataType();
	string opString;
	switch(dType)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint2, 500,"c");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint2, 500,"i");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint2, 500,"f");
			break;
		case FLOAT_TYPE_NODE:
			snprintf(typePrint2, 500,"f");
			break;
	}
	switch(oType)
	{
		case AMP_op:
			snprintf(typePrint, 500,"&");
			break;
		case STAR_op:
			snprintf(typePrint, 500,"*");
			break;
		case PLUS_op:
			snprintf(typePrint, 500,"+");
			break;
		case MINUS_op:
			snprintf(typePrint, 500,"-");
			break;
		case TILDA_op:
			snprintf(typePrint, 500,"~");
			break;
		case NOT_op:
			snprintf(typePrint, 500,"!");
			break;
		case INC_op:
			snprintf(typePrint, 500,"++");
			break;
		case DEC_op:
			snprintf(typePrint, 500,"--");
			break;
	}
	fprintf(fileout, "%s%i=%s%s%i\n",typePrint2,ticketNumber, typePrint, typePrint2, children[0]->returnTicket());
}
int OperatorNode::returnTicket()
{
	return ticketNumber;
}
