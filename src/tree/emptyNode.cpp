/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 20:57:28
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-07 13:29:12
*/
#include "emptyNode.h"

EmptyNode::EmptyNode(int TreeNodeNum, string TreeNodeProductionName,int line,int col, string source):TreeNode(TreeNodeNum,TreeNodeProductionName,0,line,col,source)
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

int EmptyNode::getDataType(char *)
{
	return dType;
}