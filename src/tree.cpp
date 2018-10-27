/*
* @Author: ahpalmerUNR
* @Date:   2018-10-27 14:10:44
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-27 15:52:27
*/
#include "tree.h"

TreeNode::TreeNode(TreeNode* parentTreeNode,int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren)
{
	TreeNodeNumber = TreeNodeNum;
	numberChildren = numberOfChildren;
	TreeNodeName = TreeNodeProductionName;
	parent = parentTreeNode;
	children.resize(numberChildren);
	
}

TreeNode::~TreeNode()
{
	
}

void TreeNode::traverse_to_file(FILE* fileout)
{
	for (int i = 0; i < numberChildren; ++i)
	{
		fprintf(fileout, "\t%s -> %s;\n", TreeNodeName.c_str(),children[i]->TreeNodeName.c_str());
		children[i]->traverse_to_file(fileout);
	}
}

void TreeNode::ast_to_3ac(FILE* fileout)
{
	// Fill in Later
}

void TreeNode::assignChild(int childIndex, TreeNode* child)
{
	children[childIndex] = child;
}

Tree::Tree()
{
	
}

Tree::~Tree()
{
	delete root;
}

void Tree::tree_to_gv(string fileName)
{
	FILE* printFile;
	printFile = fopen(fileName.c_str(),"w");
	fprintf(printFile, "digraph AST {\n");
	root->traverse_to_file(printFile);
	fprintf(printFile, "}\n");
	fclose(printFile);
}

void Tree::set_root(TreeNode* new_root)
{
	root = new_root;
}