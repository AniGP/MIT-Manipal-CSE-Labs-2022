#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num,i;
	printf("Enter number of elements : ");
	scanf("%d",&num);
	
	int arr[100];
	
	printf("Enter elements of array : \n");
	
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int *plast;
	plast = arr+num-1;
	
	int *pmid;
	pmid = arr+(int)(num/2);
	
	int *p;
	
	for(p=arr;p<=pmid; p++,plast--)
	{
		int temp = *p;
		*p = *plast;
		*plast = temp;
	}
	
	plast = arr+num-1;
	
	for(p=arr;p<=plast;p++)
	{
		printf("%d ", *p);
	}

	return 0;
}