#ifndef TREE
#define TREE

#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "../symboltable.h"

using namespace std;

extern SymbolTable astTable;

enum nodeDataType { 
	INT_TYPE_NODE,
	DOUBLE_TYPE_NODE,
	CHAR_TYPE_NODE,
	VOID_TYPE_NODE,
	POINTER_TYPE_NODE,
	SHORT_TYPE_NODE,
	LONG_TYPE_NODE,
	FLOAT_TYPE_NODE,
	SIGNED_TYPE_NODE,
	UNSIGNED_TYPE_NODE,
	STRUCT_TYPE_NODE,
	UNION_TYPE_NODE,
	ENUM_TYPE_NODE,
	TYPEDEF_NAME_TYPE_NODE,
	CONST_TYPE_NODE,
	VOLATILE_TYPE_NODE,
	STRING_TYPE_NODE,
	AUTO_TYPE_NODE,
	REGISTER_TYPE_NODE,
	STATIC_TYPE_NODE,
	EXTERN_TYPE_NODE,
	TYPEDEF_TYPE_NODE,
	ID_TYPE_NODE
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
