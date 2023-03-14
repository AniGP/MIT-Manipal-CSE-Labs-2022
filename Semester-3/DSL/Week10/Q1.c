#include <stdio.h>
#include <stdlib.h>

typedef struct node * nodeptr;

typedef struct node
{
	nodeptr rlink, llink;
	int data;
}node;

nodeptr create(int x)
{
	nodeptr temp = malloc(sizeof(node));
	temp->data = x;
	temp->rlink = temp->llink = NULL;
	return temp;
}

void insertfront(nodeptr *n,int x)
{
	nodeptr newnode = create(x);
	nodeptr temp = malloc(sizeof(node));
	temp = *n;
	
	if(temp == NULL)
	{
		*n = newnode;
	}
	
	else
	{
		newnode->llink = *n;
		(*n)->rlink = newnode;
		*n = newnode;
	}
}

void insertback(nodeptr *n,int x)
{
	nodeptr newnode = create(x);
	nodeptr temp = malloc(sizeof(node));
	temp = *n;
	
	if(temp == NULL)
	{
		*n = newnode;
	}
	
	else
	{
		while(temp->llink)
		{
			temp = temp->llink;
		}
		
		temp->llink = newnode;
		newnode->rlink = temp;
	}
}

int deletefront(nodeptr *n)
{
	int x;
	
	if(*n == NULL)
	{
		printf("Underflow\n");
		return -9999;
	}
	
	else
	{
		x = (*n)->data;
		(*n) = (*n)->llink;
		(*n)->rlink = NULL;
	}
	
	return x;
}

int deleteback(nodeptr *n)
{
	int x;
	
	if(*n == NULL)
	{
		printf("Underflow\n");
		return -9999;
	}
	
	else if((*n)->llink == NULL)
	{
		x = (*n)->data;
	}
	
	else
	{
		nodeptr temp = (*n);
		while((temp->llink)->llink)
		{
			temp = temp->llink;
		}
		
		x = (temp->llink)->data;
		(temp->llink)->rlink = NULL;
		temp->llink = NULL;
	}
	return x;
}

void display(nodeptr *n)
{
	nodeptr temp;
	for(temp=*n;temp;temp=temp->llink)
	{
		printf("%d ",temp->data);
	}
	
	printf("\n");
}

int main()
{
	nodeptr *n;
	n = malloc(sizeof(node));
	
	printf("1.) Insert front 2.) Insert back 3.) Delete front 4.) Delete back 5.) Display 6.) Exit :\n");
	int ch,ele;
	scanf("%d",&ch);
	while(ch!=6)
	{
		switch(ch)
		{
			case 1:
			
			printf("Enter data : ");
			scanf("%d",&ele);
			insertfront(n,ele);
			break;
			
			case 2:
			
			printf("Enter data : ");
			scanf("%d",&ele);
			insertback(n,ele);
			break;
			
			case 3:
			
			printf("Deleted : %d\n",deletefront(n));
			break;
			
			case 4:
			
			printf("Deleted : %d\n",deleteback(n));
			break;
			
			case 5:
			
			display(n);
			break;
		}
		
		printf("Enter option : ");
		scanf("%d",&ch);
	}
}