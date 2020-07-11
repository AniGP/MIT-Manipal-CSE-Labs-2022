#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct stack
{
	char data[MAX];
	int top;
}stack;

void init(stack *s)
{
	s->top=-1;
}

void push(stack *s, char x)
{
	(s->top)++;
	s->data[s->top]=x;
}

char pop(stack *s)
{
	char x = s->data[s->top];
	(s->top)--;
	return x;
}

int isChar(char x)
{
	if((x>='a' && x<='z') || (x>='A' && x<='Z'))
	{
		return 1;
	} 
		
	return 0;
}

int evaluate(char x)
{
	if(x=='+')
	{
		return 1;
	}
	
	if(x=='-')
	{
		return 1;
	}
	
	if(x=='*')
	{
		return 2;
	}
	
	if(x=='/')
	{
		return 2;
	}
	
	if(x=='%')
	{
		return 2;
	}
	
	if(x==')')
	{
		return 0;
	}
}

int main()
{
	stack s;
	init(&s);
	
	printf("Enter infix expression : ");
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
	
	y[j]='(';
	j++;
	y[j]='\0';
	
	printf("Reversed infix exp w left paranthesis : ");
	printf("%s\n",y);

	push(&s,')');
	int a,b;
	
	printf("Reversed prefix exp : ");
	
	for(i=0,j=0; y[i]!='\0';i++)
	{
		if(isChar(y[i]))
		{
			printf("%c",y[i]);
			x[j]=y[i];
			j++;
		}
		else
		{
			if(y[i]=='(')
			{
				while(s.data[s.top]!=')')
				{
					x[j]=pop(&s);
					printf("%c",x[j]);
					j++;
				}
				char waste=pop(&s);
			}
			else
			{
				a = evaluate(y[i]);
				b = evaluate(s.data[s.top]);
				if(a>=b)
				{
					push(&s,y[i]);
				}
				else
				{
					while(a<b && a!=0)
					{
						x[j]=pop(&s);
						printf("%c",x[j]);
						j++;
						b=evaluate(s.data[s.top]);
					}
					push(&s,y[i]);
				}
			}
		}
	}
	
	printf("\nPrefix exp : ");
	for(i=j-1;i>=0;i--)
	{
		printf("%c",x[i]);
	}
	
	printf("\n");
	
	return 0;
}
