#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
  int capacity;
  int top;
  char* arr;
  int si;
};

struct Stack* createStack(unsigned capacity)
{
  struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity=capacity;
  stack->top=-1;
  stack->si=0;
  stack->arr=(char*)malloc(stack->capacity*sizeof(char));
  return stack;
}

int isFull(struct Stack* stack)
{
  return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack* stack)
{
  return stack->top==-1;
}

void push(struct Stack* stack, char ch)
{
  if(isFull(stack))
  {
    return;
  }
  stack->arr[++stack->top]=ch;
  stack->si++;
  return;
}

char pop(struct Stack* stack)
{
  if(isEmpty(stack))
  {
    return '$';
  }
  stack->si--;
  return stack->arr[stack->top--];
}

char peep(struct Stack* stack)
{
  if(isEmpty(stack))
  {
    return '$';
  }
  return stack->arr[stack->top];
}

int main()
{
  int n,flag;
  char st[20],ch;
  
  printf("Enter the size of the stack : \n");
  scanf("%d",&n);
  
  struct Stack* stack=createStack(n);
  
  printf("Enter String : ");
  scanf(" %s",st);
  
  int j=strlen(st);
  int i=0;
  
  while (i<(j/2))
  {
    push(stack,st[i]);
    i++;
  }
  
  if (j%2!=0)
  {
    i++;
  }
  
  flag=1;
  
  while (i<j)
  {
    if (st[i]!=pop(stack))
    {
      flag=0;
      break;
    }
    i++;
  }
  
  if (flag==0)
  {
    printf("Its not a Palindrome.\n");
  }
  
  else
  {
    printf("Its a Palindrome.\n");
  }
  
  return 0;
}
