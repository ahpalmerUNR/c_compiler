/*
* @Author: ahpalmerUNR
* @Date:   2018-10-27 14:10:44
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-12-18 18:03:23
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
	tType = TREE_TYPE_NODE;
	byteSize = 0;
	arrayOffset = 1;
	// cout<<"TreeNode "<<TreeNodeName<<endl;
	// cout.flush();
}

TreeNode::~TreeNode()
{
	
}
bool TreeNode::checkChildZ()
{
	char tmp[500];
	if(children[0]->getDataType(tmp)==EMPTY_TYPE_NODE)
	{
		return true;
	}
	return false;
}

void TreeNode::traverse_to_file(FILE* fileout)
{
	
	for (int i = 0; i < numberChildren; ++i)
	{

		//cout<<"TreeNode "<<children[i]->TreeNodeName<<endl;
		fprintf(fileout, "\t%s -> %s;\n", TreeNodeName.c_str(),children[i]->TreeNodeName.c_str());
		children[i]->traverse_to_file(fileout);
	}
}

void TreeNode::ast_to_3ac(FILE* fileout)
{
	for (int i = 0; i < numberChildren; ++i)
	{
		// cout<<"TreeNode "<<TreeNodeName<<endl;
		// cout.flush();
		children[i]->ast_to_3ac(fileout);
	}
}

void TreeNode::printNode()
{
	cout<<"Line Start "<<forErrors[0].lineStart<<", ";
	cout<<"Line End "<<forErrors[0].lineEnd<<", ";
	cout<<"Col Start "<<forErrors[0].colStart<<", ";
	cout<<"Col End "<<forErrors[0].colEnd<<", "<<endl;
	for (int i = 0; i < forErrors[0].source.size(); ++i)
	{
		cout<<forErrors[0].source[i].codeLine.c_str();
	}
}

void TreeNode::setNoBytes(){
	byteSize = 0;
}

void TreeNode::assignChild(int childIndex, TreeNode* child)
{
	int pullInd;
	char temp[500];
	children[childIndex] = child;
	cout<<byteSize<<" bytes "<<TreeNodeName<<" Child "<<child->TreeNodeName<<" bytes "<<child->byteSize<<endl;
	byteSize = byteSize + child->byteSize;
	
	if (forErrors[0].lineStart ==-1)
	{
		assignLine(child->forErrors[0].lineStart,child->forErrors[0].colStart,child->forErrors[0].colEnd,child->coldLine());
	}

	// forErrors.erase(forErrors.begin()+childIndex+1);
	// forErrors.insert(forErrors.begin()+childIndex+1,child->forErrors[0]);

	
	// //skip for empty node types.
	// if (child->getDataType(temp)==EMPTY_TYPE_NODE)
	// {
	// 	// cout<<"Empty Node"<<endl;
	// }
	// else
	// {
	// 	//if nothing set before
	// 	if(forErrors[0].lineStart==-1)
	// 	{
	// 		// cout<<"NoChildrenYet"<<endl;
	// 		forErrors[0].lineStart = child->forErrors[0].lineStart;
	// 		forErrors[0].lineEnd = child->forErrors[0].lineEnd;
	// 		forErrors[0].colStart = child->forErrors[0].colStart;
	// 		forErrors[0].colEnd = child->forErrors[0].colEnd;
	// 		for (int i = 0; i < child->forErrors[0].source.size(); ++i)
	// 		{
	// 			// forErrors[0].source.erase(forErrors[0].source.begin()+i);
	// 			forErrors[0].source.insert(forErrors[0].source.begin()+i,child->forErrors[0].source[i]);
	// 		}
	// 	}
	// 	//add to existing source code
	// 	else
	// 	{
			
	// 		if (forErrors[0].lineStart > child->forErrors[0].lineStart)
	// 		{
				
	// 			int firstLine = forErrors[0].source[0].lineNum;
	// 			int index = 0;
				
	// 			while(child->forErrors[0].source[index].lineNum < firstLine)
	// 			{
	// 				forErrors[0].source.insert(forErrors[0].source.begin(),child->forErrors[0].source[index]);
	// 				++index;
	// 			}
				
	// 			forErrors[0].lineStart = child->forErrors[0].lineStart;
	// 			forErrors[0].colStart = child->forErrors[0].colStart;
	// 		}
	// 		else if(forErrors[0].lineStart == child->forErrors[0].lineStart && forErrors[0].colStart > child->forErrors[0].colStart)
	// 		{
	// 			forErrors[0].colStart = child->forErrors[0].colStart;
	// 		}
			
	// 		if (forErrors[0].lineEnd < child->forErrors[0].lineEnd)
	// 		{
	// 			pullInd = forErrors[0].source.size();
	// 			int firstLine = forErrors[0].source[pullInd-1].lineNum;
	// 			int index = child->forErrors[0].source.size()-1;
	// 			while(index >=0 && child->forErrors[0].source[index].lineNum > firstLine)
	// 			{
	// 				forErrors[0].source.insert(forErrors[0].source.begin()+pullInd,child->forErrors[0].source[index]);
	// 				--index;
	// 			}
	// 			forErrors[0].lineEnd = child->forErrors[0].lineEnd;
	// 			forErrors[0].colEnd = child->forErrors[0].colEnd;
	// 		}
	// 		else if(forErrors[0].lineEnd == child->forErrors[0].lineEnd && forErrors[0].colEnd < child->forErrors[0].colEnd)
	// 		{
	// 			forErrors[0].colEnd = child->forErrors[0].colEnd;
	// 		}
			
	// 	}
	// }
}

void TreeNode::setTypeSpecifier(nodeDataType typeSpec)
{
	tType = typeSpec;
}

void TreeNode::assignLine(int line,int colstart, int colend, string atmp)
{
	// char tmp[500];
	// long int offset = ftell(errorT);
	// fgets(tmp,sizeof tmp, errorT);
	// fseek(errorT,offset,SEEK_SET);
	// cout<<atmp;
	// 	cout.flush();
	sourceLine pair;
	pair.lineNum = line;
	pair.codeLine.assign(atmp); 
	ErrorReport toAdd;
	toAdd.lineStart = line;
	// cout<<toAdd.lineStart<<" "<<line<<endl<<endl;
	toAdd.lineEnd = line;
	toAdd.colStart = colstart;
	toAdd.colEnd = colend;

	toAdd.source.emplace_back(pair);
	forErrors.erase(forErrors.begin());
	forErrors.emplace(forErrors.begin(),toAdd);
	// cout<<forErrors[0].lineStart<<" "<<toAdd.lineStart<<" "<<line<<endl<<endl;
	// printNode();
	// cout<<TreeNodeName.c_str();
}

string TreeNode::coldLine()
{
	// printNode();
	return forErrors[0].source[0].codeLine;
}

void TreeNode::errorCheck(const char * str)
{
	// printf("Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,lineNum,colNum,str);
	// printf("%s",sourceCode.c_str());
	// for(int i = colNum-1; i>0;i--)
	// {
	// 	printf("-");
	// }
	// printf("^ \n\n");
	// fprintf(stderr,"%s\n",str);

	
	// fprintf(out_log,"Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,lineNum,colNum,str);
	// fprintf(out_log,"%s",sourceCode.c_str());
	// for(int i = colNum-1; i>0;i--)
	// {
	// 	fprintf(out_log,"-");
	// }
	// fprintf(out_log,"^ \n\n");
	
	printf("Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,forErrors[0].lineStart,forErrors[0].colStart,str);
	fprintf(out_log,"Symantic Issue: %s:Line: %d Column: %d %s\n",file_name,forErrors[0].lineStart,forErrors[0].colStart,str);
	if (forErrors[0].lineStart == forErrors[0].lineEnd)
	{
		//print single line error
		printf("%s",forErrors[0].source[0].codeLine.c_str());
		fprintf(out_log,"%s",forErrors[0].source[0].codeLine.c_str());
		for (int i = 0; i < forErrors[0].colEnd-1; ++i)
		{
			if (i==forErrors[0].colStart-1)
			{
				printf("^");
				fprintf(out_log,"^");
			}
			else if(i>forErrors[0].colStart-1 && i <forErrors[0].colEnd)
			{
				printf("-");
				fprintf(out_log,"-");
			}
			else
			{
				printf(" ");
				fprintf(out_log," ");
			}
		}
		printf("^\n\n");
		fprintf(out_log,"^\n\n");
	}
	else
	{
		//print multi-line error
		printf("Issue between:\n");
		fprintf(out_log,"Issue between:\n");
		for (int i = 0; i < forErrors[0].source.size(); ++i)
		{
			printf("%s",forErrors[0].source[i].codeLine.c_str());
		}
		printf("%s",forErrors[0].source[0].codeLine.c_str());
		fprintf(out_log,"%s",forErrors[0].source[0].codeLine.c_str());
		for (int i = 0; i < forErrors[0].colStart+20; ++i)
		{
			if (i==forErrors[0].colStart-1)
			{
				printf("^");
				fprintf(out_log,"^");
			}
			else if(i>forErrors[0].colStart-1)
			{
				printf("-");
				fprintf(out_log,"-");
			}
			else
			{
				printf(" ");
				fprintf(out_log," ");
			}
		}
		
		printf("\nand\n");
		fprintf(out_log,"\nand\n");
		printf("%s",forErrors[0].source[forErrors[0].source.size()-1].codeLine.c_str());
		fprintf(out_log,"%s",forErrors[0].source[forErrors[0].source.size()-1].codeLine.c_str());
		for (int i = 0; i < forErrors[0].colEnd; ++i)
		{
			if (i==forErrors[0].colEnd-1)
			{
				printf("^");
				fprintf(out_log,"^");
			}
			else
			{
				printf("-");
				fprintf(out_log,"-");
			}
		}
		
		printf("\n\n");
		fprintf(out_log,"\n\n");
		
	}

}

vector<nodeDataType> TreeNode::getTypes()
{
	char buffer[500];
	vector<nodeDataType> type;
	type.push_back(getDataType(buffer));
	return type;
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
	astTable.pushEmptyBST();
	printFile = fopen(fileName.c_str(),"w");
	root->ast_to_3ac(printFile);
	astTable.popBST();
	fclose(printFile);
}

void Tree::set_root(TreeNode* new_root)
{
	root = new_root;
}

string TreeNode::rep_3ac_ticket(nodeDataType ndt, int ticket)
{
	char typePrint[500];
	switch(ndt)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint, 500,"c");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint, 500,"i");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint, 500,"f");
			break;
		case FLOAT_TYPE_NODE:
			snprintf(typePrint, 500,"f");
			break;
		case VOID_TYPE_NODE:
			snprintf(typePrint,500,"i");
			break;
		default:
			snprintf(typePrint, 500, "Error probably with id %d",ndt);
			break;
		
	}
	return string(typePrint) + to_string(ticket);
}
