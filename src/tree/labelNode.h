#ifndef LABEL_NODE
#define LABEL_NODE

#include "tree.h"


class LabelNode:public TreeNode
{
public:
	LabelNode(string TreeNodeProductionName);
	~LabelNode();
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	void errorCheck(const char * str);
	int returnTicket(){return jumpCounter;}
protected:
	int jumpCounter;
	
	
};
#endif