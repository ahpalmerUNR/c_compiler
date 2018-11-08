/**
 * @file typeNode.cpp
 * @author Nathan Yocum
 * @brief This node contains the type of the node passed up from
 *        declaration specifiers
 */

#include "typeNode.h"

/**
 * @brief Construct a new Type Node object
 * 
 * @param nodeNumber 
 * @param nodeName 
 * @param ticket 
 */
TypeNode::TypeNode(string nodeName, int numChildren) : TreeNode(nodeName,numChildren)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}

/**
 * @brief Destroy the Type Node object
 * 
 */
TypeNode::~TypeNode()
{

}

/**
 * @brief 
 * 
 * @param fileout 
 */
void TypeNode::traverse_to_file(FILE* fileout)
{
	char typePrint[500];
	snprintf(typePrint, 500, "%s", TreeNodeName.c_str());
	fprintf(fileout, "\t%s [label=\"%s\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
}

/**
 * @brief 
 * 
 * @param fileout 
 */
void TypeNode::ast_to_3ac(FILE* fileout)
{

}

/**
 * @brief Walk down the tree and get the types used
 * 
 * @return vector<nodeDataType> 
 */
vector<int> TypeNode::getType()
{
	char buffer[500];
	children[0]->getDataType(buffer);
	types = children[0]->getTypes();
	vector<nodeDataType> t = parseTypes();
	return types;
}

/**
 * @brief Parse types in children nodes. Return the types of variables.
 *        Responsible for warnings when type coersions occur.
 * 
 * @return vector<nodeDataType> 
 */
vector<nodeDataType> TypeNode::parseTypes()
{
	for (const int t : types) {
		nodeDataType type = static_cast<nodeDataType>(t);
		switch (type) {
			
		}
	}
}
