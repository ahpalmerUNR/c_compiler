#include "../src/symboltable.h"
// Will be in parser
int symbol_table_debug = 1;

// Sample Test of Symbol Table 

int main()
{
	// Used by scanner to deal with conflicts/redeclarations
	int errorCode;
	// Level a declaration was found in
	int level;
	// Node pointer to set when searching and inserting
	Node *n;

	SymbolTable s;
	//1 int j;
	n = s.insert("j",1,11, INT_TYPE,&errorCode);
	//2 void func();
	n = s.insert("func",2,12,VOID_TYPE,&errorCode);
	//3 int main()
	n = s.insert("main",3,11,INT_TYPE,&errorCode);
	//4 {
	s.pushEmptyBST();
	//5 float p = 1.44;
	n = s.insert("p",5,13,FLOAT_TYPE,&errorCode);
	//6 float k = -2.43;
	n = s.insert("k",6,13,FLOAT_TYPE,&errorCode);
	//7 int j = 0;
	n = s.insert("j",7,11,INT_TYPE,&errorCode);
	//8 int q = 1;
	n = s.insert("q",8,11,INT_TYPE,&errorCode);
	
	
	//9 char burrito = 'b';	
	n = s.insert("burrito",9,12,CHAR_TYPE,&errorCode);
	//10 char taco = 't';
	n = s.insert("taco",10,13,CHAR_TYPE,&errorCode);
	//11 char taco;
	n = s.insert("taco",11,13,CHAR_TYPE,&errorCode);
	if(errorCode == 1) 
		std::cout << "Conflict with variable in current level on line/column: " << n->lineNumber << "/" << n->colNumber << std::endl;
	//12 !!D	
	s.writeToFile("driverOut.txt");
	//13 int o = 44;
	n = s.insert("o",13,12,INT_TYPE,&errorCode);
	//14 if(i==4)
	n = s.searchAll("j",&level);
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line/column: " << n->lineNumber << "/" << n->colNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//15 {
	s.pushEmptyBST();
	//16 		int j =2;
	n = s.insert("j",16,15,INT_TYPE,&errorCode);
	//17		!!D
	s.writeToFile("driverOut.txt");
	//18 		if(j == 2)
	n = s.searchAll("j",&level);
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line/column: " << n->lineNumber << "/" << n->colNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//19 		{
	s.pushEmptyBST();
	//20			int k;
	n = s.insert("k",20,17,INT_TYPE,&errorCode);
	//21	  	!!D;
	s.writeToFile("driverOut.txt");
	//22 		}
	s.popBST();
	//23 }
	s.popBST();
	//24 if(z == 1) do something;
	n = s.searchAll("z",&level);
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line/column: " << n->lineNumber << "/" << n->colNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//25 !!D
	s.writeToFile("driverOut.txt");

	// For testing searchTop and Testing that node is reconfigurable
	n = s.searchTop("j");
	n->lineNumber = 500;

	// For testing searchTop on that reconfigured node
	n = s.searchTop("j");
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line/column: " << n->lineNumber << "/" << n->colNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;

	return 0;

}
