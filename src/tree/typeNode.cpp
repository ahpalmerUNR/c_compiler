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
	return types;
}

/**
 * @brief Parse types in children nodes. Return the types of variables.
 *        Responsible for warnings when type coersions occur.
 * @note  yyerror is temporary
 * 
 * @return vector<nodeDataType> 
 */
vector<nodeDataType> TypeNode::parseTypes()
{
	vector<nodeDataType> typesToUse;
	int numPrimaryTypes = 0;
	int numLongs = 0;
	int numShorts = 0;
	int isSigned = 0;
	int isUnsigned = 0;
	for (const int t : types) {
		nodeDataType type = static_cast<nodeDataType>(t);
		switch (type) {
			case LONG_TYPE_NODE:
				printf("%s:Line: %d Column: %d Warning: Longs not supported by machine (defaults to int)\n",file_name,line,column);
				if (numShorts) {
					yyerror("Invalid type");
					return {};
				}
				typesToUse.push_back(type);
				numLongs++;
				break;
			case SHORT_TYPE_NODE:
				printf("%s:Line: %d Column: %d Warning: Shorts not supported by machine (defaults to int)\n",file_name,line,column);
				if (numLongs) {
					yyerror("Invalid type");
					return {};
				}
				typesToUse.push_back(type);
				numShorts++;
				break;
			case CHAR_TYPE_NODE:
			case INT_TYPE_NODE:
			case FLOAT_TYPE_NODE:
			case DOUBLE_TYPE_NODE:
				numPrimaryTypes++;
				typesToUse.push_back(type);
				break;
			case SIGNED_TYPE_NODE:
				isSigned++;
				if (isUnsigned) {
					yyerror("Invalid type");
					return {};
				}
				if (isSigned > 1) {
					yyerror("Invalid type");
				}
				break;
			case UNSIGNED_TYPE_NODE:
				isUnsigned++;
				if (isSigned) {
					yyerror("Invalid type");
					return {};
				}
				if (isUnsigned > 1) {
					yyerror("Invalid type");
				}
				break;
		}
	}
	if (numPrimaryTypes < 1) {
		if (isSigned || isUnsigned || numLongs || numShorts) {
			typesToUse.push_back(INT_TYPE_NODE);
		} else {
			yyerror("No type set");
			typesToUse = {};
		}
	} else if (numPrimaryTypes > 1) {
		yyerror("Too many types declared");
		typesToUse = {};
	}

	return typesToUse;
}
