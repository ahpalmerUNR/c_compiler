/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-03 15:44:39
*/
#include "symboltable.h"

SymbolTable::SymbolTable()
{
	currentLevel = -1;
	pushEmptyBST();
}

void SymbolTable::insert(string tokenKey, int lN, DataType t)
{
	int location;
	Node *d = searchAll(tokenKey,&location);
	if(d == NULL)
	{
		Node d;
		d.lineNumber = lN;
		d.type = t;
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
	}
	else
	{
		//The identifier already exists
		if(location == currentLevel)
		{
			cout << "Conflict with variable in current level on line number: " << d->lineNumber << endl;
		}
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << d->lineNumber << endl;
		}
	}

}
void SymbolTable::insert(string tokenKey, Node d)
{
	int location;
	Node *prevDecl = searchAll(tokenKey,&location);
	if(prevDecl == NULL)
	{
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
	}
	else
	{
		//The identifier already exists
		if(location == currentLevel)
		{
			cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
		}
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << prevDecl->lineNumber << endl;
		}
	}

}
Node* SymbolTable::searchAll(string key, int *location)
{
	//Print key value and node values on debug level
	int count = 0;
	for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		map<string, Node>::iterator i = it->find( key );
		if(i != it->end())
		{
			// Key exists
			if(symbol_table_debug % 5  == 0)
			{
				cout << "Level 5 debug: Level: " << count << " Key: " << i->first << " ";
				i->second.print();
			}
			*location = count;
			return &i->second;
		}
		else
		{
			// Key doesnt exist
		}
		count++;
	}
	if(symbol_table_debug % 5  == 0)
	{
		cout << "Level 5 debug: Level: NA" << " Key: " << key << " " << "NA" << endl;
	}
	return NULL;
}


Node* SymbolTable::searchTop(string key)
{
	// Print key value and node values on debug level
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
void SymbolTable::writeToFile()
{
	ofstream stream("output.txt");
	int count = 0;
	for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		for(map<string, Node>::iterator i = it->begin(); i != it->end(); ++i)
		{
			stream << "Level: " << count << " Key: " << i->first << " ";
			i->second.output(stream);
		}
		count++;
	}
	stream.close();
}
void SymbolTable::printCurrentScope()
{
		for(map<string, Node>::iterator i = stack[currentLevel].begin(); i != stack[currentLevel].end(); ++i)
		{
				cout << "Level: " << currentLevel << " Key: " << i->first << " ";
				i->second.print();
		}
}
void SymbolTable::pushBST(map<string, Node> bst)
{
	stack.push_back(bst);
	currentLevel++;
}
void SymbolTable::pushEmptyBST()
{
	map<string, Node> bst;
	stack.push_back(bst);
	currentLevel++;
	//Debug message
	if(symbol_table_debug % 2  == 0)
		cout << "Level 3 debug: Entering new scope of level: " << currentLevel << endl;	
}
void SymbolTable::popBST()
{
	stack.pop_back();
	currentLevel--;
	//Debug messege
	if(symbol_table_debug % 2  == 0)
		cout << "Level 3 debug: Exiting scope, new level: " << currentLevel << endl;
}

