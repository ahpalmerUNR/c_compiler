/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 15:47:00
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-01 19:48:23
*/
#include "labelNode.h"

LabelNode::LabelNode(int TreeNodeNum, string TreeNodeProductionName, int jumpTicket):TreeNode(TreeNodeNum,TreeNodeProductionName,2)
{
	jumpCounter = jumpTicket;
	
	
}

LabelNode::~LabelNode()
{
	
}

void LabelNode::traverse_to_file(FILE* fileout)
{
	// cout<<"LabelNode"<<endl;
	fprintf(fileout, "\t%s [shape = box,color=blue,label=\"Label\"]\n", TreeNodeName.c_str());
	TreeNode::traverse_to_file(fileout);
}

void LabelNode::ast_to_3ac(FILE* fileout)
{
	//add child1.getDataType(repr) and jumpCounter to symbolTable.
	char const_exprRepr[500];
	int a = 0;
	int isID;
	Node* ch1;
	isID=children[0]->getDataType(const_exprRepr);
	if (isID == ID_TYPE_NODE)
	{
		ch1 = astTable.searchAll(const_exprRepr,&a);
		if (ch1 ==NULL)
		{
			ch1 = astTable.insert(const_exprRepr,jumpCounter,0,INT_TYPE,&a);
		}
	}
	else
	{
		ch1 = astTable.insert(const_exprRepr,jumpCounter,0,INT_TYPE,&a);
	}

	if (a >= 1)
	{
		jumpCounter = ch1->lineNumber;
	}
	fprintf(fileout, "LABEL\t%d\n",jumpCounter);
	children[1]->ast_to_3ac(fileout);	
}