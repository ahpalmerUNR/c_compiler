#ifndef FUNCTION_NODE
#define FUNCTION_NODE 

#include "tree.h"

class FunctionNode:public TreeNode
{
public:
	FunctionNode(int TreeNodeNum, string TreeNodeProductionName,int jumpticket1,int jumpticket2, int jumpticket3, int jumpticket4, int variableticket);
	~FunctionNode();
	
	void traverse_to_file(FILE* fileout);
	void ast_to_3ac(FILE* fileout);
	int getDataType();
	int returnTicket();
	
protected:
	vector<nodeDataType> freturnType;
	int variableTick;
	int jumpTick1;
	int jumpTick2;
	int jumpTick3;
	int jumpTick4;
	vector<vector<nodeDataType>> functionArgs;
	string functName;
	
};

#endif