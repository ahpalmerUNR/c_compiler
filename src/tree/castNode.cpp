
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
	char typePrint[500] = "0";
	if (currentCodeLine != forErrors[0].source[0].lineNum )
	{
		fprintf(fileout, "# %s",TreeNode::coldLine().c_str() );
		currentCodeLine = forErrors[0].source[0].lineNum;
	}	string s1;
	nodeDataType t = children[0]->getDataType(typePrint);
	s1 = typePrint;
	if(t == ID_TYPE_NODE){ 
		t = children[0]->getidDataType();
		s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
	}
	else
	{
		if(s1 == "0")
				s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
		else
				s1 = "(" + s1 + ")";
		// Because assign
		s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
	}

	fprintf(fileout,"CAST\t%s\t_\t%s\n",s1.c_str(),rep_3ac_ticket(dType,ticketNumber).c_str());
}

int CastNode::returnTicket()
{
	return ticketNumber;
}

void CastNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}
