#include "operatorNode.h"

OperatorNode::OperatorNode(int nodeNumber, string nodeName, OperatorType2 t, int numChildren,int line,int col, string source) : TreeNode(nodeNumber,nodeName,numChildren,line,col,source)
{
	oType = t;
}

OperatorNode::~OperatorNode()
{

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

}
