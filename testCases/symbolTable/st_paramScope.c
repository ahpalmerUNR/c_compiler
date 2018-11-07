/**
 * @file st_paramScope.c
 * @author Nathan Yocum
 * @brief Test that parameters are being scoped properly
 */
int a;
void foo(int);
void foo(int a) {
	// Should throw a shadow warning.
	!!D
}