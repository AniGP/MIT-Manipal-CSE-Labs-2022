#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	
	printf("Enter Size : ")
	scanf("%d",&n);
	
	int *arr=(int*)calloc(n,sizeof(int));
	
	printf("Enter the Array Elements : \n");
	
	for(int i=0;i<n;i++)
	{
       scanf("%d",(arr+i));
	}
	
	int* l=arr+n;
	
	printf("Printing the Array forwards\n");
	
	for(;arr<l;arr++)
	{
		printf("%d  ",*arr);
	}
	
	l=l-n;
	
	printf("Printing the Array backwards\n");
	arr--;
	
	for(;arr>=l;arr--)
	{
		printf("%d  ",*arr);
	}


}