/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 20:57:28
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-31 17:11:45
*/
#include "emptyNode.h"

using namespace std;

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