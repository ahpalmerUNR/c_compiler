/*
* @Author: ahpalmerUNR
* @Date:   2018-09-28 12:11:57
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-03 15:44:39
*/
#ifndef SYMBOTABLE
#define SYMBOTABLE

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
enum DataType {
	INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, CHAR_TYPE, VOID_TYPE
};
enum NType{
	ID, ENUMERATION_CONSTANT, TYPEDEF_NAME
};
// Information about the symbol - add more data types in it as necessary
struct Node {
	int lineNumber;
	int colNumber;
	enum DataType type;
	int ntype = 1;
	void output(ofstream &stream)
	{
		stream << "Line: " << lineNumber << " Column: " << colNumber << " Type: " << type << endl;
	};
	void print()
	{
		cout << "Line: " << lineNumber << " Column: " << colNumber << " Type: " << type << endl;
	};
};
class SymbolTable {

public:

	SymbolTable();

	Node* insert(string tokenKey, int lN, int cN, DataType t,int*errorcode);
	Node* insert(string tokenKey, Node d);
	Node* searchAll(string key, int *location);


	Node* searchTop(string key);
	void writeToFile(char const *);
	void printCurrentScope();
	void pushBST(map<string, Node> bst);
	void pushEmptyBST();
	void popBST();
private:
	vector<map<string, Node> > stack;
	int currentLevel;
};

#endif
