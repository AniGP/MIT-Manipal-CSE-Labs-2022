#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
	int arr[MAX];
	int top;
}Stack;

int isEmpty(Stack *s)
{
	if(s->top==-1) return 1;
	return 0;
}

void push(Stack *s,int ch)
{
	if((s->top+1)<MAX)
	{
		s->arr[++(s->top)]=ch;
	}
	
	else
	{
		printf("Overflow!\n");
	}
}

int pop(Stack *s)
{
	if(isEmpty(s))
	{
		return -9999;
	}
	return s->arr[(s->top)--];
}

int main()
{
	Stack s1, s2;
	s1.top=s2.top=-1;
	int ch,n;
	int i=0;
	
	printf("1. Push\n2. Pop\n3. Exit\n");
	scanf("%d",&ch);
	
	while(ch==1 || ch==2)
	{
		if(ch==1)
		{
			printf("Enter element : ");
			scanf("%d",&n);
			push(&s1,n);
		}
		
		else if(ch==2)
		{
			if(isEmpty(&s2))
			{
				while(!isEmpty(&s1))
				{
					push(&s2,pop(&s1));
				}
				n=pop(&s2);
				if(n!=-9999) printf("Popped : %d\n",n);
				else printf("Underflow\n");
			}
			
			else
			{
				n=pop(&s2);
				if(n!=-9999) printf("Popped : %d\n",n);
				else printf("Underflow\n");
			}
		}
		scanf("%d",&ch);
	}
	return 0;
}
