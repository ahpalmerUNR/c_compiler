#ifndef EMPTY_NODE
#define EMPTY_NODE 

#include "tree.h"


class EmptyNode: public TreeNode
{
public:
	EmptyNode(int TreeNodeNum, string TreeNodeProductionName);
	~EmptyNode();
	void traverse_to_file(FILE*);
protected:
	
};
#endif