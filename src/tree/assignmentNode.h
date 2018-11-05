#ifndef ASSIGNMENT_NODE
#define ASSIGNMENT_NODE

#include "tree.h"

class AssignmentNode : public TreeNode {
public:	
	AssignmentNode(int nodeNumber, string nodeName, int ticket, int numberOfChildren);
	~AssignmentNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void setTypeSpecifier(nodeDataType typeSpec);
	void setAssignType(AssignType typeSpec);
protected:

	int ticketNumber;
	nodeDataType dType;
	AssignType aType;
};

#endif
