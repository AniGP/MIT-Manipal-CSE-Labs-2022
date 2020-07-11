#include<stdio.h>
#include<stdlib.h>
#define size 7

struct node
{
  int data;
  struct node *next;
};

struct node *chain[size];

void init()
{
  int i;
    
  for(i = 0; i < size; i++)
    chain[i] = NULL;
}

void insert(int value)
{
  struct node *newNode = malloc(sizeof(struct node));
    
  newNode->data = value;
  newNode->next = NULL;
    
  int key = value % size;
    
  if(chain[key] == NULL)
    chain[key] = newNode;
    
  else
  {
    struct node *temp = chain[key];
    
    while(temp->next)
    {
      temp = temp->next;
    }

    
    temp->next = newNode;
  }
}

void print()
{
  int i;
  
  for(i = 0; i < size; i++)
  {
    struct node *temp = chain[i];
    
    printf("chain[%d]-->",i);
    
    while(temp)
    {
      printf("%d -->",temp->data);
      temp = temp->next;
    }
    
    printf("NULL\n");
  }
}

int main()
{
  init();
  insert(7);
  insert(0);
  insert(3);
  insert(10);
  insert(4);
  insert(5);
  print();

  return 0;
}