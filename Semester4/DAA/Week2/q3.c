#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int sieve(int n, int *brr)
{
	int  arr[n+1];
	for(int i=0;i<=n;i++)
		arr[i] = i;

	for(int i=2;i<=(int)(floor(sqrt(n)));i++)
	{
		if(arr[i]!=0)
		{
			int j=i*i;
			while(j<=n)
			{
				arr[j]=0;
				j = j+i;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		brr[i]=0;
	}

	int j=0;
	
	for(int i=2;i<=n;i++)
	{
		if(arr[i]!=0)
		{
			brr[j]=arr[i];
			j++;
		}
	}
	return (j-1);
}

int gcd(int m, int n)
{
	int opcount = 0, ans=0;

	int *arr = calloc(m,sizeof(int));
	int *brr = calloc(n,sizeof(int));

	int len1 = sieve(m,arr);
	int len2 = sieve(n,brr);

	int a[len1+1], b[len2+1];
	
	for(int i=0;i<=len1;i++)
	{
		a[i]=0;
	}
	
	for(int i=0;i<=len2;i++)
	{
		b[i]=0;
	}
	
	int x=m, y=n;

	int i=0;
	
	while(x>0 && i<len1)
	{
		x = m;
		int count=0;
		while(x>0)
		{
			if(x%arr[i] !=0)
			{
				a[i] = count;
				i++;
				break;
			}
			else
			{
				x = x/arr[i];
				count++;
			}
		}
	}
	
	for(int i=0;i<=len1;i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\n");
	
	for(int i=0;i<=len1;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n");

	i=0;
	
	while(y>0 && i<len2)
	{
		y = n;
		int count=0;
		
		while(y>0)
		{
			if(y%arr[i] !=0)
			{
				b[i] = count;
				i++;
				break;
			}
			else
			{
				y = y/arr[i];
				count++;
			}
		}
	}
	
	for(int i=0;i<=len2;i++)
	{
		printf("%d ",brr[i]);
	}
	
	printf("\n");
	
	for(int i=0;i<=len2;i++)
	{
		printf("%d ",b[i]);
	}
	
	printf("\n");

	printf("Opcount = %d\n",opcount);
	return ans;
}

int main()
{
	printf("Enter m and n :\n");
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	int ans = gcd(m,n);
	printf("GCD of %d & %d is : %d\n",m,n,ans);

	return 0;
}