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

// Integer declared in the parser to set debug levels
extern int symbol_table_debug;
/*
1: no debug
2: print current scope
3: enter and leave scope
5: search keys
 */

using namespace std;

// To store what type the declaration is
enum DataType {
	INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, CHAR_TYPE, VOID_TYPE
};

enum nodeDataType { 
	INT_TYPE_NODE,
	DOUBLE_TYPE_NODE,
	CHAR_TYPE_NODE,
	VOID_TYPE_NODE,
	POINTER_TYPE_NODE,
	SHORT_TYPE_NODE,
	LONG_TYPE_NODE,
	FLOAT_TYPE_NODE,
	SIGNED_TYPE_NODE,
	UNSIGNED_TYPE_NODE,
	STRUCT_TYPE_NODE,
	UNION_TYPE_NODE,
	ENUM_TYPE_NODE,
	TYPEDEF_NAME_TYPE_NODE,
	CONST_TYPE_NODE,
	VOLATILE_TYPE_NODE,
	STRING_TYPE_NODE,
	AUTO_TYPE_NODE,
	REGISTER_TYPE_NODE,
	STATIC_TYPE_NODE,
	EXTERN_TYPE_NODE,
	TYPEDEF_TYPE_NODE,
	ID_TYPE_NODE,
	EMPTY_TYPE_NODE,
	TREE_TYPE_NODE
};

string getDataType(nodeDataType);

// To store if the declaration is Id, enum or, typedef
enum NType{
	ID, ENUMERATION_CONSTANT, TYPEDEF_NAME
};
// Information about the symbol - add more data types in it as necessary
struct Node {
	Node();
	Node(const Node&);
	void print();
	void output(FILE*);

	int lineNumber;
	int colNumber;
	enum DataType type;
	// Vector containing the types of the node
	vector<nodeDataType> types;
	int ntype = 1;
	string name;
	// Contains the params of node (if it is a function)
	vector<vector<nodeDataType>> params;
};
class SymbolTable {

public:

	//Default constructor for SymbolTable
	SymbolTable();

	//Insert a node with the parameters specified, return new node or previous node
	Node* insert(string tokenKey, int lN, int cN, DataType t,int*errorcode);  
	
	//Insert a node that was premade, return new node or previous node
	Node* insert(string tokenKey, Node d);

	//Search whole symbol table starting from the top level down and return a pointer the first correct node found or NULL if not found and storing the level its found in location
	Node* searchAll(string key, int *location);

	// Search the top level of the symbol table return pointer to the node or NULL
	Node* searchTop(string key);

	// Dump the symbol table to the file
	void writeToFile(FILE*); 
	
	// Print the current scope for debugging purposes
	void printCurrentScope();

	// Push a predefined bst on the stack
	void pushBST(map<string, Node> bst);

	// Push an empty bst on the stack
	void pushEmptyBST();

	// Pop the top bst from the stack
	void popBST();
private:
	// Stack of Balanced binary search trees
	vector<map<string, Node> > stack;
	// Current level of the stack
	int currentLevel;
};

#endif
