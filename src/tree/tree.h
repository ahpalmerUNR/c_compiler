#ifndef TREE
#define TREE

#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

enum nodeDataType { INT_TYPE_NODE,DOUBLE_TYPE_NODE,CHAR_TYPE_NODE,VOID_TYPE_NODE,POINT_TYPE_NODE,STRING_TYPE_NODE};

class TreeNode
{
public:
	TreeNode(int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren);
	~TreeNode();
	virtual void traverse_to_file(FILE*);
	virtual void ast_to_3ac(FILE*);
	void assignChild(int childIndex, TreeNode* child);
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
