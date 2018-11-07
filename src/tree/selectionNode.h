#ifndef SELECTION_NODE
#define SELECTION_NODE 

#include "tree.h"

class SelectionNode:public TreeNode
{
public:
	SelectionNode(int TreeNodeNum, string TreeNodeProductionName,int numChildren,bool isaSwitch, int jumpTicket1,int jumpTicket2,int jumpTicket3,int line,int col, string source);
	~SelectionNode();
	
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	
protected:
	int jticket1;
	int jticket2;
	int jticket3;
	bool isSwitch;
	SymbolTable switchTable;
	
};

#endif