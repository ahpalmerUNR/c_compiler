#ifndef TYPE_NODE
#define TYPE_NODE

#include "tree.h"

class TypeNode : public TreeNode {
public:
	TypeNode(string);
	~TypeNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	vector<nodeDataType> getType();
protected:
	// parseTypes parse types in children, return types of variables
	vector<nodeDataType> parseTypes();
	int ticketNumber;
};

#endif // TYPE_NODE