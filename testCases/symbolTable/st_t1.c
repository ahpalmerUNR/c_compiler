/**
 * @file st_t1.c
 * @author Nathan Yocum
 * @brief Tests for the symbol table insertion and lookup
 */

// Declare a variable in global scope
int i;

// Expected: Throw an error for redeclaration
int i;

// Prototype a function
int foo(int);

// Define the function - lookup that the function was defined and not declare function
// Expected: Throw a warning for shadowing (int i should be in global scope and function scope)
int foo(int i) {
	// Expected: Throw a warning for shadowing (maybe two warnings since it's being shadowed twice)
	int i;
	!!D
	/**
	 * Expected Dump:
	 * Level: 0 Key: foo Line: 14 Column: 5 Type: 0 Params: int
	 * Level: 0 Key: i Line: 8 Column: 5 Type: 0
	 * Level: 1 Key: i Line 18 Column: X Type: 0
	 * Level: 2 Key: i Line: 20 Column: 12 Type: 0
	 */
}
