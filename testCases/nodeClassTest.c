// int kb(int a, int gk, int ddy){
// 	;
// 	a = 1;
// 	return a;
// }

// int main(float a,int b)
// {

// 	// int j[2][4];
	
// 	int k = 2;
	
// 	float j = 4;
// 	char p = k + 2 * j;
// 	// !!D
// 	// for (b = 0; b < 3; ++b)
// 	// {
// 	// 	break;
// 	// }
// 	j = kb(b,k,k);
// 	if (k == 2.2)
// 	{
// 		j = 3;
// 	}

// 	j = p + k;
// 	{
// 		// int k;
// 		k = j;
// 	}
// 	// //!!D
// 	// int i;
// 	// // !!D
// 	// // 
// 	// j[0][1] = 1 + 2 + 3 + 1;
// 	// j[1]=1*i;
// 	// !!D
// 	return 1.1;
// }
// int blue(int k, int p, int g){
// 	int j;
// 	j = k+ p + g;
// 	return j + 1;
// }
int main()
{
	// float a = 1.0;
	// int a = 1;
	// int b = 2;
	// int c;
	// c = a + b;
	// writeInt(c);
	// // c = blue(a,b,c);
	// return c;
	// 
	int a[2][2];
	int b[2][2];
	int i;
	int j;
	char p;
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 2;
	a[1][1] = 2;
	
	b[0][0] = 1;
	b[0][1] = 1;
	b[1][0] = 2;
	b[1][1] = 2;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			//writeInt(a[i][j]);			
			p = 32;
			writeChar(p);
		}
		p = 10;
		writeChar(p);
	}
	p = 10;
	writeChar(p);
	p = 10;
	writeChar(p);
	p = 10;
	writeChar(p);
	
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			a[i][j] = a[i][j] + b[i][j];
		}
	}
	
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			//writeInt(a[i][j]);			
			p = 32;
			writeChar(p);
		}
		p = 10;
		writeChar(p);
	}
	return 1;
}

// void readChar(float a){
// 	return a;
// }
