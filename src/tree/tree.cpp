/*
* @Author: ahpalmerUNR
* @Date:   2018-10-27 14:10:44
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-31 17:12:08
*/
#include "tree.h"

using namespace std;

TreeNode::TreeNode(int TreeNodeNum,string TreeNodeProductionName,int numberOfChildren)
{
	TreeNodeNumber = TreeNodeNum;
	numberChildren = numberOfChildren;
	TreeNodeName = TreeNodeProductionName;
	children.resize(numberChildren);
	
}

TreeNode::~TreeNode()
{
	
}

void TreeNode::traverse_to_file(FILE* fileout)
{
	// cout<<"TreeNode "<<TreeNodeName.c_str()<<endl;
	for (int i = 0; i < numberChildren; ++i)
	{
		fprintf(fileout, "\t%s -> %s;\n", TreeNodeName.c_str(),children[i]->TreeNodeName.c_str());
		children[i]->traverse_to_file(fileout);
	}
}

void TreeNode::ast_to_3ac(FILE* fileout)
{
	for (int i = 0; i < numberChildren; ++i)
	{
		children[i]->ast_to_3ac(fileout);
	}
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