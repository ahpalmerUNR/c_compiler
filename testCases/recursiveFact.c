int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    int n;
    n = 5;
    factorial(n);
    return 0;
}
