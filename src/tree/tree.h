#ifndef TREE
#define TREE

#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "../symboltable.h"
#include "../MIPS_Type_Sizes.h"


using namespace std;

extern SymbolTable astTable;
extern void yyerror(char const * msg);
extern int line;
extern int column;
extern FILE* errorText;
extern FILE* out_log;
extern int MAX_LINE_LENGTH;
extern char* file_name;
extern int AST_node_counter;
extern int Label_counter;
extern int Variable_counter;
extern int currentCodeLine;


enum OperatorType {
	ADD_OP,
	SUB_OP,
	MULT_OP,
	DIV_OP,
	MOD_OP,
	EQ_OP,
	NE_OP,
	GT_OP,
	GE_OP,
	LT_OP,
	LE_OP,
	COMMA_OP,
	QUESTION_OP,
	OR_OP,
	AND_OP,
	BAR_OP,
	CARET_OP,
	AMP_OP,
	BRACKET_OP,
	PAREN_OP
	};
	
enum AssignType {
	EQUAL_ASSIGN,
	ADD_ASSIGN,
	SUB_ASSIGN,
	MULT_ASSIGN,
	DIV_ASSIGN,
	MOD_ASSIGN,
	LEFT_ASSIGN,
	RIGHT_ASSIGN,
	AND_ASSIGN,
	XOR_ASSIGN,
	OR_ASSIGN
	};

struct sourceLine
{
	int lineNum;
	string codeLine;
};

struct ErrorReport{
	int lineStart;
	int lineEnd;
	int colStart;
	int colEnd;
	vector<sourceLine> source;
};

class FunctionNode;

class TreeNode
{
	friend class FunctionNode;friend class TypeNode;
public:
	TreeNode(string TreeNodeProductionName,int numberOfChildren);
	~TreeNode();
	virtual void traverse_to_file(FILE*);
	virtual void ast_to_3ac(FILE*);
	virtual void assignChild(int childIndex, TreeNode* child);
	virtual nodeDataType getDataType(char *){return tType;}
	virtual void setTypeSpecifier(nodeDataType typeSpec);
	//virtual int getDataType(char *){ return -1; }
	virtual nodeDataType getidDataType(){};
	virtual vector<nodeDataType> getTypes();
	virtual void setidDataTypes(int types){};
	virtual int returnTicket(){}
	virtual void setArrayOffset(int i){arrayOffset = i;}
	virtual int getArrayOffset(){return arrayOffset;}
	void printNode();
	bool checkChildZ();
	void setNoBytes();
	virtual void errorCheck(const char * str);
	virtual void assignLine(int,int,int,string);
	virtual bool isIDList(){return false;}
	void setTicketNumber(int t){ticketNumber = t;}
	int getTicketNumber(){return ticketNumber;}
	bool isArrayNode(){return false;}
	void setLHS(){};
	string coldLine();
	string rep_3ac_ticket(nodeDataType ndt, int ticket);
protected:
	int TreeNodeNumber;
	//type
	vector<ErrorReport> forErrors;
	string TreeNodeName;
	int numberChildren;
	vector<TreeNode*> children;
	vector<nodeDataType> types;
	nodeDataType tType;
	int byteSize;
	int arrayOffset;
	int ticketNumber;
};

class Tree
{
public:
	Tree();
	~Tree();
	void tree_to_gv(string fileName);
	void tree_to_3ac(string fileName);
	void set_root(TreeNode* new_root);
private:
	TreeNode* root;
};
#endif
