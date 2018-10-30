#ifndef TREE
#define TREE

#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class TreeNode
{
public:
	TreeNode(int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren);
	~TreeNode();
	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);
	void assignChild(int childIndex, TreeNode* child);
private:
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