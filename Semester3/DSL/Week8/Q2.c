#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
#define MAX_STR 10

typedef struct
{
	char arr[MAX_SIZE][MAX_STR];
	int front,rear;
}DQ_STR;

void init(DQ_STR *s)
{
	s->front = s->rear = -1;
}

int isEmpty(DQ_STR *s)
{
	if(s->rear == -1)
	{
		return 1;
	}
	
	return 0;
}

int isFull(DQ_STR *s)
{
	if((s->rear+1)%MAX_SIZE == s->front)
	{
		return 1;
	}
	return 0;
}

void insertright(DQ_STR *s, char x[])
{
	int i;
	if(isEmpty(s))
	{
		s->rear = s->front =0;
		
		for(i=0;x[i]!='\0';i++)
		{
			s->arr[s->rear][i] = x[i];
		}
		
		s->arr[s->rear][i] = '\0';
	}
	
	else
	{
		s->rear = (s->rear+1)%MAX_SIZE;
		
		for(i=0;x[i]!='\0';i++)
		{
			s->arr[s->rear][i] = x[i];
		}
		
		s->arr[s->rear][i] = '\0';
	}
}

void insertleft(DQ_STR *s, char x[])
{
	int i;
	if(isEmpty(s))
	{
		s->rear = s->front =0;
		
		for(i=0;x[i]!='\0';i++)
		{
			s->arr[s->front][i] = x[i];
		}
		
		s->arr[s->front][i] = '\0';
	}
	else
	{
		s->front = (s->front-1+MAX_SIZE)%MAX_SIZE;;
		
		for(i=0;x[i]!='\0';i++)
		{
			s->arr[s->front][i] = x[i];
		}
		
		s->arr[s->front][i] = '\0';
	}
}

char* deleteleft(DQ_STR *s)
{
	char *str;
	str = s->arr[s->front];
	if(s->rear == s->front)
	{
		init(s);
	}
	
	else
	{
		s->front = (s->front+1)%MAX_SIZE;
	}
	return str;
}

void displaydq(DQ_STR *s)
{
	if(isEmpty(s))
	{
		printf("Queue is empty\n");
		return;
	}
	for(int temp = (s->front)%MAX_SIZE; temp!=(s->rear); temp=(temp+1)%MAX_SIZE)
	{
		printf("%s\n",s->arr[temp]);
	}
	printf("%s\n",s->arr[s->rear]);
}

int main()
{
	DQ_STR s;
	init(&s);
	int ch;
	char str[MAX_STR];
	printf("1.) Insert left\n 2.) Insert right\n 3.) Delete left\n 4.) Display\n 5.) Exit\n");
	
	do
	{
		scanf("%d",&ch);
		
		if(ch==1)
		{
			if(isFull(&s))
			{
				printf("Overflow\n");
			}
			
			else
			{
				printf("Enter string : ");
				scanf("%s",str);
				insertleft(&s,str);
			}
		}
		
		else if(ch==2)
		{
			if(isFull(&s))
			{
				printf("Overflow\n");
			}
			
			else
			{
				printf("Enter string : ");
				scanf(" %s",str);
				insertright(&s,str);
			}
		}
		else if(ch==3)
		{
			if(!isEmpty(&s))
			{
				char *pop = deleteleft(&s);
				printf("Popped : %s\n",pop);
			}
			
			else
			{
				printf("Underflow\n");
			}
		}
		else if(ch==4)
		{
			displaydq(&s);
		}
	}while(ch!=5);
}