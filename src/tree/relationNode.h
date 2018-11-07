#ifndef RELATION_NODE
#define RELATION_NODE

#include "tree.h"
class RelationNode : public TreeNode {
public:	
	RelationNode(int nodeNumber, string nodeName, int ticket,int line,int col, string source);
	~RelationNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void setOperator(OperatorType opSpec);
	void setTypeSpecifier(nodeDataType typeSpec);
protected:

	int ticketNumber;
	nodeDataType dType;
	OperatorType oType;

};

#endif
