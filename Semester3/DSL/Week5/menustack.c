#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int top = -1;
int stack[MAX];
void push();
void pop();
void display();

void push()
{
	int val;

	if(top == MAX-1)
	{
		printf("\nStack full.\n");
	}

	else
	{
		printf("Enter element to push : \n");
		scanf("%d",&val);
		top = top + 1;
		stack[top] = val;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("\nStack empty.\n");
	}

	else
	{
		printf("Deleted element is %d\n",stack[top]);
		top=top-1;
	}
}

void display()
{
	int i;
    
    if(top == -1)
	{
		printf("\nStack empty.\n");
	}

	else
	{
		printf("\nStack is...........\n");

		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}

int main()
{
	while(1)
	{
	   int ch;
	   printf("\nSTACK. Enter your choice : \n");
	   printf("\n1.) Push\n");
	   printf("\n2.) Pop\n");
	   printf("\n3.) Display\n");
	   printf("\n4.) Exit\n"); 
	   scanf("%d",&ch);

	   switch(ch)
	   {
	      case 1:
	      push();
	      break;

	      case 2:
	      pop();
	      break;

	      case 3:
	      display();
	      break;

	      case 4:
	      exit(0);

	      default:
	      printf("Enter a valid choice : \n");
	   }
	}

	return 0;
}

