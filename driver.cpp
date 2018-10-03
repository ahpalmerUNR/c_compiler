#include"symboltable.cpp"

int main()
{
	SymbolTable s;
	// Test insert
	s.insert("1",1);
	s.insert("2",2);
	s.insert("3",3);
	// Should be a conflict
	s.insert("1",4);
	// Add a new level
	s.pushEmptyBST(); 

	// Insert into second level BST
	s.insert("4",5);
	//Should be shadowed
	s.insert("2",6);
	// Pop a level
	s.popBST();
	// Push a new level
	s.pushEmptyBST();
	// Shouldnt produce a problem
	s.insert("4",7);
	data dat;
	dat.lineNumber = 8;
	s.insert("5",dat);
	// Should return pointer to node on line 7
	data *d = s.searchTop("4");
	if(d != NULL)
		cout << "This line number should be 7: " << d->lineNumber << endl;

	int loc;
	// Search all should return location 0 for bottom of stack and line 2 
	d = s.searchAll("2",&loc);
	if(d != NULL)
 		cout << "This line number should be 2 for level 0. Line: " << d->lineNumber << ". Level: " << loc << endl ;

	// Write the stack of BST to the file
	s.writeToFile();


}
