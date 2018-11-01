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
	DataNode(int nodeNumber, string nodeName, int ticket);
	~DataNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void storeInt(int i);
	void storeDouble(double d);
	void storeString(char *s);
	void storeChar(char c);

protected:

	int ticketNumber;
	nodeDataType dType;
	Data data;

};

#endif
