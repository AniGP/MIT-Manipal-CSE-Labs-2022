#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * nodeptr;

typedef struct node
{
	nodeptr rlink, llink;
	int data;
}node;

nodeptr create()
{
	nodeptr temp = malloc(sizeof(node));
	return temp;
}

void insert(nodeptr *n,int x)
{
	if(*n == NULL)
	{
		*n = create();
		(*n)->data = x;
		(*n)->llink = (*n)->rlink = *n;
	}
	else
	{
		nodeptr temp = *n;
		
		while(temp->llink != *n)
		{
			temp = temp->llink;
		}
		
		nodeptr newnode = create();
		newnode->data = x;
		temp->llink = newnode;
		newnode->rlink = temp;
		newnode->llink = *n;
		(*n)->rlink = newnode;
	}
}

nodeptr readlong()
{
	nodeptr head;
	char str[100];
	int i;
	printf("Enter string representing long int : ");
	scanf("%s",str);
	nodeptr n = create();
	n->llink = n->rlink = n;
	for(i=0;str[i];i++)
	{
		insert(&n,str[i]-'0');
	}
	return n;
}

nodeptr addlong(nodeptr A, nodeptr B)
{
	int digit, sum, carry=0;
	nodeptr head,r,R,a,b;
	a=A->rlink;
	b=B->rlink;
	head = create();
	head->llink = head->rlink = head;
	while(a!=A && b!=B)
	{
		sum = a->data + b->data +carry;
		digit = sum%10;
		carry = sum/10;
		insert(&head,digit);
		a=a->rlink;
		b=b->rlink;
	}
	if(a!=A)
	{
		r=a;
		R=A;
	}
	else
	{
		r=b;
		R=B;
	}
	while(r!=R)
	{
		sum = r->data + carry;
		digit = sum%10;
		carry = sum/10;
		insert(&head,digit);
		r = r->rlink;
	}
	if(carry) insert(&head,carry);
	return head;
}

void display(nodeptr *n)
{
	for(nodeptr temp=(*n)->rlink;temp!=*n;temp=temp->rlink)
		printf("%d ",temp->data);
	printf("\n");
}

int main()
{
	nodeptr A,B,sum;
	A = readlong();
	B = readlong();
	sum = addlong(A,B);
	display(&sum);
	return 0;
}
