#include"relationNode.h"

RelationNode::RelationNode( string nodeName) : TreeNode(nodeName,2)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}

RelationNode::~RelationNode()
{

}

void RelationNode::traverse_to_file(FILE *fileout)
{
	char typePrint[500];
	char operatorPrint[500];
	switch(dType)
	{
		case CHAR_TYPE_NODE:
			snprintf(typePrint, 500,"Char: ");
			break;
		case INT_TYPE_NODE:
			snprintf(typePrint, 500,"Int: ");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(typePrint, 500,"Float: ");
			break;
		
	}
	switch(oType)
	{
		case EQ_OP:
			snprintf(operatorPrint, 500,"Left == Right");
			break;
		case NE_OP:
			snprintf(operatorPrint, 500,"Left != Right");
			break;
		case GT_OP:
			snprintf(operatorPrint, 500,"Left > Right");
			break;
		case GE_OP:
			snprintf(operatorPrint, 500,"Left >= Right");
			break;
		case LT_OP:
			snprintf(operatorPrint, 500,"Left < Right");
			break;
		case LE_OP:
			snprintf(operatorPrint, 500,"Left <= Right");
			break;
	}
	fprintf(fileout, "\t%s [label=\"%s %s\"]\n", TreeNodeName.c_str(),typePrint, operatorPrint);
	TreeNode::traverse_to_file(fileout);
}

void RelationNode::ast_to_3ac(FILE *fileout)
{
	char operatorPrint[500];
	switch(oType)
	{
		case EQ_OP:
			snprintf(operatorPrint, 500,"Left == Right");
			break;
		case NE_OP:
			snprintf(operatorPrint, 500,"Left != Right");
			break;
		case GT_OP:
			snprintf(operatorPrint, 500,"Left > Right");
			break;
		case GE_OP:
			snprintf(operatorPrint, 500,"Left >= Right");
			break;
		case LT_OP:
			snprintf(operatorPrint, 500,"Left < Right");
			break;
		case LE_OP:
			snprintf(operatorPrint, 500,"Left <= Right");
			break;
	}
}

int RelationNode::returnTicket()
{
	return ticketNumber;
}

void RelationNode::setOperator(OperatorType op)
{
	oType = op;
}
void RelationNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}

void RelationNode::errorCheck()
{
		char wat[500];
		TreeNode *leftChild = children[0];
		TreeNode *rightChild = children[1];
		nodeDataType left = nodeDataType(leftChild->getDataType(wat));
		nodeDataType right = nodeDataType(rightChild->getDataType(wat));
		if(left == ID_TYPE_NODE)
			left = children[0]->getidDataType();
		if(right == ID_TYPE_NODE)
			right = children[1]->getidDataType();
		if(left == right)
		{
			if(left == DOUBLE_TYPE_NODE && oType == MOD_OP)
				yyerror("Invalid operands to %");
			setTypeSpecifier(left);
		}
		else
		{
			implicitCastWarning(left,right);
			CastNode *tmp = new CastNode("Implicit Cast");
			//++Variable_counter;
			//++AST_node_counter;
			if(oType == MOD_OP && (left == DOUBLE_TYPE_NODE || right == DOUBLE_TYPE_NODE))
			{
				TreeNode::errorCheck("Invalid operands to %");
			}
			if(left == DOUBLE_TYPE_NODE)
			{
				tmp->setTypeSpecifier(DOUBLE_TYPE_NODE);
				tmp->assignChild(0,rightChild);
				rightChild = tmp;
				setTypeSpecifier(DOUBLE_TYPE_NODE);
			}
			else if(right == DOUBLE_TYPE_NODE)
			{
				tmp->setTypeSpecifier(DOUBLE_TYPE_NODE);
				tmp->assignChild(0,leftChild);
				leftChild = tmp;
				setTypeSpecifier(DOUBLE_TYPE_NODE);
			}
			else if(left == INT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(INT_TYPE_NODE);
				tmp->assignChild(0,rightChild);	
				rightChild = tmp;		
				setTypeSpecifier(INT_TYPE_NODE);
			}
			else if(right == INT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(INT_TYPE_NODE);
				tmp->assignChild(0,leftChild);
				leftChild = tmp;
				setTypeSpecifier(INT_TYPE_NODE);
			}
		}
}

void RelationNode::implicitCastWarning(nodeDataType t1, nodeDataType t2)
{
	char t1Print[500];
	char t2Print[500];
	switch(t1)
	{
		case CHAR_TYPE_NODE:
			snprintf(t1Print, 500,"Char");
			break;
		case INT_TYPE_NODE:
			snprintf(t1Print, 500,"Int");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(t1Print, 500,"Float");
			break;
	}
	switch(t2)
	{
		case CHAR_TYPE_NODE:
			snprintf(t2Print, 500,"Char");
			break;
		case INT_TYPE_NODE:
			snprintf(t2Print, 500,"Int");
			break;
		case DOUBLE_TYPE_NODE:
			snprintf(t2Print, 500,"Float");
			break;
	}
	string d = "Warning: implicit cast of types: ";
	string one = t1Print;
	string two = t2Print;
	//TreeNode::errorCheck((d + one + " " + two).c_str());
	yyerror((d + one + " " + two).c_str());
}

