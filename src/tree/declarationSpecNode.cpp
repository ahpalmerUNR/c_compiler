/**
 * @file declarationSpecNode.cpp
 * @author Nathan Yocum
 * @brief Declaration specifier node
 * 
 */

#include "declarationSpecNode.h"

DeclarationSpecNode::DeclarationSpecNode(string nodeName, int numChildren) : TreeNode(nodeName,numChildren)
{

}

DeclarationSpecNode::~DeclarationSpecNode()
{

}

void DeclarationSpecNode::traverse_to_file(FILE* fileout)
{
	char typePrint[500];
	snprintf(typePrint, 500, "%s", TreeNodeName.c_str());
	fprintf(fileout, "\t%s [label=\"%s\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
}

void DeclarationSpecNode::ast_to_3ac(FILE* fileout)
{

}

nodeDataType DeclarationSpecNode::getDataType(char* ignore)
{
	// char buffer[500];
	// for(int i = 0; i < numberChildren; i++) {
	// 	if (children[i]->getDataType(buffer) != -1) {
	// 		types.push_back(children[i]->getDataType(buffer));
	// 	}
	// }
	// return children[0]->getDataType(buffer);
	return VOID_TYPE_NODE;
}

vector<nodeDataType> DeclarationSpecNode::getTypes()
{
	char buffer[500];
	for (int i = 0; i < numberChildren; i++) {
		vector<nodeDataType> tmp = children[i]->getTypes();
		for (nodeDataType t : tmp) {
			if (t != -1) {
				types.push_back(t);
			}
		}

		// types.push_back(children[i]->getDataType(buffer));
	}
	return types;
}
