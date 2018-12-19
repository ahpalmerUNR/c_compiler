int main()
{
  int array[10];
  int n= 10 ;
  int c=1;
  int d=2;
  char k = 20;
  int swap;
  char message[5];
  
  message[0] = 68;
  message[1] = 79;
  message[2] = 78;
  message[3] = 69;
  message[4] = 33;
  
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

  k = 32;
  for (c = 0; c < n; c = c + 1)
  {
    d = array[c];
    writeInt(d);
    writeChar(k);
  }
  k=10;
  writeChar(k);
 
  for (c = 0 ; c < n - 1; c = c + 1)
  {
    for (d = 0 ; d < n - c - 1; d = d + 1)
    {
      if (array[d] >= array[d+ 1])
      {
        
        swap       = array[d];
        // writeInt(swap);
        array[d]   = array[d+ 1];
        array[d+ 1] = swap;
      }
      else{
        for (swap = 0; swap < 5; swap += 1)
        {
          k = message[swap];
          writeChar(k);
        }
      }
    }
  }
  k=10;
   writeChar(k);
  k=32;
  for (c = 0; c < n; c = c + 1)
  {
    d = array[c];
    writeInt(d);
    writeChar(k);
  }
 
  return 0;
}
