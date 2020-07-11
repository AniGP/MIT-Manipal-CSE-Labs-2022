#include <stdio.h>
#include <stdlib.h>

#define UNDER '\0'

typedef struct Node
{
	char data;
	struct Node *next;
} NODE;

NODE* createNode ()
{
        NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->next = temp;
	temp->data = UNDER;
	return temp;
}

void insert (NODE *list, char item)
{
	NODE *temp = createNode();
	NODE *p;
	
	temp->data = item;
	temp->next = list;
	
	if (list->next == list)
		list->next = temp;
	
	else
	{
		p = list->next;
		
		while (p->next != list)
			p = p->next;
		p->next = temp;
	}
}

void display (NODE *list)
{
	NODE *temp = list->next;
	
	if (temp != list)
	{
		while (temp->next != list)
		{
			printf(" %c\t", temp->data);
			temp = temp->next;
		}
		printf(" %c", temp->data);
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
	char item;
	
	printf("Enter number of elements of list 1 : \n");
	scanf("%d", &n);
	
	printf("Enter list 1 elements in ascending order (if numbers, single digit only) : \n");
	for (i = 0; i < n; ++i)
	{
		scanf(" %c", &item);
		insert(list1, item);
	}
	
	printf("Enter number of elements of list 2 : \n");
	scanf("%d", &n);
	
	printf("Enter list 2 elements in ascending order (if numbers, single digit only) : \n");
	
	for (i = 0; i < n; ++i)
	{
		scanf(" %c", &item);
		insert(list2, item);
	}
	
	NODE *temp1 = list1->next;
	NODE *temp2 = list2->next;
	
	while (temp1 != list1 && temp2 != list2)
	{
		char c1 = temp1->data;
		char c2 = temp2->data;
		if (c1 > c2)
		{
			insert(newList, c2);
			temp2 = temp2->next;
		}
		else
		{
			insert(newList, c1);
			temp1 = temp1->next;
		}
	}
	while (temp1 != list1)
	{
		insert(newList, temp1->data);
		temp1 = temp1->next;
	}
	while (temp2 != list2)
	{
		insert(newList, temp2->data);
		temp2 = temp2->next;
	}
	
	printf("List 1 is :\n");
	display(list1);
	
	printf("List 2 is : \n");
	display(list2);
	
	printf("Merged list is : \n");
	display(newList);
}