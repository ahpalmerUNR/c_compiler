#ifndef DATA_NODE
#define DATA_NODE

#include "tree.h"

union Data
{
	int dint;
	char dchar;
	char *dstr;
	double ddoub;
};

class DataNode : public TreeNode {
public:	
	DataNode(int nodeNumber, string nodeName, int ticket,int line,int col, string source);
	~DataNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void storeInt(int i);
	void storeDouble(double d);
	void storeString(char *s);
	void storeChar(char c);
	void setTypeSpecifier(nodeDataType typeSpec);
	void setOperator(OperatorType typeSpec);
	int getDataType(char * representation);//representation returned uses max buffer 500 characters.
	void notData();
	void setNumberChildren(int);
	void setSymbolNode(Node *n);
protected:

	int ticketNumber;
	nodeDataType dType;
	OperatorType oType;
	Data data;
	bool isData;
	bool isOperatorNode;
	Node *symbolTableNode;
};

#endif
