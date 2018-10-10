#include"symboltable.h"
// Will be in parser
int symbol_table_debug;
int main()
{

	SymbolTable s;
	// Test insert
	s.insert("1",1,INT_TYPE);
	s.insert("2",2,FLOAT_TYPE);
	s.insert("3",3,DOUBLE_TYPE);
	// Should be a conflict
	s.insert("1",4,CHAR_TYPE);
	// Add a new level
	s.pushEmptyBST();

	// Insert into second level BST
	s.insert("4",5,VOID_TYPE);
	//Should be shadowed
	s.insert("2",6,INT_TYPE);
	// Pop a level
	s.popBST();
	// Push a new level
	s.pushEmptyBST();
	// Shouldnt produce a problem
	s.insert("4",7,INT_TYPE);
	Node dat;
	dat.lineNumber = 8;
	dat.type = VOID_TYPE;
	s.insert("5",dat);

	s.pushEmptyBST();
	//Should be shadowed from level 0 line 2
	s.insert("2",10,FLOAT_TYPE);

	// Should return pointer to node on line 7
	Node *d = s.searchTop("4");
	if(d != NULL)
		cout << "This line number should be 7: " << d->lineNumber << endl;

	int loc;
	// Search all should return location 0 for bottom of stack and line 2
	d = s.searchAll("2",&loc);
	if(d != NULL)
 		cout << "This line number should be 10 for level 2. Line: " << d->lineNumber << ". Level: " << loc << endl ;

	//s.printCurrentScope();
	// Write the stack of BST to the file
	s.writeToFile();

}
