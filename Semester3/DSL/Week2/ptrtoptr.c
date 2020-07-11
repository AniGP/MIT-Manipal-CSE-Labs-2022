#include<stdio.h>
int main()
{
	int a;
	int *p;
	int **q;

	a=58;
	p=&a;
	q=&p;

	printf("%d",a);
	printf("%d",*p);
	printf("%d",**q);
		
    return 0;
}