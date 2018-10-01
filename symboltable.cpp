/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-09-28 15:07:43
*/
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Information about the symbol - add more data types in it as necessary
struct data {
	int lineNumber;

	void output(ofstream &stream)
	{
		stream << lineNumber << endl;
	};
};
class SymbolTable {

	/*
	void insert(string tokenKey, int lN);
	data* searchTop(string key);
	data* searchAll(string key, int *location);
	void pushEmptyBST();
	void pushBST(map<string, data> bst);
	void popBST();
	void writeToFile();
	*/
public: 
	void insert(string tokenKey, int lN)
	{
		int location;
		data *d = searchAll(tokenKey,&location);
		if(d == NULL)
		{
			data d;
			d.lineNumber = lN;
			stack[0].insert(pair<string,data>(tokenKey,d));
		}
		else
		{
			//The identifier already exists so error?
			cout << "Shadowed variable in level: " << location << " On line number: " << d->lineNumber << endl;
		}

	}

	data* searchAll(string key, int *location)
	{
		int count = 0;
		for(vector<map<string, data> >::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			map<string, data>::iterator i = it->find( key );
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


	data* searchTop(string key)
	{
		map<string, data>::iterator it = stack[0].find( key );
		if(it != stack[0].end())
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
		for(vector<map<string, data> >::iterator it = stack.begin(); it != stack.end(); ++it)
		{
			for(map<string, data>::iterator i = it->begin(); i != it->end(); ++i)
			{
					stream << i->first << " ";
					i->second.output(stream);
			}
		}

	}
	void pushBST(map<string, data> bst)
	{
		stack.push_back(bst);
	}
	void pushEmptyBST()
	{
		map<string, data> bst;
		stack.push_back(bst);
	}
	void popBST()
	{
		stack.pop_back();
	}

private:
	vector<map<string, data> > stack;
};
// Driver for now need to test other things still
int main()
{
	SymbolTable s;
	map<string, data> bst;
	s.pushBST(bst);
	s.insert("1",1);
	s.insert("2",2);
	s.insert("3",3);
	s.insert("1",21);
	s.pushEmptyBST();
	s.insert("4",21);

	s.writeToFile();


	}
