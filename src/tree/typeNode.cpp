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
TypeNode::TypeNode(int nodeNumber, string nodeName, int ticket) : TreeNode(nodeNumber,nodeName,0)
{

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
void TypeNode::traverse_to_file (FILE* fileout)
{

}

/**
 * @brief 
 * 
 * @param fileout 
 */
void TypeNode::ast_to_3ac (FILE* fileout)
{

}

/**
 * @brief Parse types in children nodes. Return the types of variables.
 *        Responsible for warnings when type coersions occur.
 * 
 * @return vector<nodeDataType> 
 */
vector<nodeDataType> parseTypes()
{

}

/**
 * @brief Called to throw error in types TODO
 * 
 */
void typeNodeError()
{

}
