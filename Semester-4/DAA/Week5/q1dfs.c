#include <stdio.h>
#include <stdlib.h>

int a[50][50], visit[50], stack[100],n,t=0;

void dfs(int v)
{
	visit[v]=1;

	for(int i=0;i<n;i++)
	{
		if(a[v][i] && !visit[i])
		{
			dfs(i);
		}
	}

	stack[t++]=v;
}

void printStack()
{
	for(int i=n-1;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}

	printf("\n");
}

int main()
{
	printf("Enter the Number of Vertices : \n");
	scanf("%d", &n);
	
	printf("Enter the Adjacency Matrix : \n");
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
    		scanf("%d", &a[i][j]);
		}
	}

	for(int i = 0; i<n; i++)
	{
		if(!visit[i])
		{
    		dfs(i);
		}
	}

	printf("The Topological Sort Order is :\n");
	printStack();
	

	return 0;
}