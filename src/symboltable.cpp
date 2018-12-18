/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-12-03 14:44:27
*/
#include "symboltable.h"
#include <stdio.h>

string getDataType(nodeDataType type)
{
	switch (type)
	{
	case INT_TYPE_NODE:
		return ("int");
	case DOUBLE_TYPE_NODE:
		return ("double");
	case CHAR_TYPE_NODE:
		return ("char");
	case VOID_TYPE_NODE:
		return ("void");
	case POINTER_TYPE_NODE:
		return ("*");
	case SHORT_TYPE_NODE:
		return ("short");
	case LONG_TYPE_NODE:
		return ("long");
	case FLOAT_TYPE_NODE:
		return ("float");
	case SIGNED_TYPE_NODE:
		return ("signed");
	case UNSIGNED_TYPE_NODE:
		return ("unsigned");
	case STRUCT_TYPE_NODE:
		return ("struct");
	case UNION_TYPE_NODE:
		return ("union");
	case ENUM_TYPE_NODE:
		return ("enum");
	case TYPEDEF_NAME_TYPE_NODE:
		return ("typedef");
	case CONST_TYPE_NODE:
		return ("const");
	case VOLATILE_TYPE_NODE:
		return ("volatile");
	case AUTO_TYPE_NODE:
		return ("auto");
	case REGISTER_TYPE_NODE:
		return ("register");
	case STATIC_TYPE_NODE:
		return ("static");
	case EXTERN_TYPE_NODE:
		return ("extern");
	case TYPEDEF_TYPE_NODE:
		return ("typedef");
	case ID_TYPE_NODE:
		return ("id");
	default:
		return ("ERROR");
	}
}

Node::Node()
{
}

Node::Node(const Node &n)
{
	lineNumber = n.lineNumber;
	colNumber = n.colNumber;
	for (const nodeDataType type : n.types)
	{
		types.push_back(type);
	}

	ntype = n.ntype;
	name = n.name;
	ticketNumber = n.ticketNumber;
	for (const vector<nodeDataType> paramVector : n.params)
	{
		params.push_back(paramVector);
	}
}

void Node::print()
{
	cout << "line: " << lineNumber << " col: " << colNumber;
	cout<<" ticketNumber: "<<ticketNumber;
	cout << " types: ";
	for (const nodeDataType type : types)
	{
		cout << getDataType(type) << " ";
	}
	cout << "(node) key: " << name;
	
	if (params.size())
	{
		cout << "Params: (";
		for (const vector<nodeDataType> paramVector : params)
		{
			for (const nodeDataType param : paramVector)
			{
				cout << getDataType(param) << " ";
			}
			cout << ", ";
		}
		cout << ")";
	}
	cout << endl;
}

void Node::output(FILE *stream)
{
	fprintf(stream, "Line: %d, Col: %d, Ticket Number:%d, Types: ", lineNumber, colNumber,ticketNumber);
	for (const nodeDataType type : types)
	{
		fprintf(stream, "%s ", getDataType(type).c_str());
	}
	// If debugging -- to check if symTab and node keys line up.
	// fprintf(stream, "(Node) Key: %s", name.c_str());
	if (params.size())
	{
		fprintf(stream, " Params: (");
		for (const vector<nodeDataType> paramVector : params)
		{
			for (const nodeDataType param : paramVector)
			{
				fprintf(stream, "%s ", getDataType(param).c_str());
			}
			fprintf(stream, ", ");
		}
		fprintf(stream, ")");
	}
	if(arraySizes.size())
	{
		fprintf(stream, " Array Sizes: ");
		for (const int size : arraySizes)
		{
			fprintf(stream, "%d ", size);
		}
	}
	fprintf(stream, "\n");
}

bool Node::compareFunction(Node nodeToCompare) {
	if (name != nodeToCompare.name) {
		cout << "ST Error: Names not the same:" << name << " " << nodeToCompare.name << endl;
		return false;
	}
	for (vector<nodeDataType>::iterator i = types.begin(); i != types.end(); i++) {
		
	}
}

SymbolTable::SymbolTable()
{
	currentLevel = -1;
	// Initialize the symbol table with a bst
	pushEmptyBST();
}

SymbolTable::SymbolTable(string n)
{
	name = n;
	currentLevel = -1;
	// Initialize the symbol table with a bst
	pushEmptyBST();
	// Add reserved functions
	Node readIntNode;
	readIntNode.name = "readInt";
	readIntNode.isDefined = true;
	readIntNode.types.push_back(INT_TYPE_NODE);
	insert("readInt", readIntNode);

	Node readCharNode;
	readCharNode.name = "readChar";
	readCharNode.isDefined = true;
	readCharNode.types.push_back(CHAR_TYPE_NODE);
	insert("readChar", readCharNode);

	Node readFloatNode;
	readFloatNode.name = "readFloat";
	readFloatNode.isDefined = true;
	readFloatNode.types.push_back(DOUBLE_TYPE_NODE);
	insert("readChar", readFloatNode);

	Node writeIntNode;
	writeIntNode.name = "writeInt";
	writeIntNode.isDefined = true;
	writeIntNode.types.push_back(VOID_TYPE_NODE);
	writeIntNode.params.push_back({ INT_TYPE_NODE });
	insert("writeInt", writeIntNode);

	Node writeCharNode;
	writeCharNode.name = "writeChar";
	writeCharNode.isDefined = true;
	writeCharNode.types.push_back(VOID_TYPE_NODE);
	writeCharNode.params.push_back({ CHAR_TYPE_NODE });
	insert("writeChar", writeCharNode);

	Node writeFloat;
	writeFloat.name = "writeFloat";
	writeFloat.isDefined = true;
	writeFloat.types.push_back(VOID_TYPE_NODE);
	writeFloat.params.push_back({ DOUBLE_TYPE_NODE });
	insert("writeFloat", writeFloat);
}

Node *SymbolTable::insert(string tokenKey, int lN, int cN, DataType t, int *errorcode)
{
	// cout<<"Here"<<endl;
	// cout.flush();
	int location;
	// Search for a previous declaration
	Node *prevDecl = searchAll(tokenKey, &location);
	// No previous : insert symbol
	if (prevDecl == NULL)
	{
		Node d;
		d.lineNumber = lN;
		d.colNumber = cN;
		// d.type = t;
		d.name = tokenKey;
		stack[currentLevel].insert(pair<string, Node>(tokenKey, d));
		return searchTop(tokenKey);
	}
	else
	{
		//cout << "The identifier already exists" << endl;
		// Previous declaration in same level : return error code
		if (location == currentLevel)
		{
			// cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
			//
			*errorcode = 1;
		}
		// Previous declaration in another level : shadow warning, insert node
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << prevDecl->lineNumber << endl;
			Node d;
			d.lineNumber = lN;
			d.colNumber = cN;
			d.type = t;
			stack[currentLevel].insert(pair<string, Node>(tokenKey, d));
			*errorcode = 2;
			return searchTop(tokenKey);
		}
		return prevDecl;
	}
}

Node *SymbolTable::insert(string tokenKey, Node d)
{
	int location;
	// Search for a previous declaration
	Node *prevDecl = searchAll(tokenKey, &location);
	// No previous : insert symbol
	if (prevDecl == NULL)
	{
		stack[currentLevel].insert(pair<string, Node>(tokenKey, d));
		return searchTop(tokenKey);
	}
	else
	{
		//cout << "The identifier already exists" << endl;
		// Previous declaration in same level : return error code
		if (location == currentLevel)
		{
			cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
		}
		// Previous declaration in another level : shadow warning, insert node
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << prevDecl->lineNumber << endl;
			stack[currentLevel].insert(pair<string, Node>(tokenKey, d));
			return searchTop(tokenKey);
		}
		return prevDecl;
	}
}

Node *SymbolTable::searchAll(string key, int *location)
{
	//cout<<"entered search all"<<endl;
	//Print key value and node values on debug level
	// Iterate from top to bottom of stack and return first node or null if not found
	for (int i = currentLevel; i >= 0; i--)
	{
		map<string, Node>::iterator it = stack[i].find(key);
		if (it != stack[i].end())
		{
			// Key exists
			if (symbol_table_debug % 5 == 0)
			{
				cout << "Level 5 debug: Level: " << i << " Key: " << it->first << " ";
				it->second.print();
			}
			//cout<<"location found"<<endl;
			*location = i;
			//cout<<"location set"<<endl;
			return &it->second;
		}
		else
		{
			// Key doesnt exist
		}
	}
	if (symbol_table_debug % 5 == 0)
	{
		cout << "Level 5 debug: Level: NA"
			 << " Key: " << key << " "
			 << "NA" << endl;
	}
	//cout<<"leaving searchAll"<<endl;
	return NULL;
}

Node *SymbolTable::searchTop(string key)
{
	// Print key value and node values on debug level
	// Search top level and return node found or NULL
	map<string, Node>::iterator it = stack[currentLevel].find(key);
	if (it != stack[currentLevel].end())
	{
		// Key exists
		if (symbol_table_debug % 5 == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " ";
			it->second.print();
		}
		return &it->second;
	}
	else
	{
		if (symbol_table_debug % 5 == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " "
				 << "NA" << endl;
		}
		// Key doesnt exist
		return NULL;
	}
}

Node *SymbolTable::searchBottom(string key)
{
	if (currentLevel < 0) {
		return NULL;
	}
	// Print key value and node values on debug level
	// Search top level and return node found or NULL
	map<string, Node>::iterator it = stack[0].find(key);
	if (it != stack[currentLevel].end())
	{
		// Key exists
		if (symbol_table_debug % 5 == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " ";
			it->second.print();
		}
		return &it->second;
	}
	else
	{
		if (symbol_table_debug % 5 == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " "
				 << "NA" << endl;
		}
		// Key doesnt exist
		return NULL;
	}
}

void SymbolTable::writeToFile(FILE *stream)
{
	//char const *fileName)
	string text;
	// ofstream stream;
	// stream.open(fileName,fstream::app);
	int count = 0;
	fprintf(stream, "%s: SYMBOL TABLE DUMP\n", name.c_str());
	// Iterate through symbol table and dump contents to file
	for (vector<map<string, Node>>::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		for (map<string, Node>::iterator i = it->begin(); i != it->end(); ++i)
		{
			text = i->first;
			fprintf(stream, "Level: %d Key: %s ", count, text.c_str());
			// stream << "Level: " << count << " Key: " << i->first << " ";
			// cout <<"HERE"<< i->first << endl;
			// cout<<endl;
			i->second.output(stream);
		}
		count++;
	}
	fprintf(stream, "\n\n%s: SYMBOL TABLE ABOVE\n\n", name.c_str());
	// stream<<"\n\nSYMBOL TABLE ABOVE"<<endl<<endl;
	// stream.close();
	fflush(stream);
}

void SymbolTable::printCurrentScope()
{
	// Iterate through top level and output information
	for (map<string, Node>::iterator i = stack[currentLevel].begin(); i != stack[currentLevel].end(); ++i)
	{
		cout << "Level: " << currentLevel << " Key: " << i->first << " ";
		i->second.print();
	}
}

void SymbolTable::pushBST(map<string, Node> bst)
{
	//Push bst and increment level
	stack.push_back(bst);
	currentLevel++;
}

void SymbolTable::pushSymbolTableCopy(const SymbolTable stCopy)
{
	FILE* fi = fopen("build/table.txt", "w");
	if (stCopy.currentLevel == -1) {
		return;
	}
	for (map <string, Node> bst : stCopy.stack) {
		bst[0].output(fi);
		fflush(fi);
		stack.push_back(bst);
		currentLevel++;
	}
}

void SymbolTable::pushEmptyBST()
{
	// Push empty bst and increment level
	map<string, Node> bst;
	stack.push_back(bst);
	currentLevel++;
	//Debug message
	// if(symbol_table_debug % 2  == 0)
		// cout << "Level 3 debug: Entering new scope of level: " << currentLevel << endl;

	cout.flush();

}

void SymbolTable::popBST()
{
	// Pop bst and decrement level
	stack.pop_back();
	currentLevel--;
	//Debug messege
	if (symbol_table_debug % 2 == 0)
		cout << "Level 3 debug: Exiting scope, new level: " << currentLevel << endl;
	cout.flush();
	
}

void SymbolTable::popUntilGlobal()
{
	while (currentLevel > 0) {
		// Pop bst and decrement level
		stack.pop_back();
		currentLevel--;
	}
	//Debug messege
	if (symbol_table_debug % 2 == 0)
		cout << "Level 3 debug: Exiting scope, new level: " << currentLevel << endl;
	cout.flush();
	
}
