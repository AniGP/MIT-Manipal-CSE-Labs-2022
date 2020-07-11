#include <stdio.h>
#include <stdlib.h>

typedef struct Node * Nodeptr;

typedef struct Node
{
	int data;
	Nodeptr rchild, lchild;
}Node;

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

void inorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		inorder((ptr)->lchild);
		printf("%d ",(ptr)->data);
		inorder((ptr)->rchild);
	}
}

void postorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		postorder((ptr)->lchild);
		postorder((ptr)->rchild);
		printf("%d ",(ptr)->data);
	}
}

void preorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",(ptr)->data);
		preorder((ptr)->lchild);
		preorder((ptr)->rchild);
	}
}

int main()
{
	int ch;
	Nodeptr root;
	root = NULL;
	printf("1.) Insert 2.) Traverse 3.) Exit\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			root = create();
			break;

			case 2:
			
			printf("Inorder : ");
			inorder(root);
			
			printf("\nPostorder : ");
			postorder(root);
			
			printf("\nPreorder : ");
			preorder(root);
			
			printf("\n");
			
			break;

			case 3: 
			exit(0);
		}
	}
	return 0;
}