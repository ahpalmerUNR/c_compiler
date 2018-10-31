#ifndef TREE
#define TREE

#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

enum nodeDataType { INT_TYPE,DOUBLE_TYPE,CHAR_TYPE,VOID_TYPE,POINT_TYPE}

class TreeNode
{
public:
	TreeNode(int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren);
	~TreeNode();
	virtual void traverse_to_file(FILE*);
	virtual void ast_to_3ac(FILE*);
	virtual void assignChild(int childIndex, TreeNode* child);
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
	void set_root(TreeNode* new_root);
private:
	TreeNode* root;
};
#endif