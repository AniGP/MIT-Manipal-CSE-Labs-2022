#include <stdio.h>

int main()
{
	int n = 18, temp,opcount=0;
	int num[n];
	
	for(int i = n-1;i>=0;i--)
	{
		num[n-i-1] = i;
	}
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n-1-i;j++)
		{
			if(num[j+1] < num[j])
			{
				temp = num[j+1];
				num[j+1] = num[j];
				num[j] = temp;
			}
			
			opcount++;
		}
	}
	
	printf("%d",opcount);
}