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
vector<map<string, data> > stack;

void insert(string tokenKey, int lN);
data* searchTop(string key);
data* searchAll(string key);
void pushBST(map<string, data> bst);
void popBST();
void writeToFile();


int main()
{
	map<string, data> bst;
	pushBST(bst);

	insert("1",1);
	insert("2",2);
	insert("3",3);
	// For testing the search
	//data *d = searchTop("1");
	//stack[0].insert(pair<string,data>("4",*d));
	//data *e = searchAll("1");
	//stack[0].insert(pair<string,data>("5",*e));

	writeToFile();


}
void insert(string tokenKey, int lN)
{
	if(searchTop(tokenKey) == NULL)
	{
		data d;
		d.lineNumber = lN;
		stack[0].insert(pair<string,data>(tokenKey,d));
	}
	else
	{
		//The identifier already exists so error?
	}

}

data* searchAll(string key)
{
	for(vector<map<string, data> >::iterator it = stack.begin(); it != stack.end(); ++it)
	{
		map<string, data>::iterator i = it->find( key );
		if(i != it->end())
		{
			// Key exists
			cout << "Key exists" << endl;
			return &i->second;
		}
		else
		{
			// Key doesnt exist
		}
	}
	return NULL;
}


data* searchTop(string key)
{
	map<string, data>::iterator it = stack[0].find( key );
	if(it != stack[0].end())
	{
		// Key exists
		cout << "Key exists" << endl;
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
void popBST()
{
	stack.pop_back();
}
