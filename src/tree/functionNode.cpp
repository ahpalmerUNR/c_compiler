/*
* @Author: ahpalmerUNR
* @Date:   2018-11-05 15:44:49
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-07 13:26:13
*/
#include "functionNode.h"

using namespace std;

FunctionNode::FunctionNode(int TreeNodeNum, string TreeNodeProductionName, int variableticket,int line,int col, string source):TreeNode(TreeNodeNum,TreeNodeProductionName,4,line,col,source)
{
	variableTick = variableticket;
}

FunctionNode::~FunctionNode()
{

}

void FunctionNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "\t%s [shape=doubleoctagon,color=red,label=\"%s\"]\n", TreeNodeName.c_str(),functName.c_str());
	TreeNode::traverse_to_file(fileout);
}

void FunctionNode::ast_to_3ac(FILE* fileout)
{

}

int FunctionNode::getDataType()
{

}

int FunctionNode::returnTicket()
{

}

void FunctionNode::errorCheck()
{
	char temp[500];
	if (children[1]->getDataType(temp)==ID_TYPE_NODE)
	{
		functName.assign(temp);
	}
	else
	{
		yyerror("No function name.");
	}
	if (children[0]->getDataType(temp)==EMPTY_TYPE_NODE)
	{
		yyerror("Warning: No return type specified for function.");
	}
	else
	{
		//set return type
	}
	if (children[2]->getDataType(temp)!=EMPTY_TYPE_NODE)
	{
		//set param types
	}
	
	
}
