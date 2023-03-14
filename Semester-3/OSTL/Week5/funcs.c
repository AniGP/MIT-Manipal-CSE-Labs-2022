#include <stdio.h>
int g1(int x)
{
	printf("Inside g1(x=%d)\n",x);
	if(x>0)
	{
		return 5;
	}
	return -11;
}

int g2(int x)
{
	printf("Inside g2(x=%d)\n",x);
	int y=g1(x-10);
	printf("y=%d\n",y);
	return y;
}