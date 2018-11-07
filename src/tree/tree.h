#ifndef TREE
#define TREE

#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "../symboltable.h"

using namespace std;

extern SymbolTable astTable;
extern void yyerror(char const * msg);


enum OperatorType {
	ADD_OP,
	SUB_OP,
	MULT_OP,
	DIV_OP,
	MOD_OP,
	EQ_OP,
	NE_OP,
	GT_OP,
	GE_OP,
	LT_OP,
	LE_OP,
	COMMA_OP,
	QUESTION_OP,
	OR_OP,
	AND_OP,
	BAR_OP,
	CARET_OP,
	AMP_OP	
	};
	
enum AssignType {
	EQUAL_ASSIGN,
	ADD_ASSIGN,
	SUB_ASSIGN,
	MULT_ASSIGN,
	DIV_ASSIGN,
	MOD_ASSIGN,
	LEFT_ASSIGN,
	RIGHT_ASSIGN,
	AND_ASSIGN,
	XOR_ASSIGN,
	OR_ASSIGN
	};

class TreeNode
{
public:
	TreeNode(int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren);
	~TreeNode();
	virtual void traverse_to_file(FILE*);
	virtual void ast_to_3ac(FILE*);
	virtual void assignChild(int childIndex, TreeNode* child);
	virtual int getDataType(char *){}
	virtual int returnTicket(){}
protected:
	int TreeNodeNumber;
	//type
	string TreeNodeName;
	int numberChildren;
	vector<TreeNode*> children;
};

class Tree
{
public:
	Tree();
	~Tree();
	void tree_to_gv(string fileName);
	void tree_to_3ac(string fileName);
	void set_root(TreeNode* new_root);
private:
	TreeNode* root;
};
#endif
