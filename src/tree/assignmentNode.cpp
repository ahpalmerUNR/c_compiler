#include"assignmentNode.h"

AssignmentNode::AssignmentNode(string nodeName, int numberOfChildren) : TreeNode(nodeName,numberOfChildren)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}
AssignmentNode::~AssignmentNode()
{

}

void AssignmentNode::traverse_to_file(FILE *fileout)
{
	char typePrint[500];
	char assignPrint[500];
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
			default:
				snprintf(typePrint, 500, "Error probably with id");
				break;
			
		}
		switch(aType)
		{
			case EQUAL_ASSIGN:
				snprintf(assignPrint, 500,"Left = Right");
				break;
			case ADD_ASSIGN:
				snprintf(assignPrint, 500,"Left += Right");
				break;
			case SUB_ASSIGN:
				snprintf(assignPrint, 500,"Left -= Right");
				break;
			case MULT_ASSIGN:
				snprintf(assignPrint, 500,"Left *= Right");
				break;
			case DIV_ASSIGN:
				snprintf(assignPrint, 500,"Left /= Right");
				break;
			case MOD_ASSIGN:
				snprintf(assignPrint, 500,"Left %%= Right");
				break;
			case LEFT_ASSIGN:
				snprintf(assignPrint, 500,"Left <<= Right");
				break;
			case RIGHT_ASSIGN:
				snprintf(assignPrint, 500,"Left >>= Right");
				break;
			case AND_ASSIGN:
				snprintf(assignPrint, 500,"Left &= Right");
				break;
			case XOR_ASSIGN:
				snprintf(assignPrint, 500,"Left ^= Right");
				break;
			case OR_ASSIGN:
				snprintf(assignPrint, 500,"Left |= Right");
				break;
		}

		fprintf(fileout, "\t%s [label=\"%s %s\"]\n", TreeNodeName.c_str(),typePrint, assignPrint);
	TreeNode::traverse_to_file(fileout);
	
}
void AssignmentNode::ast_to_3ac(FILE *fileout)
{
	children[0]->ast_to_3ac(fileout);
	children[1]->ast_to_3ac(fileout);
	char typePrint1[500] = "0";
	char typePrint2[500] = "0";
	char assignPrint[500];
fprintf(fileout, "#%s",TreeNode::coldLine().c_str() );
	bool isOpAssign = true;
	string assignString;
	string s1,s2;
	nodeDataType t = children[0]->getDataType(typePrint1);
	//s1 = typePrint1;
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
	//s2 = typePrint2;
				s2 =  rep_3ac_ticket(t,children[1]->returnTicket());
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


	switch(aType)
	{
		case EQUAL_ASSIGN:
			isOpAssign = false;
			break;
		case ADD_ASSIGN:
			assignString = "ADD\t" + s1 + "\t" + s2;
			break;
		case SUB_ASSIGN:
			assignString = "SUB\t" + s1 + "\t" + s2;
			break;
		case MULT_ASSIGN:
			assignString = "MULT\t" + s1 + "\t" + s2;
			break;
		case DIV_ASSIGN:
			assignString = "DIV\t" + s1 + "\t" + s2;
			break;
		case MOD_ASSIGN:
			assignString = "MOD\t" + s1 + "\t" + s2;
			break;
		case LEFT_ASSIGN:
			assignString = "LEFT\t" + s1 + "\t" + s2;
			break;
		case RIGHT_ASSIGN:
			assignString = "RIGHT\t" + s1 + "\t" + s2;
			break;
		case AND_ASSIGN:
			assignString = "AND\t" + s1 + "\t" + s2;
			break;
		case XOR_ASSIGN:
			assignString = "XOR\t" + s1 + "\t" + s2;
			break;
		case OR_ASSIGN:
			assignString = "OR\t" + s1 + "\t" + s2;
			break;
	}	
	if(isOpAssign)
	{
		fprintf(fileout,"%s\t%s\n",assignString.c_str(),s1.c_str());
		//fprintf(fileout,"ASSIGN\t%s\t%s%i\n",s1.c_str(),typePrint1,Variable_counter++);
	}
	else
		fprintf(fileout,"ASSIGN\t%s\t_\t%s\n",s2.c_str(),s1.c_str());
}

int AssignmentNode::returnTicket()
{
	return ticketNumber;
}

void AssignmentNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}

void AssignmentNode::setAssignType(AssignType assignSpec)
{
	aType = assignSpec;
}

void AssignmentNode::errorCheck()
{
		char pointless[500];
		nodeDataType left, right;
		//Actually have to get the data type from the symbol table
		left = nodeDataType(children[0]->getDataType(pointless));
		right = nodeDataType(children[1]->getDataType(pointless));
		if(left != ID_TYPE_NODE)
			yyerror("Error: lvalue required as left operand of assignment");
		
		left = children[0]->getidDataType();
		if(right == ID_TYPE_NODE)
		{
			//Get rights actual type
		  right = children[1]->getidDataType();
		}
		
		if(right != left)
		{
			CastNode *tmp = new CastNode("Implicit_Cast_");
			tmp->setTypeSpecifier(left);
			tmp->assignChild(0,children[1]);
			assignChild(1,tmp);
			setTypeSpecifier(left);
			//may produce duplicate warnings as data node so maybe not use it...
			implicitCastWarning(left,right);
		}
		cout<<children[0]->returnTicket()<<endl;
		cout<<ticketNumber<<endl;
		ticketNumber = children[0]->returnTicket();
}

void AssignmentNode::implicitCastWarning(nodeDataType t1, nodeDataType t2)
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
		case FLOAT_TYPE_NODE:
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
		case FLOAT_TYPE_NODE:
			snprintf(t2Print, 500,"Float");
			break;
	}
	string d = "Warning: implicit cast of types in assignment: ";
	string one = t1Print;
	string two = t2Print;
	TreeNode::errorCheck((d + one + " " + two).c_str());
	//yyerror((d + one + " " + two).c_str());
}
