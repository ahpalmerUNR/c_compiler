#ifndef ASSIGNMENT_NODE
#define ASSIGNMENT_NODE

#include "tree.h"
#include "castNode.h"
class AssignmentNode : public TreeNode {
public:	
	AssignmentNode(string nodeName, int numberOfChildren);
	~AssignmentNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void setTypeSpecifier(nodeDataType typeSpec);
	void setAssignType(AssignType typeSpec);
	void errorCheck();
protected:

	int ticketNumber;
	nodeDataType dType;
	AssignType aType;
};

#endif
