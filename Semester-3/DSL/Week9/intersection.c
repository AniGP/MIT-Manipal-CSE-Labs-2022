#include <stdio.h>
#include <stdlib.h>

#define UNDER 0

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} NODE;


NODE* createNode ()
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = UNDER;
	return temp;
}

void insert (NODE *list, int item)
{
	NODE *temp = createNode();
	NODE *p;
	
	temp->data = item;
	
	if (list->next == NULL)
	{
		temp->prev = list;
		list->next = temp;
		list->data = item;
	}
	
	else
	{
		p = list->next;
		
		while (p->next != NULL)
		{
			p = p->next;
		}
		
		temp->prev = p;
		p->next = temp;
	}
}

int listContainsItem (NODE * node, int item)
{
	NODE *temp = node->next;
	while (temp != NULL) 
	{
		if (temp->data == item)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void display (NODE *list)
{
	NODE *temp = list->next;
	
	if (list->next != NULL) 
	{
		while (temp->next != NULL)
		{
			printf(" %d\t", temp->data);
			temp = temp->next;
		}
		printf(" %d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main ()
{
	
	NODE *list1 = createNode();
	NODE *list2 = createNode();
	NODE *newList = createNode();
	
	int i, n;
	int item;
	
	printf("Enter number of elements in list 1 : \n");
	scanf("%d", &n);
	
	printf("Enter elements of list 1: \n");
	
	for (i = 0; i < n; ++i)
	{
		scanf(" %d", &item);
		insert(list1, item);
	}
	
	printf("Enter number of elements in list 2 : \n");
	scanf("%d", &n);
	
	printf("Enter elements of list 2 : \n");
	
	for (i = 0; i < n; ++i)
	{
		scanf(" %d", &item);
		insert(list2, item);
	}
	
	NODE *temp = list1->next;
	
	while (temp != NULL)
	{
		char item = temp->data;
		if ((listContainsItem(list2, item)) == 1 && (listContainsItem(newList, item))==0)
		{
			insert(newList, item);
		}
		
		temp = temp->next;
	}
	
	printf("List 1 is : \n");
	display(list1);
	
	printf("List 2 is : \n");
	display(list2);
	
	printf("Intersection is : \n");
	display(newList);
}