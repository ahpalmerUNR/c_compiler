/**
 * @file st_recursion.c
 * @author Nathan Yocum
 * @brief Test that recursion works properly in symbol table
 */

int factorial(int m) {
	int k;
	//writeInt(m);
	;
	if ( m <= 1) {
		return 1;
	} else {
		k = m;
		m = m - 1;
		m = k * factorial(m);
		//writeInt(m);
		return m ;
	}
	// !!D
}

int main()
{
	int a = 5;
	a = factorial(a);
	writeInt(a);
	return a;
}
