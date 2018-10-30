/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 15:47:00
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-30 16:55:59
*/
#include "labelNode.h"

LabelNode::LabelNode(int TreeNodeNum, string TreeNodeProductionName, int jumpTicket):TreeNode(TreeNodeNum,TreeNodeProductionName,1)
{
	jumpCounter = jumpTicket;
}

LabelNode::~LabelNode()
{
	
}

void LabelNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "%s [shape = box,color=blue,label=\"Label\"]\n", TreeNodeName.c_str());
	TreeNode::traverse_to_file(fileout);
}

void LabelNode::ast_to_3ac(FILE* fileout)
{
	fprintf(fileout, "LABEL\t%d\n",jumpCounter);
	children[0]->ast_to_3ac(fileout);	
}