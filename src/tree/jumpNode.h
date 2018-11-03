#ifndef JUMP_NODE
#define JUMP_NODE 

#include "tree.h"

class JumpNode: public TreeNode
{
	//In constructor, jumpType refers to what production.
	//0->goto id;
	//1->continue;
	//2->break;
	//3->return;
	//4->return expr ;
public:
	JumpNode(int TreeNodeNum, string TreeNodeProductionName,int jumpTicket, int jumpType);//jumpType for productions 0 to 4 range
	~JumpNode();
	
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	
protected:
	int jumpCounter;
	int ticketNumber;
	int jtype;
	
};

#endif