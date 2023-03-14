#include <stdio.h>

int i=0;

void sumOfArray(int arr[], int n)
{
	int sum=0;
	for(i=0; i<n; i++)
	{
	  sum=sum+arr[i];
	}
	printf("Sum = %d \n", sum);
}

void linearsearch(int arr[], int num, int n)
{
	int flag=0;
	for(i=0; i<num; i++)
	{
	  if(arr[i]==n)
	  {
	    printf("Number found.\n");
	    flag=1;
	    break;
	  }
	}
	if(flag==0)
	  printf("Number not found.\n");
}

void productofmatrices(int a, int b, int c, int d)
{
	int m1[3][3];
	int m2[3][3];
	int ans[3][3];
	int sum=0;
	int j=0,k=0;

	printf("Matrix m1 : \n");
	
	for(i=0; i<a; i++)
	{
	  for(j=0; j<b; j++)
	  {
	    scanf("%d", &m1[i][j]);
	  }
	}
	
	printf("Matrix m2 : \n");
	for(i=0; i<c; i++)
	{
	  for(j=0; j<d; j++)
	  {
	    scanf("%d", &m2[i][j]);
	  }
	}

	for(k=0; k<a; k++)
	{
	  for(i=0; i<d; i++)
	  {
	    for(j=0; j<b; j++)
	    {
	    	sum = sum + m1[k][j]*m2[j][i];
	    }
	    ans[k][i] = sum;
	    sum=0;
	  }
	}
	
	printf("Product of the Matrices are : \n");
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<d;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}

void secondlargest(int arr[], int n)
{
	int l1=arr[0];
	int p=0, l2=0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>l1) 
		{
			l1=arr[i];
			p=i;
		}
	}
	if (p==0) 
	{
		l2=arr[1];
	}
	
	else
	{
		l2=arr[0];
	}
	
	for(i=0;i<n;i++)
	{
		if(arr[i]<l1 && arr[i]>l2)
		{

			l2=arr[i];
		}
	}
	printf("2nd largest number  = %d \n", l2);
}

int main()
{
	int n=0,num=0,ele;
	int r1=0,r2=0,c1=0,c2=0;
	printf("1. Find sum of numbers in a 1D array.\n");
	printf("2. Linear Search.\n");
	printf("3. Product of 2 Matrices.\n");
	printf("4. Find 2nd largest in a list of numbers.\n");
	
	printf("Enter your choice : ");
	scanf("%d", &n);
	
	switch(n)
	{
		case 1:
		
		printf("Enter number of elements : ");
		scanf("%d", &num);
		
		int arr[100];
		
		printf("Enter elements of array :\n");
		for(i=0;i<num;i++)
		{
			scanf("%d", &arr[i]);
		}
		
		sumOfArray(arr,num);
		break;

		case 2:
		
		printf("Enter number of elements : ");
		scanf("%d", &num);
		
		int a[100];
		printf("Enter elements of array :\n");
		
		for(i=0;i<num;i++)
		{
			scanf("%d", &a[i]);
		}
		printf("Enter no. to be searched : ");
		scanf("%d", &ele);
		
		linearsearch(a,num,r);
		break;

		case 3:
		
		printf("Enter r1 : ");
		scanf("%d",&r1);
		
		printf("Enter c1 : ");
		scanf("%d",&c1);
		
		printf("Enter r2 : ");
		scanf("%d",&r2);
		
		printf("Enter c2 : ");
		scanf("%d",&c2);
		
		if(c1==r2)
		{
			productofmatrices(a,b,c,d);
		}
		
		else 
		{
			printf("Invalid input.");
		}
		
		break;

		case 4:
		
		printf("Enter number of elements : ");
		scanf("%d", &num);
		
		int b[100];
		
		printf("Enter elements of array :\n");
		for(i=0;i<num;i++)
		{
			scanf("%d", &b[i]);
		}
		
		secondlargest(b, num);
		break;

		default:
		
		printf("Invalid input.");
		break;
	}

	return 0;
}