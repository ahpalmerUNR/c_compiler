/*
* @Author: ahpalmerUNR
* @Date:   2018-10-27 19:16:07
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-10-27 20:32:51
*/
int maxSize;
void sendInt(int);
void sendFloat(float);
void sendChar(char);


int main()
{
	int i;
	const float num = 1.1;
	char niceChar;
	int p =0;
	int k[4];
	
	maxSize = 100;
	
	k[0] = 25;
	k[1] = 2*k[0];
	k[2] = k[1] + k[0];
	k[3] = 5*k[0]-k[0];
	
	niceChar = 'a';
	
	sendInt(i);
	
	for (p = 5; p < maxSize; ++p)
	{
		sendInt(p);
	}
	
	if (maxSize == 100)
	{
		sendFloat(num);
	}
	
	while(p>1){
		p-=1;
	}
	
	sendInt(k[3]);
	
	sendChar(niceChar);
	
	return 0;
}

void sendInt(int a){
	//stuff
}

void sendFloat(float taa){
	//stuff
}

void sendChar(char ca){
	//stuff
}
