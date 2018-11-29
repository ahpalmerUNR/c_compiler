#ifndef DECLARATION_SPEC_NODE
#define DECLARATION_SPEC_NODE

#include "tree.h"

class DeclarationSpecNode : public TreeNode {
public:
	DeclarationSpecNode(string, int);
	~DeclarationSpecNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	nodeDataType getDataType(char*);
	vector<nodeDataType> getTypes();
protected:
	// parseTypes parse types in children, return types of variables
	vector<nodeDataType> parseTypes();
	int ticketNumber;
	int numChildrenTypes;
};

#endif // DECLARATION_SPEC_NODE