#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int size1;
int f1;
int r1;
int arr[100]; 
}Q;

void push(Q *q,int str)
{
	if((q->r1+1)%(q->size1)!=(q->f1))
	{
		q->r1=(q->r1+1)%(q->size1);
		q->arr[q->r1]=str;
	}
	
	else
		printf("Overflow.\n");
}

int pop(Q *q)
{
	if(q->f1!=q->r1)
	{
		q->f1=(q->f1+1)%(q->size1);
		return q->arr[q->f1];
	}
	
	else
		printf("Underflow..\n");
	return '\0';
}

int empty(Q *q)
{
	if(q->r1==q->f1)
		return 1;
	
	return 0;
}

void rev(Q *q)
{
	if(empty(q))
		return;
	
	int x=pop(q);
	rev(q);
	push(q,x);
}

void disp(Q *q)
{
	int n=(q->f1+1)%(q->size1);
	int e=(q->r1+1)%(q->size1);
	
	while(n!=e)
	{
		printf("%d\n",q->arr[n]);
		n=(n+1)%(q->size1);
	}
}

int main()
{
	Q q;
	q.r1=-1;
	q.f1=-1;
	q.size1=100;
	
	push(&q,1);
	push(&q,2);
	push(&q,3);
	disp(&q);
	
	printf("Calling rev\n");
	rev(&q);
	disp(&q);
}
