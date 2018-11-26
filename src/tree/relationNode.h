#ifndef RELATION_NODE
#define RELATION_NODE

#include "tree.h"
#include "castNode.h"
class RelationNode : public TreeNode {
public:	
	RelationNode( string nodeName);
	~RelationNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();
	nodeDataType getDataType(char *);
	void setOperator(OperatorType opSpec);
	void setTypeSpecifier(nodeDataType typeSpec);
	void errorCheck();
	void implicitCastWarning(nodeDataType t1, nodeDataType t2);
protected:

	int ticketNumber;
	nodeDataType dType;
	OperatorType oType;

};

#endif
