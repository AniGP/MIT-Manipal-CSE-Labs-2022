#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int flag = 0;
	
	printf("Enter Number of Vertices : \n");
	scanf("%d",&n);
	
	int adj[n][n];
	
	printf("Enter Adjacency Matrix : \n");
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	
	printf("Adjacency Matrix is : \n");
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		
		printf("\n");
	}
	
	printf("Adjacency List is : \n");
	
	for(int i=0;i<n;i++)
	{
		printf("%c--\n",(97+i));
		
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]==1)
			{
				printf("%c is adjacent to %c\n",(97+i),(97+j));
				printf("%c ,\n",(97+j));
			}
		}
		
		printf("\n");
	}

	return 0;
}