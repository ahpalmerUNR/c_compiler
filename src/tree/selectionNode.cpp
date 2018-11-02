/*
* @Author: ahpalmerUNR
* @Date:   2018-10-31 11:49:36
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-01 21:04:51
*/
#include "selectionNode.h"

SelectionNode::SelectionNode(int TreeNodeNum, string TreeNodeProductionName,int numChildren,bool isaSwitch, int jumpTicket1,int jumpTicket2,int jumpTicket3):TreeNode(TreeNodeNumber,TreeNodeProductionName,numChildren)
{
	jticket1 = jumpTicket1;
	jticket2 = jumpTicket2;
	jticket3 = jumpTicket3;
	isSwitch = isaSwitch;
}
SelectionNode::~SelectionNode()
{
	
}

void SelectionNode::traverse_to_file(FILE* fileout)
{
	if (isSwitch)
	{
		//code for switch
		fprintf(fileout, "\t%s [shape=hexagon,color=green,label=\"switch\"]\n", TreeNodeName.c_str());
		TreeNode::traverse_to_file(fileout);
	}
	else
	{
		if (jticket3<0)
		{
			fprintf(fileout, "\t%s [shape=diamond,color=green,label=\"if\"]\n", TreeNodeName.c_str());
		TreeNode::traverse_to_file(fileout);
		}
		else
		{
			fprintf(fileout, "\t%s [shape=diamond,color=green,label=\"if else\"]\n", TreeNodeName.c_str());
			TreeNode::traverse_to_file(fileout);
		}
	}
}
void SelectionNode::ast_to_3ac(FILE* fileout)
{
	if (isSwitch)
	{
		//code for switch
	}
	else
	{
		if (jticket3<0)
		{
			//no else
			children[0]->ast_to_3ac(fileout);
			fprintf(fileout, "BREQ\t%d\t(0)\t%d\n", children[0]->returnTicket(),jticket1);
			fprintf(fileout, "BR\t\t\t%d\n", jticket2);
			fprintf(fileout, "LABEL\t%d\n",jticket1);
			children[1]->ast_to_3ac(fileout);
			fprintf(fileout, "LABEL\t%d\n", jticket2);
		}
		else
		{
			//else
			children[0]->ast_to_3ac(fileout);
			fprintf(fileout, "BREQ\t%d\t(0)\t%d\n", children[0]->returnTicket(),jticket1);
			fprintf(fileout, "BR\t\t\t%d\n", jticket2);
			fprintf(fileout, "LABEL\t%d\n",jticket1);
			children[1]->ast_to_3ac(fileout);
			fprintf(fileout, "BR\t\t\t%d\n", jticket3);
			fprintf(fileout, "LABEL\t%d\n", jticket2);
			children[2]->ast_to_3ac(fileout);
			fprintf(fileout, "LABEL\t%d\n", jticket3);
		}
	}
}