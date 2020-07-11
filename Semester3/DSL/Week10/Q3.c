#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef struct Node 
{
	char * data;
	struct Node * rlink;
	struct Node * llink;
} node;

typedef node * nodePtr;

nodePtr createNode () 
{
	nodePtr temp = (nodePtr)malloc(sizeof(node));
	temp->data = (char *)malloc(SIZE * sizeof(char));
	temp->llink = temp;
	temp->rlink = temp;
	return temp;
}

void insert (nodePtr head, char *val) 
{
	nodePtr temp = createNode();
	nodePtr p;
	
	temp->data = val;
	temp->rlink = head;
	
	head->llink = temp;
	
	if (head->rlink == head) 
	{
		temp->llink = head;
		head->rlink = temp;
	}
	
	else 
	{
		p = head->rlink;
		
		while (p->rlink != head)
		{
			p = p->rlink;
		}
		
		temp->llink = p;
		p->rlink = temp;
	}
}

void inputList (nodePtr head) 
{
	int i, n;
	
	printf("\n\tEnter number of terms in the head: ");
	scanf("%d", &n);
	
	printf("\n\tEnter the head: ");
	
	for (i = 0; i < n; ++i) 
	{
		char *item = (char *)malloc(SIZE * sizeof(char));
		scanf(" %s", item);
		insert(head, item);
	}
}

nodePtr createAndInputList () 
{
	nodePtr li = createNode();
	inputList(li);
	return li;
}

void reverseList2 (nodePtr head) 
{
	
	nodePtr slow = head->rlink;
	nodePtr fast = head->rlink;
	
	while (fast != head) 
	{
		fast = fast->rlink;
		
		if (fast != head) 
		{
			slow = slow->rlink;
			fast = fast->rlink;
		}
	}
	
	nodePtr temp1 = head->rlink;
	nodePtr temp2 = head->llink;
	
	while (temp1 != slow) 
	{
		
		char * swap = temp1->data;
		temp1->data = temp2->data;
		temp2->data = swap;
		
		temp1 = temp1->rlink;
		temp2 = temp2->llink;
	}
}

void displayList (nodePtr head) 
{
	nodePtr temp = head->rlink;
	
	while (temp->rlink != head) 
	{
		printf("%s -> ", temp->data);
		temp = temp->rlink;
	}
	printf("%s", temp->data);
}

int main () 
{
	
	nodePtr head = createAndInputList();
	
	printf("\n\t     Initially: ");
	displayList(head);
	
	reverseList2(head);
	
	printf("\n\tAfter Reversal: ");
	displayList(head);
	
	printf("\n\n");
	return 0;
}