/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 20:57:28
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-22 11:12:27
*/
#include "emptyNode.h"

EmptyNode::EmptyNode(string TreeNodeProductionName):TreeNode(TreeNodeProductionName,0)
{
	dType = EMPTY_TYPE_NODE;
}
EmptyNode::~EmptyNode()
{
	
}
void EmptyNode::traverse_to_file(FILE* fileout)
{
	// cout<<"EmptyNode"<<endl;
	fprintf(fileout, "\t%s [style=filled,color=indigo,fontcolor=white]\n",TreeNodeName.c_str() );
}

nodeDataType EmptyNode::getDataType(char *)
{
	return dType;
}