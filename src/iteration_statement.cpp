/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 22:43:27
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-30 23:31:58
*/
#include "iteration_statement.h"

Iter_statement::Iter_statement(int TreeNodeNumber,string TreeNodeProductionName,int TicketOne,int TicketTwo,bool doType):TreeNode(TreeNodeNumber,TreeNodeProductionName,4)
{
	jumpCounterOne = TicketOne;
	jumpCounterTwo = TicketTwo;
	dotype = doType;
}
Iter_statement::~Iter_statement()
{
	
}
void Iter_statement::traverse_to_file(FILE* fileout)
{
	string doRep;
	if (dotype)
	{
		doRep = "do type\niteration";
	}
	else
	{
		doRep = "for type\niteration";
	}
	fprintf(fileout, "%s [label=\"%s\",color=\"0.3 0.4 0.4\"]\n",TreeNodeName.c_str(),doRep.c_str() );
	TreeNode::traverse_to_file(fileout);
}
void Iter_statement::ast_to_3ac(FILE* fileout)
{
	
}