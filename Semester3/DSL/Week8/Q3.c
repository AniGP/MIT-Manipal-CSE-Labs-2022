#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
	char arr[MAX];
	int front,rear;
}DQ_STR;

int isEmpty(DQ_STR *s)
{
	if(s->rear == -1) 
		return 1;
	
	return 0;
}

int isFull(DQ_STR *s)
{
	if((s->rear+1)%MAX == s->front)
		return 1;
	
	return 0;
}

void insert(DQ_STR *s, char x)
{
	if(isFull(s))
		printf("Overflow\n");
	
	else if(isEmpty(s))
	{
		s->front=s->rear=0;
		s->arr[0]=x;
	}
	else
		s->arr[++s->rear]=x;
}

char deleteright(DQ_STR *s)
{
	char c = s->arr[s->rear--];
	return c;
}
char deleteleft(DQ_STR *s)
{
	char c = s->arr[s->front++];
	return c;
}

void display(DQ_STR s)
{
	for(int temp=s.front; temp<=s.rear; temp++)
	{
		printf("%c",s.arr[temp]);
	}
	
	printf("\n");
}

int main()
{
	DQ_STR s;
	s.front = s.rear =-1;
	
	printf("Enter a string : ");
	char arr[MAX];
	scanf("%s",arr);
	
	for(int i=0; arr[i]!='\0'; i++)
		insert(&s,arr[i]);
	
	display(s);
	
	int flag=1;
	
	for(;s.front!=s.rear && !isEmpty(&s);)
	{
		char c1=deleteleft(&s);
		char c2=deleteright(&s);
		
		if(c1!=c2)
		{
			flag=0; break;
		}
	}
	
	if(flag==0)
		printf("Not palindrome.\n");
	
	else if(flag==1) 
		printf("Palindrome.\n");
	
	return 0;
}