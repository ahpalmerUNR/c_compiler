// Vector of types for argument expression list, warning on implicit casting
int q(int l, int f, int t)
{

}
int main()
{
	int i;
	int j[5] = {1,2,3,4,5};
	i = 1 + 5.0;
	i = 5 + 'c';
	i = 'c' + 'c';
	i++;
	i = (char) i; 
}
