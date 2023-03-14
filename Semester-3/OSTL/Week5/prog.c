#include <stdio.h>
int g1(int x);
int g2(int x);
int main()
{
	int x=5;
	int y=-7;
	int a=g2(x+8);
	int b=g2(y);
	printf("a=%d, b=%d\n",a,b);
	return 0;
}