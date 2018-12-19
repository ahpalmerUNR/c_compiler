/**
 * @file emptyIterNode.cpp
 * @author Nathan Yocum
 * @version 0.1
 * @date 2018
 */
#include "emptyIterNode.h"

EmptyIterNode::EmptyIterNode(string TreeNodeProductionName):TreeNode(TreeNodeProductionName,0)
{
	dType = EMPTY_ITER_TYPE_NODE;
}
EmptyIterNode::~EmptyIterNode()
{
	
}
void EmptyIterNode::traverse_to_file(FILE* fileout)
{
	// cout<<"EmptyIterNode"<<endl;
	fprintf(fileout, "\t%s [style=filled,color=indigo,fontcolor=white]\n",TreeNodeName.c_str() );
}

nodeDataType EmptyIterNode::getDataType(char *)
{
	return dType;
}