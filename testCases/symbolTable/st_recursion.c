/**
 * @file st_recursion.c
 * @author Nathan Yocum
 * @brief Test that recursion works properly in symbol table
 */

int factorial(int n);

int factorial(int m) {
	m = 5;
	if (m <= 1) {
		return 1;
	} else {
		return m * factorial(m - 1);
	}
	!!D
}
