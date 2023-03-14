#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
	int arr[MAX];
	int left, right;
}Q;

void insert(Q *q,int num)
{
	if(q->right==-1 && q->left==-1)
	{
		q->right=q->left=0;
		q->arr[q->right]=num;
	}

	if((q->right+1)%MAX != q->left)
	{
		q->right=(q->right+1)%MAX;
	  	q->arr[q->right]=num;
	}
	
	else
	{
		printf("Overflow !\n");
	}
}

int delete(Q *q)
{
	if(q->left==-1)
	{
		return -9999;
	}
	
	else if(q->left==q->right)
	{
		int x = q->arr[q->left];
		q->left=q->right=-1;
		return x;
	}
	
	else
	{
		int x = q->arr[q->left];
		q->left=(q->left+1)%MAX;
		return x;
	}
}

void display(Q q)
{
	int i=q.left;
	if(q.left!=-1)
	{
		for(;i!=q.right;i=(i+1)%MAX)
		printf("%d ",q.arr[i] );
		printf("%d\n",q.arr[i] );
	}
	else
	{
		printf("Is empty!\n");
	} 
		
}

int chkElement(Q q, int elem)
{
	int val;
	while(1)
	{
		val=delete(&q);
		if(val==elem)
		{
			return 1;
		}
		
		else if(val == -9999)
		{
			return 0;
		}
	}
}

int main()
{
	Q q;
	q.left=q.right=-1;
	
	printf("Enter %d elememts for the queue below :\n", MAX);
	int val;
	
	for(int i=0;i<MAX;i++)
	{
		scanf("%d",&val);
		insert(&q,val);
	}
	
	printf("Enter the element to search for : ");
	int elem;
	scanf("%d",&elem);
	
	int result=chkElement(q,elem);
	
	if(result==1)
	{
		printf("Element found in q : ");
	}
	
	else
	{
		printf("Element not found in q : ");
	}
	
	display(q);
	return 0;
}
