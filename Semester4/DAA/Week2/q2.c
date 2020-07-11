#include <stdio.h>
#include <stdlib.h>

int gcd_middle(int m , int n)
{
	if(m > n)
	{
		gcd_middle(n , m);
	}
	
	int fact = 2;
	int gcd = 1;
	int k = m;
	int count = 0;
	
	for(fact = 2; fact <= k; fact++)
	{
		count++;

		while(((m % fact) == 0) && ((n % fact) == 0))
		{	
			count++;
			gcd = gcd * fact;
			n = n / fact;
			m = m / fact;
			
			if (m == 0 || n == 0)
			{
				printf("%d\t",count);
				return gcd;
			}
		}
	}
	
	printf("%d\t",count);
	
	return gcd;
}

int main()
{
	int m , n;
	
	printf("Enter the First Number : \n");
	scanf("%d", &m);
	
	printf("Enter the Second Number : \n");
	scanf("%d", &n);

	int i;
	
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d\n",gcd_middle(m,n));
	}
	
	printf("The GCD of '%d' and '%d' = '%d' \n",m,n,gcd_middle(m,n));
	
	
}