#ifndef SELECTION_NODE
#define SELECTION_NODE 

#include "tree.h"

class SelectionNode:public TreeNode
{
public:
	SelectionNode(string TreeNodeProductionName,bool isaSwitch);
	~SelectionNode();
	
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	void errorCheck(const char * str);
	
protected:
	int jticket1;
	int jticket2;
	int jticket3;
	int ticket;
	bool isSwitch;
	SymbolTable switchTable;
	
};

#endif