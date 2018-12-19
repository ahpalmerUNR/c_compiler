#ifndef EMPTY_ITER_NODE
#define EMPTY_ITER_NODE 

#include "tree.h"


class EmptyIterNode: public TreeNode
{
public:
	EmptyIterNode(string TreeNodeProductionName);
	~EmptyIterNode();
	void traverse_to_file(FILE*);
	nodeDataType getDataType(char *);
protected:
	nodeDataType dType;
};
#endif