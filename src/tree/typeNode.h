#ifndef TYPE_NODE
#define TYPE_NODE

#include "tree.h"

class TypeNode : public TreeNode {
public:
	TypeNode(string, int);
	~TypeNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	vector<int> getType();
	vector<nodeDataType> parseTypes();
protected:
	// parseTypes parse types in children, return types of variables
	int ticketNumber;
	int numChildrenTypes;
};

#endif // TYPE_NODE