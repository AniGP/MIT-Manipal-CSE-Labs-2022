#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *left, *right;
}NODE;

typedef struct
{
	NODE * arr[100];
	int top;
}STACK;

void push(STACK *s, NODE * n)
{
	if((s->top+1)<100)
		s->arr[++(s->top)]=n;
	else
		printf("Overload!\n");
}

NODE * pop (STACK *s)
{
	if(s->top >= 0)
		return s->arr[(s->top)--];
	else
		return NULL;
}

void inorder(NODE * root)
{
	if(root==NULL)
		return;
	
	inorder(root->left);
	printf("%c ",root->data );
	inorder(root->right);
}

int isOperator(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^': return 1;
		default : return 0;
	}
}

int main()
{
	char postfix[100];
	
	printf("Enter the postfix expression below : \n");
	scanf(" %[^\n]s",postfix);
	
	int i=0;
	STACK s;
	s.top=-1;
	NODE* n;
	NODE* op1;
	NODE* op2;
	
	for(;postfix[i]!='\0';i++)
	{
		n = (NODE*)malloc(sizeof(NODE));
		n->data=postfix[i];
		if(!isOperator(postfix[i]))
		{
			n->left=n->right=NULL;
			push(&s,n);
		}
		
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			n->left=op1;
			n->right=op2;
			push(&s,n);
		}
	}
	
	printf("The resultant tree is:\n");
	
	NODE * root=pop(&s);
	
	inorder(root);
	
	printf("\n");
	
	printf("Root node data is: %c\n",root->data);
	
	return 0;
}
