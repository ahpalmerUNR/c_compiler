#ifndef DECLARATION_SPEC_NODE
#define DECLARATION_SPEC_NODE

#include "tree.h"

class DeclarationSpecNode : public TreeNode {
public:
	DeclarationSpecNode(string, int);
	~DeclarationSpecNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int getDataType(char*);
	vector<int> getTypes();
protected:
	// parseTypes parse types in children, return types of variables
	vector<nodeDataType> parseTypes();
	int ticketNumber;
	vector<int> types;
	int numChildrenTypes;
};

#endif // DECLARATION_SPEC_NODE