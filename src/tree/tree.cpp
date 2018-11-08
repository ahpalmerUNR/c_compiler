/*
* @Author: ahpalmerUNR
* @Date:   2018-10-27 14:10:44
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-08 15:06:07
*/
#include "tree.h"

TreeNode::TreeNode(string TreeNodeProductionName,int numberOfChildren)
{
	TreeNodeNumber = AST_node_counter;
	++AST_node_counter;
	numberChildren = numberOfChildren;
	TreeNodeName = TreeNodeProductionName + to_string(TreeNodeNumber);
	children.resize(numberChildren);
	forErrors.resize(numberChildren+1);
	forErrors[0].lineStart = -1;
	forErrors[0].lineEnd = -1;
	forErrors[0].colStart = -1;
	forErrors[0].colEnd = -1;
}

TreeNode::~TreeNode()
{
	
}

void TreeNode::traverse_to_file(FILE* fileout)
{
	
	for (int i = 0; i < numberChildren; ++i)
	{
		// cout<<"TreeNode "<<TreeNodeName<<endl;
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
	forErrors.assign(childIndex+1,child.forErrors[0]);

	if(forErrors[0].lineStart==-1)
	{
		forErrors[0].lineStart = child.forErrors[0].lineStart;
		forErrors[0].lineEnd = child.forErrors[0].lineEnd;
		forErrors[0].colStart = child.forErrors[0].colStart;
		forErrors[0].colEnd = child.forErrors[0].colEnd;
		for (int i = 0; i < child.forErrors[0].source.size(); ++i)
		{
			forErrors[0].source.assign(i,child.forErrors[0].source[i]);
		}
	}

	else
	{
		if (forErrors[0].lineStart > child.forErrors[0].lineStart)
		{
			int firstLine = forErrors[0].source[0].lineNum;
			int index = 0;
			while(child.forErrors[0].source[index].lineNum < firstLine)
			{
				firstLine.source.insert(0,child.forErrors[0].source[index]);
				++index;
			}
		}
		///Working here!!!
	}

}

void TreeNode::assignLine(int line,int colstart, int colend, string code)
{
	sourceLine pair;
	pair.lineNum = line;
	pair.codeLine.assign(code); 
	ErrorReport toAdd;
	toAdd.lineStart = line;
	toAdd.lineEnd = line;
	toAdd.colStart = colstart;
	toAdd.colEnd = colend;
	toAdd.source.emblace_back(pair);
	forErrors.assign(0,toAdd);
}

void TreeNode::errorCheck(const char * str)
{
	printf("Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,lineNum,colNum,str);
	printf("%s",sourceCode.c_str());
	for(int i = colNum-1; i>0;i--)
	{
		printf("-");
	}
	printf("^ \n\n");
	fprintf(stderr,"%s\n",str);
	
	fprintf(out_log,"Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,lineNum,colNum,str);
	fprintf(out_log,"%s",sourceCode.c_str());
	for(int i = colNum-1; i>0;i--)
	{
		fprintf(out_log,"-");
	}
	fprintf(out_log,"^ \n\n");
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

void Tree::tree_to_3ac(string fileName)
{
	FILE* printFile;
	printFile = fopen(fileName.c_str(),"w");
	root->ast_to_3ac(printFile);
	fclose(printFile);
}

void Tree::set_root(TreeNode* new_root)
{
	root = new_root;
}