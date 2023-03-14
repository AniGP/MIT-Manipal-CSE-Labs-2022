#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
#define MAX_STR 10

typedef struct
{
	char **arr;
	int front,rear;
}CQ_STR;

void init(CQ_STR *s)
{
	s->front = s->rear = -1;
	s->arr = malloc(sizeof(char*) * MAX_SIZE);
	for(int i=0;i<MAX_SIZE;i++)
	{
		s->arr[i] = malloc(sizeof(char) * MAX_STR);
	}
}

void insertcq(CQ_STR *s, char x[])
{
	int temp = (s->rear + 1)%MAX_SIZE;
	if((s->rear == MAX_SIZE-1 && s->front == -1) || s->front == temp)
	{
		printf("Queue overflow\n");
	}
	else
	{
		s->rear = temp;
		for(int i=0;x[i]!='\0';i++)
		{
			*(*(s->arr + s->rear)+i) = x[i];
		}
	}
}

char* deletecq(CQ_STR *s)
{
	char *ch;
	char c;
	char carr[MAX_STR]="";
	ch=&c;
	if(s->front == s->rear)
	{
		printf("Queue underflow\n");
		return ch; 
	}
	s->front = (s->front + 1)%MAX_SIZE;

	for(int i=0;*(*(s->arr + s->front)+i)!='\0';i++)
	{
		carr[i]=*(*(s->arr + s->front)+i);
		*(*(s->arr + s->front)+i) = ' ';
	}
	ch=carr;
	return ch;
}

void displaycq(CQ_STR s)
{
	for(int temp = (s.front+1)%MAX_SIZE; temp!=(s.rear); temp=(temp+1)%MAX_SIZE)
	{
		printf("%s\n",(*(s.arr + temp)));
	}
	printf("%s\n",(*(s.arr + s.rear)));
}

int main()
{
	CQ_STR s;
	
	init(&s);
	
	insertcq(&s,"A");
	
	insertcq(&s,"B");
	
	insertcq(&s,"Hi");
	
	insertcq(&s,"Hello");
	
	insertcq(&s,"Semester !");
	
	printf("Queue Values : \n");
	
	displaycq(s);
	
	insertcq(&s,"I got supplies !");
	
	printf("Deleted : %s\n",deletecq(&s));
	
	printf("Deleted : %s\n",deletecq(&s));
	
	displaycq(s);
	
	insertcq(&s,"Fall back to safe zone !");
	
	printf("After inserting :\n");
	
	displaycq(s);
}