// Vector of types for argument expression list, warning on implicit casting
int main()
{
  float k;
	char l;
	int i;
	double j;

	i = 5.0;
	j = 1;
	i = j;
	i = 1 + 5.0 + 'c';
	l = 'c';
	l = 1;
}
