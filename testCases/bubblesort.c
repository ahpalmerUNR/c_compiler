int main()
{
  int array[10];
  int n= 10 ;
  int c;
  int d;
  int swap;
  
  array[0] = 10;
  array[1] = 9;
  array[2] = 8;
  array[3] = 7;
  array[4] = 6;
  array[5] = 5;
  array[6] = 13;
  array[7] = 1;
  array[8] = 125;
  array[9] = 0;
  
  d = array[0];
  writeInt(d);
  
  for (c = 0; c < n; c += 1)
  {
    d = array[c];
    writeInt(d);
  }
 
  // for (c = 0 ; c < n - 1; c += 1)
  // {
  //   for (d = 0 ; d < n - c - 1; d += 1)
  //   {
  //     if (array[d] > array[d+ 1])
  //     {
  //       swap       = array[d];
  //       array[d]   = array[d+ 1];
  //       array[d+ 1] = swap;
  //     }
  //   }
  // }
  for (c = 0; c < n; c += 1)
  {
    d = array[c];
    writeInt(d);
  }
 
  return 0;
}
