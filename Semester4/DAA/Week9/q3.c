#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 7

int h[TABLE_SIZE]={NULL};

void insert()
{
  int key, index, i, flag=0, hkey;
  printf("Enter a Value to Insert into the Hash Table : \n");
  scanf("%d", &key);
  hkey = key % TABLE_SIZE;
  
  for(i = 0 ; i < TABLE_SIZE ; i++)
  {
    index = (hkey + i) % TABLE_SIZE;
    if(h[index] == NULL)
    {
      h[index] = key;
      break;
    }
  }
  
  if(i == TABLE_SIZE)
    printf("The Element cannot be Inserted\n");
}

void search()
{
  int key, index, i, flag=0, hkey;
  
  printf("Enter the Search Element : \n");
  scanf("%d", &key);
  
  hkey = key % TABLE_SIZE;
  
  for(i = 0 ; i < TABLE_SIZE ; i++)
  {
    index = (hkey + i) % TABLE_SIZE;
    
    if(h[index] == key)
    {
      printf("Value is Found at Index %d\n", index);
      break;
    }
  }
    
  if(i == TABLE_SIZE)
    printf("Value is not Found\n");
}

void display()
{
  int i;
  
  printf("Elements in the Hash Table are : ");
  
  for(i = 0 ; i < TABLE_SIZE ; i++)
    printf("\nat Index %d  Value =  %d",i,h[i]);

}

int main()
{
  int opt, i;
  
  while(1)
  {
    printf("\nEnter 1. Insert 2. Display 3. Search 4.Exit : \n");
    scanf("%d", &opt);
    
    switch(opt)
    {
      case 1:
        insert();
        break;
      case 2:
        display();
        break;
      case 3:
        search();
        break;
      case 4: 
        exit(0);
    }
  }

  return 0;
}