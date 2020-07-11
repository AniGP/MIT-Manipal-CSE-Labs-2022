#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node * Nodeptr;

typedef struct Node
{
	int data;
	Nodeptr rchild, lchild;
}Node;

typedef struct
{
	Nodeptr arr[MAX];
	int front,rear;
}CQ;

void init2(CQ *s)
{
	s->front = s->rear = -1;
}

void insertcq(CQ *s, Nodeptr x)
{
	int temp = (s->rear + 1)%MAX;
	if((s->rear == MAX-1 && s->front == -1) || s->front == temp)
	{
		printf("Queue overflow\n");
	}
	else
	{
		s->rear = temp;
		s->arr[s->rear] = x;
	}
}

Nodeptr deletecq(CQ *s)
{
	if(s->front == s->rear)
	{
		init2(s);
		return NULL;
	}
	s->front = (s->front + 1)%MAX;
	
	return s->arr[s->front];
}

void levelOrder(Nodeptr root)
{
    CQ s;
		init2(&s);
		Nodeptr temp = root;

    while (temp)
    {
        printf("%d ", temp->data);
		
		if (temp->lchild)
			insertcq(&s, temp->lchild);

		if (temp->rchild)
			insertcq(&s, temp->rchild);

		temp = deletecq(&s);
    }
}



typedef struct stack
{
	Nodeptr arr[MAX];
	int top;
}stack;

void init1(stack *s)
{
	s->top=-1;
}

void push(stack *s, Nodeptr x)
{
	(s->top)++;
	s->arr[s->top]=x;
}

Nodeptr pop(stack *s)
{
	Nodeptr x = s->arr[s->top];
	(s->top)--;
	return x;
}

struct stck
{
	Nodeptr n;
	int flag;
}s[50];

Nodeptr create()
{
	int ele;
	
	printf("Enter the element to insert (-1 for no data) : ");
	scanf("%d",&ele);
	
	if(ele==-1) 
		return NULL;
	
	Nodeptr temp;
	
	temp = malloc(sizeof(Node));
	temp->data = ele;
	
	printf("Enter left child of %d : \n",ele);
	temp->lchild = create();
	
	printf("Enter right child of %d : \n",ele);
	temp->rchild = create();
	
	return temp;
}

void iterpost(Nodeptr root)
{
	if(root==NULL)
	{
		printf("Empty tree!\n");
		return;
	}
	
	int top=-1;
	
	while(1)
	{
		while(root!=NULL)
		{
			top++;
			s[top].n=root;
			s[top].flag=1;
			root=root->lchild;
		}
		
		while(s[top].flag==0)
		{
			root=s[top].n;
			top--;
			printf("%d ",root->data );
			if(top==-1)
				return;
		}
		
		root=s[top].n;
		s[top].flag=0;
		root=root->rchild;
	}
}

void iterin(Nodeptr ptr)
{
	stack s;
	init1(&s);
	
	while(ptr!=NULL)
	{
		while(ptr!=NULL)
		{
			if(ptr->rchild!=NULL)
				push(&s,ptr->rchild);
			
			push(&s,ptr);
			ptr = ptr->lchild;
		}
		
		ptr = pop(&s);
		
		while(s.top!=-1 && ptr->rchild==NULL)
		{
			printf("%d ",ptr->data);
			ptr=pop(&s);
		}
		
		printf("%d ",ptr->data);
		ptr = (s.top!=-1)?pop(&s):NULL;
	}
}

void iterpre(Nodeptr ptr)
{
	stack s;
	init1(&s);
	push(&s,ptr);
	
	while(s.top!=-1)
	{
		ptr = pop(&s);
		printf("%d ",ptr->data);

		if(ptr->rchild!=NULL)
			push(&s,ptr->rchild);
		if(ptr->lchild!=NULL)
			push(&s,ptr->lchild);
	}
}

int main()
{
	int ch;
	Nodeptr root = NULL;
	root = create();
	
	printf("\nInorder : ");
	iterin(root);
	
	printf("\nPostorder : ");
	iterpost(root);
	
	printf("\nPreorder : ");
	iterpre(root);
	
	printf("\nLevel order : ");
	levelOrder(root);
	
	printf("\n");
	return 0;
}
