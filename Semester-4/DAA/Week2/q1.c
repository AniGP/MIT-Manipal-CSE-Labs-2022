#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	int opcount = 0, t=0;
	if(m==0 && n==0)
	{
		t = 0;
	}
	else if(m==0 && n!=0) 
	{
		t = n;
		opcount++;
	}
	else if(m!=0 && n==0) 
	{
		t = m;
		opcount++;
	}
	else
	{
		t = (m<n?m:n);
		while(1)
		{
			opcount++;
			if(m%t==0 && n%t==0)
				break;
			else
				t--;
		}
	}
	printf("Opcount = %d\n",opcount);
	return t;
}

int main()
{
	printf("Enter m and n :\n");
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	int ans = gcd(m,n);
	
	if(ans==0)
	{
		printf("GCD of %d & %d is undefined\n",m,n);
	}
	
	else
	{
		printf("GCD of %d & %d = %d\n",m,n,ans);
	}
	return 0;
}