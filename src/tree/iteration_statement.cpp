/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 22:43:27
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-01 19:47:49
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
	// cout<<"Iter_statement"<<endl;
	string doRep;
	if (dotype)
	{
		doRep = "shape=invhouse,label=\"do type\niteration\",color=firebrick1";
	}
	else
	{
		doRep = "shape=house,label=\"for type\niteration\",color=firebrick1";
	}
	fprintf(fileout, "%s [%s]\n",TreeNodeName.c_str(),doRep.c_str() );
	TreeNode::traverse_to_file(fileout);
}
void Iter_statement::ast_to_3ac(FILE* fileout)
{
	
}