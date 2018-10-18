#include "../src/symboltable.h"
// Will be in parser
int symbol_table_debug = 1;

// Sample Test of Symbol Table 

int main()
{

	SymbolTable s;
	//1 int j;
	s.insert("j",1, INT_TYPE);
	//2 void func();
	s.insert("func",2,VOID_TYPE);
	//3 int main()
	s.insert("main",3,INT_TYPE);
	//4 {
	s.pushEmptyBST();
	//5 float p = 1.44;
	s.insert("p",5,FLOAT_TYPE);
	//6 float k = -2.43;
	s.insert("k",6,FLOAT_TYPE);
	//7 int i = 0;
	s.insert("i",7,INT_TYPE);
	//8 int q = 1;
	s.insert("q",8,INT_TYPE);
	
	
	//9 char burrito = 'b';	
	s.insert("burrito",9,CHAR_TYPE);
	//10 char taco = 't';
	s.insert("taco",10,CHAR_TYPE);
	//11 char taco;
	s.insert("taco",11,CHAR_TYPE);
	//12 !!D	
	s.writeToFile("driverOut.txt");
	//13 int o = 44;
	s.insert("o",13,INT_TYPE);
	//14 if(i==4)
	int level;
	Node *n;
	n = s.searchAll("i",&level);
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line: " << n->lineNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//15 {
	s.pushEmptyBST();
	//16 		int j =2;
	s.insert("j",16,INT_TYPE);
	//17		!!D
	s.writeToFile("driverOut.txt");
	//18 		if(j == 2)
	n = s.searchAll("j",&level);
		if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line: " << n->lineNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//19 		{
	s.pushEmptyBST();
	//20			int k;
	s.insert("k",20,INT_TYPE);
	//21	  	!!D;
	s.writeToFile("driverOut.txt");
	//22 		}
	s.popBST();
	//23 }
	s.popBST();
	//24 if(z == 1) do something;
	n = s.searchAll("z",&level);
	if(n != NULL)
		std::cout << "Node found in level: " << level << ", on line: " << n->lineNumber << std::endl;
	else
		std::cout << "Node not found." << std::endl;
	//25 !!D
	s.writeToFile("driverOut.txt");

	return 0;

}
