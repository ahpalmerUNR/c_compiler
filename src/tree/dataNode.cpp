#include "dataNode.h"

DataNode::DataNode(string nodeName) : TreeNode(nodeName,0)
{

	ticketNumber = Variable_counter;
	++Variable_counter;
	isData = false;
	isOperatorNode = false;
	//idDataTypes.push_back(INT_TYPE_NODE);
}

DataNode::~DataNode()
{
	if (dType == ID_TYPE_NODE || dType == STRING_TYPE_NODE)
	{
		delete data.dstr;
	}
}

void DataNode::traverse_to_file(FILE* fileout) 
{
	char typePrint[500];
	char operatorPrint[500];
	//cout << "here" << endl;
	//cout << idDataTypes[0] << endl;
	if (isData)
	{
		switch(dType)
		{
			case CHAR_TYPE_NODE:
				snprintf(typePrint, 500,"Char: %c",data.dchar);
				break;
			case INT_TYPE_NODE:
				snprintf(typePrint, 500,"Int: %d",data.dint);
				break;
			case DOUBLE_TYPE_NODE:
				snprintf(typePrint, 500,"Float: %f",data.ddoub);
				break;
			case STRING_TYPE_NODE:
				snprintf(typePrint, 500,"String: %s",data.dstr);
				break;
			case ID_TYPE_NODE:
				snprintf(typePrint, 500,"ID: %s", data.dstr);
				
		}
	}
	else if (!isOperatorNode)
	{
		switch(dType)
		{
			case INT_TYPE_NODE:
				snprintf(typePrint, 500,"int");
				break;
			case DOUBLE_TYPE_NODE:
				snprintf(typePrint, 500,"double");
				break;
			case CHAR_TYPE_NODE:
				snprintf(typePrint, 500,"char");
				break;
			case VOID_TYPE_NODE:
				snprintf(typePrint, 500,"void");
				break;
			case POINTER_TYPE_NODE:
				snprintf(typePrint, 500,"*");
				break;
			case SHORT_TYPE_NODE:
				snprintf(typePrint, 500,"short");
				break;
			case LONG_TYPE_NODE:
				snprintf(typePrint, 500,"long");
				break;
			case FLOAT_TYPE_NODE:
				snprintf(typePrint, 500,"float");
				break;
			case SIGNED_TYPE_NODE:
				snprintf(typePrint, 500,"signed");
				break;
			case UNSIGNED_TYPE_NODE:
				snprintf(typePrint, 500,"unsigned");
				break;
			case STRUCT_TYPE_NODE:
				snprintf(typePrint, 500,"struct");
				break;
			case UNION_TYPE_NODE:
				snprintf(typePrint, 500,"union");
				break;
			case ENUM_TYPE_NODE:
				snprintf(typePrint, 500,"enum");
				break;
			case TYPEDEF_NAME_TYPE_NODE:
				snprintf(typePrint, 500,"%s",data.dstr);
				break;
			case CONST_TYPE_NODE:
				snprintf(typePrint, 500,"const");
				break;
			case VOLATILE_TYPE_NODE:
				snprintf(typePrint, 500,"volatile");
				break;
			case STRING_TYPE_NODE:
				snprintf(typePrint, 500,"string");
				break;
			case AUTO_TYPE_NODE:
				snprintf(typePrint, 500,"auto");
				break;
			case REGISTER_TYPE_NODE:
				snprintf(typePrint, 500,"register");
				break;
			case STATIC_TYPE_NODE:
				snprintf(typePrint, 500,"static");
				break;
			case EXTERN_TYPE_NODE:
				snprintf(typePrint, 500,"extern");
				break;
			case TYPEDEF_TYPE_NODE:
				snprintf(typePrint, 500,"typedef");
				break;
		}
	}
	else
	{
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
				snprintf(typePrint, 500," ");
		}
		switch(oType)
		{
			case ADD_OP:
				snprintf(operatorPrint, 500,"Left + Right");
				break;
			case SUB_OP:
				snprintf(operatorPrint, 500,"Left - Right");
				break;
			case MULT_OP:
				snprintf(operatorPrint, 500,"Left * Right");
				break;
			case DIV_OP:
				snprintf(operatorPrint, 500,"Left / Right");
				break;
			case MOD_OP:
				snprintf(operatorPrint, 500,"Left %% Right");
				break;
			case COMMA_OP:
				snprintf(operatorPrint, 500,"Left , Right");
				snprintf(typePrint, 500," ");
				break;
			case QUESTION_OP:
				snprintf(operatorPrint, 500,"Left ? Middle : Right");
				break;
			case OR_OP:
				snprintf(operatorPrint, 500,"Left || Right");
				break;
			case AND_OP:
				snprintf(operatorPrint, 500,"Left && Right");
				break;
			case BAR_OP:
				snprintf(operatorPrint, 500,"Left | Right");
				break;
			case CARET_OP:
				snprintf(operatorPrint, 500,"Left ^ Right");
				break;
			case AMP_OP:
				snprintf(operatorPrint, 500,"Left & Right");
				break;
			case BRACKET_OP:
				snprintf(operatorPrint, 500,"Left[Right]");
				break;
			case PAREN_OP:
				snprintf(operatorPrint, 500,"Left(Right)");
				break;					
		}
	}
	if(isOperatorNode)
		fprintf(fileout, "\t%s [label=\"%s %s\"]\n", TreeNodeName.c_str(),typePrint, operatorPrint);
	else
		fprintf(fileout, "\t%s [label=\"%s\"]\n", TreeNodeName.c_str(),typePrint);
	TreeNode::traverse_to_file(fileout);
}
void DataNode::ast_to_3ac(FILE* fileout)
{
	char typePrint1[500];
	char typePrint2[500];
	if(isOperatorNode)
	{
		bool isOpAssign = true;
		string opString;
		string s1;
		string s2;
		string s3;
		children[0]->ast_to_3ac(fileout);
		children[1]->ast_to_3ac(fileout);
		nodeDataType t = children[0]->getDataType(typePrint1);
		if(t == ID_TYPE_NODE) t = children[0]->getidDataType();
		s1 =  rep_3ac_ticket(t,children[0]->returnTicket());		
		t = children[1]->getDataType(typePrint2);
		if(t == ID_TYPE_NODE) t = children[1]->getidDataType();
		s2 =  rep_3ac_ticket(t,children[1]->returnTicket());		

		s3 = rep_3ac_ticket(dType,ticketNumber);
		switch(oType)
		{
			case ADD_OP:
				opString = "ADD\t" + s1 + "\t" + s2;
				break;
			case SUB_OP:
				opString = "SUB\t" + s1 + "\t" + s2;
				break;
			case MULT_OP:
				opString = "MULT\t" + s1 + "\t" + s2;
				break;
			case DIV_OP:
				opString = "DIV\t" + s1 + "\t" + s2;
				break;
			case MOD_OP:
				opString = "MOD\t" + s1 + "\t" + s2;
				break;
			case COMMA_OP:
				opString = "COMMA\t" + s1 + "\t" + s2;
				break;
			case QUESTION_OP:
				opString = "QUESTION\t" + s1 + "\t" + s2;
				break;
			case OR_OP:
				opString = "OR\t" + s1 + "\t" + s2;
				break;
			case AND_OP:
				opString = "AND\t" + s1 + "\t" + s2;
				break;
			case BAR_OP:
				opString = "BAR\t" + s1 + "\t" + s2;
				break;
			case CARET_OP:
				opString = "CARET\t" + s1 + "\t" + s2;
				break;
			case AMP_OP:
				opString = "AMP\t" + s1 + "\t" + s2;
				break;
			case BRACKET_OP:
				opString = "BRACKET\t" + s1 + "\t" + s2;
				s3 = rep_3ac_ticket(getidDataType(),ticketNumber);
				break;
			case PAREN_OP:
				opString = "PAREN\t" + s1 + "\t" + s2;
				break;					
		}
		fprintf(fileout,"%s\t%s\n",opString.c_str(),s3.c_str()); 
	}	
}

void DataNode::storeChar(char c)
{
	data.dchar = c;
	dType = CHAR_TYPE_NODE;
	isData = true;
}
void DataNode::storeInt(int i)
{
	data.dint = i;
	dType = INT_TYPE_NODE;
	isData = true;
}
void DataNode::storeDouble(double d)
{
	data.ddoub = d;
	dType = DOUBLE_TYPE_NODE;
	isData = true;
}
void DataNode::storeString(char *s)
{

	data.dstr = new char [500];
	snprintf(data.dstr,500,"%s",s);

	dType = STRING_TYPE_NODE;
	isData = true;
}

nodeDataType DataNode::getidDataType()
{
	//cout << "here " << idDataTypes.size() << endl;
	for(int i = 0; i < idDataTypes.size(); i++)
	{
		if(idDataTypes[i] == (FLOAT_TYPE_NODE || INT_TYPE_NODE || CHAR_TYPE_NODE || DOUBLE_TYPE_NODE))
				return idDataTypes[i];
	}

}
void DataNode::setidDataTypes(vector<nodeDataType> types)
{
	idDataTypes = types;
}
int DataNode::returnTicket()
{
	return ticketNumber;
}

void DataNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}
	void DataNode::setOperator(OperatorType operatorSpec)
{
	oType = operatorSpec;
	isOperatorNode = true;
}

nodeDataType DataNode::getDataType(char * representation)
{
	if (isData)
	{
		switch(dType)
		{
			case CHAR_TYPE_NODE:
				snprintf(representation, 500,"%c",data.dchar);
				break;
			case INT_TYPE_NODE:
				snprintf(representation, 500,"%d",data.dint);
				break;
			case DOUBLE_TYPE_NODE:
				snprintf(representation, 500,"%f",data.ddoub);
				break;
			case STRING_TYPE_NODE:
				snprintf(representation, 500,"%s",data.dstr);
				break;
			case ID_TYPE_NODE:
				snprintf(representation, 500,"%s",data.dstr);

				// printf("%s\n", data.dstr);	

		}
	}
	return dType;
}

void DataNode::notData()
{
	isData = false;
}

void DataNode::setNumberChildren(int numberOfChildren)
{
	numberChildren = numberOfChildren;
	children.resize(numberOfChildren);
	forErrors.resize(numberOfChildren+1);
	// TreeNode::printNode();
}
void DataNode::errorCheck()
{
		char wat[500];
		nodeDataType left = nodeDataType(children[0]->getDataType(wat));
		nodeDataType right = nodeDataType(children[1]->getDataType(wat));
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

void DataNode::implicitCastWarning(nodeDataType t1, nodeDataType t2)
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
	string d = "Warning: implicit cast of types when performing operation: ";
	string one = t1Print;
	string two = t2Print;
	//TreeNode::errorCheck((d + one + " " + two).c_str());
	yyerror((d + one + " " + two).c_str());
}

