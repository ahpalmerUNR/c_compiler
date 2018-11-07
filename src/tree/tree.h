#ifndef TREE
#define TREE

#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "../symboltable.h"

using namespace std;

extern SymbolTable astTable;

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
