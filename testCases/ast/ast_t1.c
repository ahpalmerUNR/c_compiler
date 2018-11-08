/**
 * @file ast_t1.c
 * @author Nathan Yocum
 * @brief File to demonstrate semantic type checking in AST
 */

// Expected: Warning that longs aren't supported
long long int a;

// Expected: Error that two primary types declared.
int float b;

// Expected: Warn of implict cast from long to long int
long c;

// Expected: Error
signed unsigned d;

// Expected: Error
long short e;

// Expected: Error
long float f;

long double g;

// !!D
