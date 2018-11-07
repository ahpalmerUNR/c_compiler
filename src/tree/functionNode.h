#ifndef FUNCTION_NODE
#define FUNCTION_NODE 

#include "tree.h"

class FunctionNode:public TreeNode
{
public:
	FunctionNode(int TreeNodeNum, string TreeNodeProductionName, int variableticket,int line,int col, string source);
	~FunctionNode();
	
	void traverse_to_file(FILE* fileout);
	void ast_to_3ac(FILE* fileout);
	int getDataType();
	int returnTicket();
	void errorCheck();
	
protected:
	vector<nodeDataType> freturnType;
	int variableTick;
	vector<vector<nodeDataType>> functionArgs;
	string functName;
	
};

#endif