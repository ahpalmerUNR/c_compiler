/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-01 16:04:22
*/
#include "symboltable.h"
#include <stdio.h>



SymbolTable::SymbolTable()
{
	currentLevel = -1;
	// Initialize the symbol table with a bst
	pushEmptyBST();
}

Node* SymbolTable::insert(string tokenKey, int lN, int cN, DataType t,int*errorcode)
{
	int location;
	// Search for a previous declaration
	Node *prevDecl = searchAll(tokenKey,&location);
	// No previous : insert symbol
	if(prevDecl == NULL)
	{
		Node d;
		d.lineNumber = lN;
		d.colNumber = cN;
		d.type = t;
		d.name = tokenKey;
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
		return searchTop(tokenKey);

	}
	else
	{
		//cout << "The identifier already exists" << endl;
		// Previous declaration in same level : return error code
		if(location == currentLevel)
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
			stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
			*errorcode = 2;
			return searchTop(tokenKey);

		}
		return prevDecl;
	}

}
Node* SymbolTable::insert(string tokenKey, Node d)
{
	int location;
	// Search for a previous declaration
	Node *prevDecl = searchAll(tokenKey,&location);
	// No previous : insert symbol
	if(prevDecl == NULL)
	{
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
		return searchTop(tokenKey);

	}
	else
	{
		//cout << "The identifier already exists" << endl;
		// Previous declaration in same level : return error code
		if(location == currentLevel)
		{
			cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
		}
		// Previous declaration in another level : shadow warning, insert node
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << prevDecl->lineNumber << endl;
			stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
			return searchTop(tokenKey);
		}
		return prevDecl;
	}

}
Node* SymbolTable::searchAll(string key, int *location)
{
	//cout<<"entered search all"<<endl;
	//Print key value and node values on debug level
	// Iterate from top to bottom of stack and return first node or null if not found
	for(int i = currentLevel; i >= 0; i--)
	{
		map<string, Node>::iterator it = stack[i].find( key );
		if(it != stack[i].end())
		{
			// Key exists
			if(symbol_table_debug % 5  == 0)
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
	if(symbol_table_debug % 5  == 0)
	{
		cout << "Level 5 debug: Level: NA" << " Key: " << key << " " << "NA" << endl;
	}
	//cout<<"leaving searchAll"<<endl;
	return NULL;
}


Node* SymbolTable::searchTop(string key)
{
	// Print key value and node values on debug level
	// Search top level and return node found or NULL
	map<string, Node>::iterator it = stack[currentLevel].find( key );
	if(it != stack[currentLevel].end())
	{
		// Key exists
		if(symbol_table_debug % 5  == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " ";
			it->second.print();
		}
		return &it->second;
	}
	else
	{
		if(symbol_table_debug % 5  == 0)
		{
			cout << "Level 5 debug: Level: " << currentLevel << " Key: " << it->first << " " << "NA" << endl;
		}
		// Key doesnt exist
		return NULL;
	}
}
void SymbolTable::writeToFile(FILE* stream)
{
	//char const *fileName)
	string text;
	// ofstream stream;
	// stream.open(fileName,fstream::app);
	int count = 0;
	fprintf(stream, "SYMBOL TABLE DUMP\n");
	// Iterate through symbol table and dump contents to file
	for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		for(map<string, Node>::iterator i = it->begin(); i != it->end(); ++i)
		{
			text = i->first;
			fprintf(stream, "Level: %d Key: %s ",count,text.c_str());
			// stream << "Level: " << count << " Key: " << i->first << " ";
			// cout <<"HERE"<< i->first << endl;
			// cout<<endl;
			i->second.output(stream);
		}
		count++;
	}
	fprintf(stream, "\n\nSYMBOL TABLE ABOVE\n\n");
	// stream<<"\n\nSYMBOL TABLE ABOVE"<<endl<<endl;
	// stream.close();
}
void SymbolTable::printCurrentScope()
{
		// Iterate through top level and output information
		for(map<string, Node>::iterator i = stack[currentLevel].begin(); i != stack[currentLevel].end(); ++i)
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
void SymbolTable::pushEmptyBST()
{
	// Push empty bst and increment level
	map<string, Node> bst;
	stack.push_back(bst);
	currentLevel++;
	//Debug message
	if(symbol_table_debug % 2  == 0)
		cout << "Level 3 debug: Entering new scope of level: " << currentLevel << endl;
}
void SymbolTable::popBST()
{
	// Pop bst and decrement level
	stack.pop_back();
	currentLevel--;
	//Debug messege
	if(symbol_table_debug % 2  == 0)
		cout << "Level 3 debug: Exiting scope, new level: " << currentLevel << endl;
}

