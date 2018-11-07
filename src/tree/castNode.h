#ifndef CAST_NODE
#define CAST_NODE

#include "tree.h"

class CastNode : public TreeNode {
public:	
	CastNode(int nodeNumber, string nodeName, int ticket,int line,int col, string source);
	~CastNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void setTypeSpecifier(nodeDataType typeSpec);
protected:

	int ticketNumber;
	nodeDataType dType;
};

#endif
