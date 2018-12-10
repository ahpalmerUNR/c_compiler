#include"relationNode.h"

RelationNode::RelationNode( string nodeName) : TreeNode(nodeName,2)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}

RelationNode::~RelationNode()
{

}
nodeDataType RelationNode::getDataType(char *c)
{
	return dType;
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
	if (currentCodeLine != forErrors[0].source[0].lineNum )
	{
		fprintf(fileout, "#%s",TreeNode::coldLine().c_str() );
		currentCodeLine = forErrors[0].source[0].lineNum;
	}
	children[0]->ast_to_3ac(fileout);
	children[1]->ast_to_3ac(fileout);
	char typePrint[500] = "0";
	char typePrint2[500]= "0";
	char typePrint3[500] = "0";
	string opString;
	string s1,s2,s3;

	nodeDataType t = children[0]->getDataType(typePrint);
	//s1 = typePrint;
				s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
	if(t == ID_TYPE_NODE){ 
		t = children[0]->getidDataType();
		s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
	}
	/*else
	{
		if(s1 == "0")
				s1 =  rep_3ac_ticket(t,children[0]->returnTicket());
		else
				s1 = "(" + s1 + ")";
	}*/		
	t = children[1]->getDataType(typePrint2);
				s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
	//s2 = typePrint2;
	if(t == ID_TYPE_NODE){
		t = children[1]->getidDataType();
		s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
	}		
	/*else
	{
		if(s2 == "0")
				s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
		else
				s2 = "(" + s2 + ")";
	}*/	

	s3 = rep_3ac_ticket(dType,ticketNumber);
 
	switch(oType)
	{
		case EQ_OP:
			opString = "EQ\t" + s1 + "\t" + s2;
			break;
		case NE_OP:
			opString = "NE\t" + s1 + "\t" + s2;
			break;
		case GT_OP:
			opString = "GT\t" + s1 + "\t" + s2;
			break;
		case GE_OP:
			opString = "GE\t" + s1 + "\t" + s2;
			break;
		case LT_OP:
			opString = "LT\t" + s1 + "\t" + s2;
			break;
		case LE_OP:
			opString = "LE\t" + s1 + "\t" + s2;
			break;
	}
	fprintf(fileout, "%s\t%s\n",opString.c_str(),s3.c_str());
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
				yyerror("ERROR: Invalid operands to %");
			setTypeSpecifier(left);
		}
		else
		{
			implicitCastWarning(left,right);
			CastNode *tmp = new CastNode("Implicit_Cast");
			//++Variable_counter;
			//++AST_node_counter;
			if(oType == MOD_OP && (left == DOUBLE_TYPE_NODE || right == DOUBLE_TYPE_NODE))
			{
				TreeNode::errorCheck("ERROR: Invalid operands to %");
			}
			if(left == DOUBLE_TYPE_NODE || left ==  FLOAT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(DOUBLE_TYPE_NODE);
				tmp->assignChild(0,children[1]);
				assignChild(1,tmp);
				setTypeSpecifier(DOUBLE_TYPE_NODE);
			}
			else if(right == DOUBLE_TYPE_NODE || right == FLOAT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(DOUBLE_TYPE_NODE);
				tmp->assignChild(0,children[0]);
				assignChild(0,tmp);
				setTypeSpecifier(DOUBLE_TYPE_NODE);
			}
			else if(left == INT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(INT_TYPE_NODE);
				tmp->assignChild(0,children[1]);	
				assignChild(1,tmp);
				setTypeSpecifier(INT_TYPE_NODE);
			}
			else if(right == INT_TYPE_NODE)
			{
				tmp->setTypeSpecifier(INT_TYPE_NODE);
				tmp->assignChild(0,children[0]);
				assignChild(0,tmp);
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
	TreeNode::errorCheck((d + one + " " + two).c_str());
	//yyerror((d + one + " " + two).c_str());
}

