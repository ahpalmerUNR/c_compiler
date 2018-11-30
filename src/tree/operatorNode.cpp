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
{fprintf(fileout, "#%s",TreeNode::coldLine().c_str() );
	children[0]->ast_to_3ac(fileout);
	char typePrint[500];
	char typePrint2[500];
	dType = children[0]->getDataType(typePrint);
	if(dType == ID_TYPE_NODE)
		dType = children[0]->getidDataType();
	string s2 = rep_3ac_ticket(dType,ticketNumber);
	string s1 = rep_3ac_ticket(dType,children[0]->returnTicket());
	switch(oType)
	{
		case AMP_op:
			snprintf(typePrint, 500,"AMP");
			break;
		case STAR_op:
			snprintf(typePrint, 500,"STAR");
			break;
		case PLUS_op:
			snprintf(typePrint, 500,"PLUS");
			break;
		case MINUS_op:
			snprintf(typePrint, 500,"MINUS");
			break;
		case TILDA_op:
			snprintf(typePrint, 500,"TILDA");
			break;
		case NOT_op:
			snprintf(typePrint, 500,"NOT");
			break;
		case INC_op:
			snprintf(typePrint, 500,"INC");
			//maybe since inc and dec store the value back 
			s1 = s2;
			ticketNumber = children[0]->returnTicket();
			break;
		case DEC_op:
			snprintf(typePrint, 500,"DEC");
			//maybe
			s1 = s2;
			ticketNumber = children[0]->returnTicket();
			break;
	}
	fprintf(fileout, "%s\t%s\t_\t%s\n",typePrint,s1.c_str(),s2.c_str());
}
int OperatorNode::returnTicket()
{
	return ticketNumber;
}
