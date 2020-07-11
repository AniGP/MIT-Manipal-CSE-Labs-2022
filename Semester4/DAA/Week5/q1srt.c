#include <stdio.h>
#include <stdlib.h>

int queue[100], k_1 = 0, k = 0, arr[100][100], n, indegree[100];
void calc()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(arr[j][i] && i!=j)
			{
    			indegree[i]++;
			}
		}
	}
}

void initQueue()
{
	for(int i = 0; i<n; i++)
	{
    	queue[i] = -1;
	}
}

void dec(int v)
{
	for(int i = 0; i<n; i++)
	{
		if(arr[v][i])
		{
			indegree[i]--;
		}
	
		if(indegree[i] == 0)
		{
    		queue[k++] = i;
		}
	}
}

int queueEmpty()
{
	for(int i = 0; i<n; i++)
	{
		if(queue[i] != -1)
		{
    		return 0;
		}
	}

	return 1;
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
    		scanf("%d", &arr[i][j]);
		}
	}    
	
	initQueue();
	calc();
	
	for(int i = 0; i<n; i++)
	{
		if(indegree[i] == 0)
		{
    		queue[k++] = i;
		}
	}
	
	printf("The Topological Sort Order is : \n");
	
	while(!queueEmpty())
	{
		int vertex = queue[k_1++];
		printf("%d ", vertex);
		queue[k_1-1] = -1;
		dec(vertex);

		printf("%d ", vertex);
	}
	
	printf("\n");

	return 0;
}