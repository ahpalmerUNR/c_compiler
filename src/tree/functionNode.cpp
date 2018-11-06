/*
* @Author: ahpalmerUNR
* @Date:   2018-11-05 15:44:49
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-06 15:03:58
*/
#include "functionNode.h"

using namespace std;

FunctionNode::FunctionNode(int TreeNodeNum, string TreeNodeProductionName, int jumpticket1, int jumpticket2, int jumpticket3, int jumpticket4, int variableticket):TreeNode(TreeNode,TreeNodeProductionName,4)
{
	jumpTick1 = jumpticket1;
	jumpTick2 = jumpticket2;
	jumpTick3 = jumpticket3;
	jumpTick4 = jumpticket4;
	variableTick = variableticket;
	name = functName;
}

FunctionNode::~FunctionNode()
{

}

void FunctionNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "\t%s [shape=doubleoctagon,color=red,label=\"%s\"\n", TreenodeName,functName);
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
