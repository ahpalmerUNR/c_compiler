#ifndef FUNCTION_NODE
#define FUNCTION_NODE 

#include "tree.h"

class FunctionNode:public TreeNode
{
public:
	FunctionNode( string TreeNodeProductionName);
	~FunctionNode();
	
	void traverse_to_file(FILE* fileout);
	void ast_to_3ac(FILE* fileout);
	int getDataType(char*);
	int returnTicket();
	void errorCheck();
	vector<int> getTypes();
	
protected:
	// vector<nodeDataType> freturnType;
	vector<int> freturnType;
	int variableTick;
	vector<vector<nodeDataType>> functionArgs;
	string functName;
	
};

#endif