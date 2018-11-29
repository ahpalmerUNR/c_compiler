#ifndef CAST_NODE
#define CAST_NODE

#include "tree.h"

class CastNode : public TreeNode {
public:	
	CastNode(string nodeName);
	~CastNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();
	nodeDataType getDataType(char*);
	void setTypeSpecifier(nodeDataType typeSpec);
protected:

	int ticketNumber;
	nodeDataType dType;
};

#endif
