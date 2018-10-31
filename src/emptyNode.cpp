/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 20:57:28
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-30 22:34:17
*/
#include "emptyNode.h"

EmptyNode::EmptyNode(int TreeNodeNum, string TreeNodeProductionName):TreeNode(TreeNodeNum,TreeNodeProductionName,0)
{
	
}
EmptyNode::~EmptyNode()
{
	
}
void EmptyNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "%s [style=filled,color=\"0.1 0.1 0.1\"]\n",TreeNodeName.c_str() );
}