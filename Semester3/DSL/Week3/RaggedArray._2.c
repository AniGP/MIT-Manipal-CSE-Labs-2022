#include <stdio.h>
#include <stdlib.h>
void **copy(int **);

void **copy(int **table)
{
	int r,c,i,j;

for(i=0;i < *(table+r)-1;i++)
{
	for(j=0; j < *(table+c);j++)
	{
		*(table+i) = *(table(i+j-1));
	}

	if((*(table+i)+j) == 0)
	{
		(*(table+i)+j) = NULL;
		printf("\nnull\n.")
	}
}
}


int main()
{
	int r;
	printf("Enter no. of rows : \n");
	scanf("%d",&r);
	int **table=(int**)calloc(r+1,sizeof(int*));
	*(table+r)=NULL;
	int i;
	//int **ans;
	for(i=0;i<r;i++)
	{
		printf("Enter the no. of columns : \n");
		int c;
		scanf("%d",&c);
		*(table+i)=(int*)calloc(c+1,sizeof(int));
		**(table+i)=c;
		printf("Enter the Elements \n");
		for(int j=1;j<=c;j++)
		{
			scanf("%d",(*(table+i)+j));
		}
	}
	printf("Printing the elements of the original ragged array\n");
	for(i=0;i<r;i++)
	{
		for(int j=1;j<=table[i][0];j++)
		{
			printf("%d  ",table[i][j]);
		}
		
		printf("\n");
	}

	 copy(table);

	printf("Printing the elements of the ragged array after\n");
	for(i=0;i<r;i++)
	{
		for(int j=1;j<=table[i][0];j++)
		{
			printf("%d  ",table[i][j]);
		}
		
		printf("\n");
	}

	return 0;
}


