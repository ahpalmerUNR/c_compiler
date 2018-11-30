/*
* @Author: ahpalmerUNR
* @Date:   2018-11-05 15:44:49
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-29 23:10:42
*/
#include "functionNode.h"

using namespace std;

FunctionNode::FunctionNode(string TreeNodeProductionName):TreeNode(TreeNodeProductionName,4)
{
	variableTick = Variable_counter;
	++Variable_counter;
	sizeOfParams = 0;
	sizeOfLocals = 0;
}

FunctionNode::~FunctionNode()
{

}

void FunctionNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "\t%s [shape=doubleoctagon,color=red,label=\"%s\"]\n", TreeNodeName.c_str(),functName.c_str());
	TreeNode::traverse_to_file(fileout);
}

void FunctionNode::ast_to_3ac(FILE* fileout)
{
	
	int* tp;
	astTable.pushEmptyBST();
	
	astTable.insert("return",forErrors[0].source[0].lineNum,forErrors[0].colStart,INT_TYPE,tp);
	cout<<"TreeNode "<<TreeNodeName<<endl;
		cout.flush();
	astTable.writeToFile(out_log);
	fflush(out_log);
	
	fprintf(fileout, "PROCENTRY\t%s\t(%d)\t(%d)\n",functName.c_str(),sizeOfParams,sizeOfLocals);
	children[3]->ast_to_3ac(fileout);
	fprintf(fileout, "ENDPROC\n");
	astTable.popBST();
}

nodeDataType FunctionNode::getDataType(char* buffer)
{
	return VOID_TYPE_NODE;
}

vector<nodeDataType> FunctionNode::getTypes()
{
	return freturnType;
}

int FunctionNode::returnTicket()
{
	return variableTick;
}

void FunctionNode::errorCheck(const char * str)
{
	char temp[500];
	//Gets function name and sets param list if direct_decl_type
	// if (children[1]->getDataType(temp)==ID_TYPE_NODE)
	// {
	// 	functName.assign(temp);
	// 	cout<<endl<<children[1]->getDataType(temp)<<endl<<endl<<functName<<endl<<endl;
	// }
	// else if(children[1]->getDataType(temp)==DIRECT_DECL_TYPE_NODE)
	// {
	// 	children[1]->children[0]->getDataType(temp);
		
	// 	functName.assign(temp);
	// 	cout<<endl<<children[1]->children[0]->getDataType(temp)<<endl<<endl<<functName<<endl<<endl;
	// 	//set param list
	// }
	// else
	// {
	// 	cout<<endl<<children[1]->getDataType(temp)<<endl<<endl<<functName<<endl<<endl;
	// 	cout<<"Child type "<<children[1]->getDataType(temp)<<" "<<ID_TYPE_NODE<<endl;
	// 	// children[1]->printNode();
	// 	children[1]->errorCheck("No function name.");
	// }
	
	//check return type provided
	//if type is a storage-class specifier then it can only be extern or static
	//
	//return type may be arithmetic type, a structure, a union, a pointer, or 
	//void, but it can't be a function or an array
	//
	if (children[0]->getDataType(temp)==EMPTY_TYPE_NODE)
	{
		children[1]->errorCheck("Warning: No return type specified for function.");
		cout<<endl<<endl<<functName<<endl<<endl;
	}
	else
	{
		freturnType = children[0]->getTypes();
	}
	// if (children[2]->getDataType(temp)!=EMPTY_TYPE_NODE)
	// {
	// 	//set param types
	// }
	// TreeNode::printNode();
	
	
	//function declaration must specify explicitly that the declared identifier has function type:
	// i.e. direct_decl ( parameter-type-list)
	//   or direct_decl ( identifier-list) 
	// 	 or direct_decl ( )
	// 	
	if (children[1]->getDataType(temp)!=DIRECT_DECL_TYPE_NODE)
	{
		children[1]->errorCheck("ERROR: Incorrect declarator type. Must be function declarator.");
		
	} 
	else
	{
		children[1]->children[0]->getDataType(temp);
		
		functName.assign(temp);
		
		//direct_decl in above comment must be either identifier or parenthesized identifier
		//
		
		//can't be function type by means of typedef
		//
		
		//if parameter-type-list in above comment then declaration-list must be absent
		int typeNode = children[1]->children[1]->getDataType(temp);
		if (typeNode!=EMPTY_TYPE_NODE)
		{
			if (children[1]->children[1]->isIDList())
			{
				//Set param types to variables
				//
				//if type with identifier-list
				//identifier-list names the variables and declaration-list names the types and must be present or all types are assumed to be ints
				//
				//declaration-list can only name types specified in id-list
				//
				//initialization is not permitted
				//
				//Only storage-class specifier possible is register
				//
			
				sizeOfParams = children[2]->byteSize;
			
			}
			else
			{
				if (children[2]->getDataType(temp)!=EMPTY_TYPE_NODE)
				{
					children[2]->errorCheck("ERROR: Parameterized list in declaration does not permit declaration list after declarator.");
				}
				else
				{
					sizeOfParams = children[1]->byteSize;
				}
				//Each decl in param-list must contain an identifier
				//
				//could end with ", ..." but we are ignoring this case for now
				//otherwise
				//the function must be called with more params than arguments
				//the va_arg macro mechanism defined in the stdarg.h is used to ref extra args
				//variadic functions must have at least one named parameter
				//
			}
		}
		else
		{
			//Unless parameter-type-list consists only of void meaning that it takes no parameters
			if (children[2]->getDataType(temp)!=EMPTY_TYPE_NODE)
			{
				children[2]->errorCheck("ERROR: Empty parameter list in declaration does not permit declaration list after declarator.");
			}
			else
			{
				sizeOfParams = children[1]->byteSize;
			}
		}
		
		
	}
	
	
	
	//both types make assumption that params are declared just after the beginning of the compound statement(the function body)
	//
	//shadowing of params allowed only in inner blocks
	//
	//if param is declared to be of type array, then it is redeclared to be of type pointer to type
	//
	//if param is declared to be function returning type, then the declaration is adjusted to read pointer to function returing type
	//
	//Converted as necessary to the appropiate types specified in function spec
	//
	//
	
	sizeOfLocals = children[3]->byteSize;
}


ParamListNode::ParamListNode(string TreeNodeProductionName,bool isIDListType):TreeNode(TreeNodeProductionName,2)
{
	isID = isIDListType;
}

ParamListNode::~ParamListNode()
{
	
}

bool ParamListNode::isIDList()
{
	return isID;
}