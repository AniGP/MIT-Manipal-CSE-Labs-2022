#include <stdio.h>
#include <math.h>

int main()
{
	int sum=0,n;
	
	printf("Enter number of terms : ");
	scanf("%d",&n);
	
	printf("Enter numbers : ");
	int num[n];
	
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&num[i]);
		sum += num[i];
	}
	
	sum=sum/2;
	
	for(int i = 0;i<pow(2,n);i++)
	{
		int current_sum = 0;
		
		for(int j = 0;j<n;j++)
		{
			if(i&(1<<j))
			{
				current_sum+=num[j];
			}
		}
		
		if(current_sum == sum)
		{
			for(int j =0;j<n;j++)
			{
				if(i&(1<<j))
				{
					printf("%d",num[j]);
				}
			}
		}
		
		printf("////");
		for(int j = 0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				printf("%d",num[j]);
			}
		}
		printf("\n");
	}
}