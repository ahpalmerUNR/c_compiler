#include "dataNode.h"

DataNode::DataNode(int nodeNumber, string nodeName, int ticket) : TreeNode(nodeNumber,nodeName,0)
{
	ticketNumber = ticket;
	isData = false;
	isOperatorNode = false;
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
				snprintf(typePrint, 500,"ID: %s",data.dstr);
			
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
int DataNode::getDataType(char * representation)
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
				printf("%s\n", data.dstr);	
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
}


