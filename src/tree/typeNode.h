#ifndef TYPE_NODE
#define TYPE_NODE

#include "tree.h"

class TypeNode : public TreeNode {
	TypeNode(int, string, int);
	~TypeNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	// parseTypes parse types in children, return types of variables
	vector<nodeDataType> parseTypes();
	void typeNodeError();
}

#endif // TYPE_NODE