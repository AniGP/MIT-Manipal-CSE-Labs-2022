#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *a;
  int top;
}STACK;

void push(STACK *s, int ele)
{
  *((s->a)+(s->top))=ele;
  (s->top)++;
}

void pop(STACK *s)
{
  (s->top)--;
  //return *((s->a)+(s->top));
}

void display(STACK s)
{
  for(int i=0;i<(s.top);i++)
  {
    printf("%d ",*(s.a+i));
  }
  printf("\n");
}

int main()
{
  int n,k,i,e;
  
  printf("Enter the length of array : ");
  scanf("%d",&n);
  
  STACK s;
  s.a=(int*)calloc(n,sizeof(int));
  s.top=0;
  
  printf("Enter number of elements to be deleted : ");
  scanf("%d",&k);
  
  for(i=0;i<n;i++)
  {
    printf("Enter element : ");
    scanf("%d",&e);
    
    if(s.top==0)
    {
      push(&s,e);
      display(s);
    }
    
    else
    {
      while((*(s.a + (s.top-1)) < e) && k>0 && s.top>0)
      {
        pop(&s);
        display(s);
        k--;
      }
      
      push(&s,e);
      display(s);
    }
  }
  
  display(s);
  return 0;
}
