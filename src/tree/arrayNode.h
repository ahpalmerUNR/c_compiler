#ifndef ARRAY_NODE
#define ARRAY_NODE

#include "tree.h"
#include "castNode.h"
//error: array subscript is not an integer
class ArrayNode : public TreeNode {
public:	
	ArrayNode(string nodeName);
	~ArrayNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();
	void setTypeSpecifier(nodeDataType typeSpec);
	nodeDataType getDataType(char * representation);//representation returned uses max buffer 500 characters.
	void notData();
	void errorCheck();
	void implicitCastWarning(nodeDataType t1, nodeDataType t2);
	void setidDataTypes(vector<nodeDataType>);
	nodeDataType getidDataType();
	void setArrayOffset(int i);
	int getArrayOffset();
	void setTicketNumber(int);
	int getTicketNumber();
	void setFirst();
	void setLast();
	void storeString(char *string);
	bool isArrayNode();
	void setLHS();
protected:

	//int ticketNumber;
	nodeDataType dType;
	vector<nodeDataType> idDataTypes;
	int arrayOffset;
	bool isLHS;
	bool isFirst;
	bool isLast;
	char name[500];
};

#endif
