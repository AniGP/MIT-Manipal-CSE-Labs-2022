#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char arr[100][100];
	int top;
}Stack;

void push(Stack *s,char ch[])
{
	if((s->top+1)<100)
	{
	 	strcpy(s->arr[++(s->top)],ch);
	}
	
	else
	{
		printf("Overload!\n");
	}
}

char * pop(Stack *s)
{
	if(s->top>=0)
	{
		return s->arr[(s->top)--];
	}
	
	printf("Underload!\n");
	return NULL;
}

int isOperator(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '$': return 1;
		default : return 0;
	}
}

void strrev(char *arr)
{
	int i=0,n=0;
	char temp;
	for(i=0;arr[i]!='\0';i++)
	{
		n++;
	}
	
	for(i=0;i<n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
	}
}

int main(int argc, char const *argv[])
{
	char prefix[100];
	Stack s;
	s.top=-1;
	
	printf("Enter the prefix expression below : \n");
	scanf(" %[^\n]s",prefix);
	
	strrev(prefix);
	
	printf("The reversed prefix is : %s\n",prefix );
	char ch;
	int i=0;
	
	while((ch=prefix[i++])!='\0')
	{
		if(!isOperator(ch))
		{
			char temp []= {ch,'\0'};
			push(&s,temp);
		}
		else
		{
			char *op1=pop(&s);
			char *op2=pop(&s);
			char result[]={ch,'\0'};
			strcat(result,op2);
			strcat(result,op1);
			// strrev(result);
			printf("%s\n",result );
			push(&s,result);
		}
	}
	char *temp2= pop(&s);
	strrev(temp2);
	printf("The postfix expression is : %s\n",temp2);
	return 0;
}
