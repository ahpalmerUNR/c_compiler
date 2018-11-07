// Vector of types for argument expression list, warning on implicit casting
int main()
{
	int i;
	i = 1 + 5.0;
	i = 5 + 'c';
	i = 'c' + 'c';
	i++;
	i = (char) i; 
}
