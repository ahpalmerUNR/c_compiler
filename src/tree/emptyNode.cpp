/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 20:57:28
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-01 19:47:54
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
	// cout<<"EmptyNode"<<endl;
	fprintf(fileout, "%s [style=filled,color=indigo,fontcolor=white]\n",TreeNodeName.c_str() );
}