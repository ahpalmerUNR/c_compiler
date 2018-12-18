#ifndef FunctionCall_NODE
#define FunctionCall_NODE

#include "tree.h"
#include "castNode.h"
//error: array subscript is not an integer
class FunctionCallNode : public TreeNode {
public:	
	FunctionCallNode(string nodeName);
	~FunctionCallNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();
	void setTypeSpecifier(nodeDataType typeSpec);
	nodeDataType getDataType(char * representation);//representation returned uses max buffer 500 characters.
	void errorCheck();
	void implicitCastWarning(nodeDataType t1, nodeDataType t2);
	void setidDataTypes(vector<nodeDataType>);
	nodeDataType getidDataType();
	void setTicketNumber(int){};
	int getTicketNumber();
	void storeString(char *string);
	void setParamTickets(vector<int> pT);
	void setParamDataTypes(vector<nodeDataType> pT);
protected:

	//int ticketNumber;
	nodeDataType dType;
	vector<nodeDataType> paramDataTypes;
	vector<int> paramTicketNumbers;
	char funcName[500];
};

#endif
