#include"functionCallNode.h"
FunctionCallNode::FunctionCallNode(string nodeName) : TreeNode(nodeName,2)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}
FunctionCallNode::~FunctionCallNode()
{

}

void FunctionCallNode::traverse_to_file(FILE* fileout)
{
	cout << "function traverse" << endl;
	cout.flush();
	fprintf(fileout, "\t%s [label=\"Left(Right)\"]\n", TreeNodeName.c_str());
	TreeNode::traverse_to_file(fileout);
}
void FunctionCallNode::ast_to_3ac(FILE* fileout)
{
	TreeNode::ast_to_3ac(fileout);
}

int FunctionCallNode::returnTicket()
{
	return ticketNumber;
}
void FunctionCallNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}
nodeDataType FunctionCallNode::getDataType(char * representation)
{
	return dType;
}
void FunctionCallNode::errorCheck()
{

}
void FunctionCallNode::implicitCastWarning(nodeDataType t1, nodeDataType t2)
{

}
void FunctionCallNode::setidDataTypes(vector<nodeDataType> n)
{

}
nodeDataType FunctionCallNode::getidDataType()
{
	return dType;
}
void FunctionCallNode::storeString(char *string)
{
	snprintf(funcName,500,"%s",string);
}
void FunctionCallNode::setParamTickets(vector<int> pT)
{
	paramTicketNumbers = pT;
}
void FunctionCallNode::setParamDataTypes(vector<nodeDataType> pT)
{
	paramDataTypes = pT;
}



