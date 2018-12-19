int main()
{
  int array[10];
  int n;
  int c;
  int d;
  int swap;
 
  for (c = 0 ; c < n - 1; c += 1)
  {
    for (d = 0 ; d < n - c - 1; d += 1)
    {
      if (array[d] > array[d+ 1])
      {
        swap       = array[d];
        array[d]   = array[d+ 1];
        array[d+ 1] = swap;
      }
    }
  }
 
  return 0;
}
