#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25

typedef struct stack
{
	int data[MAX];
	int top;
}stack;

int empty(stack *s)
{
	if(s->top == -1)
	{
	   return 1;
	}

	return 0;
}

int full(stack *s)
{
	if(s->top == MAX-1)
	{
	   return 1;
	}

	return 0;
}

void push(stack *s, int x)
{
	s->top = s->top+1;
	s->data[s->top] = x;
}

int pop(stack *s)
{
	int x;
	x = s->data[s->top];
	s->top = s->top - 1;
	return x;

}

int main()
{
	
	stack s;
	int num;
	s.top = -1;
	
	while(1)
	{
		printf("\nEnter a Number : \n");
	    scanf("%d",&num);

	    while(num!=0)
	    {
	      if(!full(&s))
	      {
	        push(&s,num%2);
	        num=num/2;
	      }

	      else
	      {
	        printf("Stack Overflow.");
	        exit(0);
	      }
	    }

	   while(!empty(&s))
	   {
	      num = pop(&s);
	      printf("%d\n",num);
	   }
	}

	return 0;
}

	
	