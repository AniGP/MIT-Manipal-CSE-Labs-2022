#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
	int arr[MAX];
	int front,rear;
}Que;

int isEmpty(Que *q)
{
	if(q->rear == -1)
	{
		return 1;
	}
	
	return 0;
}

int isFull(Que *q)
{
	if((q->rear+1)%MAX == q->front)
	{
		return 1;
	}
	
	return 0;
}

void insert(Que *q, int x)
{
	if(isEmpty(q))
	{
		q->rear = q->front =0;
		q->arr[0] = x;
	}
	else
	{
		for(int i=0;i<=q->rear;i++)
		{
			if(x<q->arr[i])
			{
				int j;
				for(j=q->rear;j>=i;j--)
				{
					q->arr[j+1]=q->arr[j];
				}
				q->arr[i]=x;
				q->rear++;
				break;
			}
		}
		if(x>q->arr[q->rear]) q->arr[++q->rear]=x;
	}
}

int delete(Que *q)
{
	if(isEmpty(q))
	{
		printf("Underflow\n");
		return -9999;
	}
	int x = q->arr[q->front];
	if(q->rear == q->front) q->front = q->rear = -1;
	else q->front = (q->front +1)%MAX;
	return x;
}

void display(Que q)
{
	if(isEmpty(&q))
	{
		printf("Queue is empty\n");
		return;
	}
	for(int temp = (q.front)%MAX; temp!=q.rear; temp = (temp+1)%MAX)
	{
		printf("%d ",q.arr[temp]);
	}
	
	printf("%d\n", q.arr[q.rear]);
}

int main()
{
	Que q;
	q.rear = q.front =-1;
	int ch,x;
	printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
	do
	{
		scanf("%d",&ch);
		
		if(ch==1)
		{
			printf("Enter element : ");
			scanf("%d",&x);
			insert(&q,x);
		}
		
		else if(ch==2)
		{
			x = delete(&q);
			
			if(x!=-9999)
			{
				printf("Popped : %d\n",x);
			}
		}
		
		else if(ch==3)
		{
			display(q);
		}
	}while(ch!=4);
}