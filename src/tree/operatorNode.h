#ifndef OPERATOR_NODE
#define OPERATOR_NODE

#include "tree.h"

enum OperatorType2{AMP_op, STAR_op, PLUS_op, MINUS_op, TILDA_op, NOT_op, INC_op, DEC_op};

class OperatorNode : public TreeNode {
public:	
	OperatorNode(string nodeName, OperatorType2 t, int numChildren);
	~OperatorNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();
	nodeDataType getDataType(char *);

protected:

	OperatorType2 oType;
	int ticketNumber;
	nodeDataType dType;
};

#endif
