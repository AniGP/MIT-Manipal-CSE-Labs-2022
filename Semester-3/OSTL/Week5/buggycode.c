#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	
	do
	{
		printf("Enter a +ve no. : ");
		scanf("%d",&num);
	}while(num<0);
	
	int f=1,i;
	
	for(i=1;i<=num;i++)
	{
		f=f*i;
	}
	
	printf("%d! = %d\n",num,f);
	return 0;
}