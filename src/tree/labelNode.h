#ifndef LABEL_NODE
#define LABEL_NODE

#include "tree.h"


class LabelNode:public TreeNode
{
public:
	LabelNode(int TreeNodeNum, string TreeNodeProductionName,int jumpTicket,int line,int col, string source);
	~LabelNode();
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
protected:
	int jumpCounter;
	
	
};
#endif