#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct stack
{
	int data[MAX];
	int top;
}stack;

void init(stack *s)
{
	s->top=-1;
}

void push(stack *s, int x)
{
	(s->top)++;
	s->data[s->top]=x;
}

int pop(stack *s)
{
	int x = s->data[s->top];
	(s->top)--;
	return x;
}

int evaluate(char x, int op1, int op2)
{
	if(x=='+')
	{
		return op1+op2;
	}
	
	if(x=='-')
	{
		return op2-op1;
	}
	
	if(x=='*')
	{
		return op1*op2;
	}
	
	if(x=='/')
	{
		return op2/op1;
	}
	
	if(x=='%')
	{
		return op2%op1;
	}
}

int isDigit(char x)
{
	if(x>='0' && x<='9')
	{
		return 1;
	}
	
	return 0;
}

int main()
{
	stack s;
	init(&s);
	
	printf("Enter an expression with single digit operands & operators : ");
	char x[MAX];
	scanf("%s",x);
	char y[MAX];
	int i,c,j;
	
	for(i=0; x[i]!='\0';i++)
	{
		c++;
	}
	
	for(j=0,i=c-1;i>=0;i--,j++)
	{
		y[j]=x[i];
	}
	y[j]='\0';
	
	printf("Reversed prefix exp : ");
	printf("%s\n",y);

	int op1,op2,val;
	for(i=0; y[i]!='\0'; i++)
	{
		if(isDigit(y[i]))
		{
			push(&s,y[i]-'0');
		}
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			val = evaluate(y[i],op1,op2);
			push(&s,val);
		}
	}
	printf("Value of prefix exp = %d\n",pop(&s));
	return 0;
}