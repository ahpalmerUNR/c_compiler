/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-03 15:44:39
*/
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

extern int symbol_table_debug;
/*
1: no debug
2: print current scope
3: enter and leave scope
5: search keys
 */

using namespace std;
enum Type {
	INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, CHAR_TYPE, VOID_TYPE
};

// Information about the symbol - add more data types in it as necessary
struct Node {
	int lineNumber;
	enum Type type;
	void output(ofstream &stream)
	{
		stream << lineNumber << endl;
	};
};
class SymbolTable {

	/*
	void insert(string tokenKey, int lN);
	Node* searchTop(string key);
	Node* searchAll(string key, int *location);
	void pushEmptyBST();
	void pushBST(map<string, Node> bst);
	void popBST();
	void writeToFile();
	*/
public:

	SymbolTable()
	{
		pushEmptyBST();
		currentLevel = 0;
	}

	void insert(string tokenKey, int lN)
	{
		int location;
		Node *d = searchAll(tokenKey,&location);
		if(d == NULL)
		{
			Node d;
			d.lineNumber = lN;
			stack[currentLevel].insert(pair<string,Node>(tokenKey,d));
		}
		else
		{
			//The identifier already exists so error?
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
	void insert(string tokenKey, Node d)
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
	Node* searchAll(string key, int *location)
	{
		//Print key value and node values on debug level
		int count = 0;
		for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			map<string, Node>::iterator i = it->find( key );
			if(i != it->end())
			{
				// Key exists
				//cout << "Key exists" << endl;
				*location = count;
				return &i->second;
			}
			else
			{
				// Key doesnt exist
			}
			count++;
		}
		return NULL;
	}


	Node* searchTop(string key)
	{
		// Print key value and node values on debug level
		map<string, Node>::iterator it = stack[currentLevel].find( key );
		if(it != stack[currentLevel].end())
		{
			// Key exists
			//cout << "Key exists" << endl;
			return &it->second;
		}
		else
		{
			// Key doesnt exist
			return NULL;
		}
	}
	void writeToFile()
	{
		ofstream stream("output.txt");
		for(vector<map<string, Node> >::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			for(map<string, Node>::iterator i = it->begin(); i != it->end(); ++i)
			{
					stream << i->first << " ";
					i->second.output(stream);
			}
		}

	}
	void printCurrentScope()
	{

	}
	void pushBST(map<string, Node> bst)
	{
		stack.push_back(bst);
		currentLevel++;
	}
	void pushEmptyBST()
	{
		//Debug message
		map<string, Node> bst;
		stack.push_back(bst);
		currentLevel++;
	}
	void popBST()
	{
		//Debug messege
		stack.pop_back();
		currentLevel--;
	}

private:
	vector<map<string, Node> > stack;
	int currentLevel;
};

