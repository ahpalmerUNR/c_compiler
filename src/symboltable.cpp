/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-18 13:51:44
*/
#include "symboltable.h"


SymbolTable::SymbolTable()
{
	currentLevel = -1;
	pushEmptyBST();
}

Node* SymbolTable::insert(string tokenKey, int lN, int cN, DataType t,int*errorcode)
{
	int location;
	Node *prevDecl = searchAll(tokenKey,&location);
	if(prevDecl == NULL)
	{
		Node d;
		d.lineNumber = lN;
		d.colNumber = cN;
		d.type = t;
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
		return searchTop(tokenKey);

	}
	else
	{
		//cout << "The identifier already exists" << endl;
		if(location == currentLevel)
		{
			// cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
			// 
			*errorcode = 1;
		}
		else
		{
			cout << "Shadowed variable in level: " << location << " On line number: " << prevDecl->lineNumber << endl;
			Node d;
			d.lineNumber = lN;
			d.colNumber = cN;
			d.type = t;
			stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
			return searchTop(tokenKey);

		}
		return prevDecl;
	}

}
Node* SymbolTable::insert(string tokenKey, Node d)
{
	int location;
	Node *prevDecl = searchAll(tokenKey,&location);
	if(prevDecl == NULL)
	{
		stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
		return searchTop(tokenKey);

	}
	else
	{
		cout << "The identifier already exists" << endl;
		if(location == currentLevel)
		{
			cout << "Conflict with variable in current level on line number: " << prevDecl->lineNumber << endl;
		}
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
void SymbolTable::writeToFile(char const *fileName)
{
	ofstream stream;
	stream.open(fileName,fstream::app);
	int count = 0;
	stream<<"SYMBOL TABLE DUMP\n"<<endl;
	for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		for(map<string, Node>::iterator i = it->begin(); i != it->end(); ++i)
		{
			stream << "Level: " << count << " Key: " << i->first << " ";
			i->second.output(stream);
		}
		count++;
	}
	stream<<"\n\nSYMBOL TABLE ABOVE"<<endl<<endl;
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

