#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node * Nodeptr;

typedef struct Node
{
	int data;
	Nodeptr right, left;
}Node;

void insert(struct Node** root,int data)
{
	struct Node* node=malloc(sizeof(struct Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	
	if (*root==NULL)
	{
		*root=node;
		return;
	}
	
	struct Node* temp;
	char str[10];
	
	for(temp=*root;temp!=NULL;)
	{
		printf("Insert to left or right of %d? ", temp->data);
		scanf("%s",str);
		
		if (strcmp(str,"left")==0)
		{
			if (temp->left==NULL)
			{
				temp->left=node;
				break;
			}
			else{
				temp=temp->left;
			}
		}
		
		else
		{
			if(temp->right==NULL)
			{
				temp->right=node;
				break;
			}
			
			else
			{
				temp=temp->right;
			}
		}
	}
}

void inorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		inorder((ptr)->left);
		printf("%d ",(ptr)->data);
		inorder((ptr)->right);
	}
}

void postorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		postorder((ptr)->left);
		postorder((ptr)->right);
		printf("%d ",(ptr)->data);
	}
}

void preorder(Nodeptr ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",(ptr)->data);
		preorder((ptr)->left);
		preorder((ptr)->right);
	}
}

int main()
{
	struct Node* root=NULL;
	int n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	
	int k;
	struct Node* temp=root;
	
	for(int i=0;i<n;i++)
	{
		printf("Give the integer to go in the tree: ");
		scanf("%d",&k);
		insert(&root,k);
	}
	
	printf("\nPreorder is: ");
	preorder(root);
	
	printf("\nInorder is: ");
	inorder(root);
	
	printf("\nPostorder is: ");
	postorder(root);
	
	printf("\n");
	return 0;
}
