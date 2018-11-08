#ifndef ITERATION_STATEMENT
#define ITERATION_STATEMENT

#include "tree.h"

class Iter_statement: public TreeNode
{
public:
	Iter_statement(string TreeNodeProductionName, bool doType);
	~Iter_statement();
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	
protected:
	int jumpCounterOne;
	int jumpCounterTwo;
	bool dotype;
	
};
#endif