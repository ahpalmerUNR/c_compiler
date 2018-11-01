#include"dataNode.h"

DataNode::DataNode(int nodeNumber, string nodeName, int ticket) : TreeNode(nodeNumber,nodeName,0)
{
	ticketNumber = ticket;
	isData = false;
}

DataNode::~DataNode()
{

}

void DataNode::traverse_to_file(FILE* fileout) 
{
	char typePrint[500];
	
	if (isData)
	{
		switch(dType)
		{
			case CHAR_TYPE_NODE:
				snprintf(typePrint, 500,"%c",data.dchar);
				break;
			case INT_TYPE_NODE:
				snprintf(typePrint, 500,"%d",data.dint);
				break;
			case DOUBLE_TYPE_NODE:
				snprintf(typePrint, 500,"%f",data.ddoub);
				break;
			case STRING_TYPE_NODE:
				snprintf(typePrint, 500,"%s",data.dstr);
			
		}
	}
	else
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
	// cout<<"Data Node "<<TreeNodeName<<endl;
	fprintf(fileout, "\t%s [label=\"%s\"]\n", TreeNodeName.c_str(),typePrint);
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
	data.dstr = s;
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
	
int DataNode::getDataType()
{
	return dType;
}

void DataNode::notData()
{
	isData = false;
}