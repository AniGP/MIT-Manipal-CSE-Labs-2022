#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

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
		printf("Insert to left or right of %d?\n", temp->data);
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
		else{
			if(temp->right==NULL)
			{
				temp->right=node;
				break;
			}
			else{
				temp=temp->right;
			}
		}
	}	
}

void preorder(struct Node* root)
{
	if(!root)
	{
		return;
	}
	
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}

void inorder(struct Node* root)
{
	if(!root)
	{
		return;
	}
	
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	return;
}

void postorder(struct Node* root)
{
	if(!root)
	{
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	return;
}

int main()
{
	struct Node* root=NULL;
	int n;
	
	printf("Enter no. of nodes : ");
	scanf("%d",&n);
	
	int k;
	struct Node* temp=root;
	
	for(int i=0;i<n;i++)
	{	
		printf("Give the integer to go in the tree : \n");
		scanf("%d",&k);
		insert(&root,k);
	}
	
	printf("Preorder : ");
	preorder(root);
	
	printf("\nInorder : ");
	inorder(root);
	
	printf("\nPostorder : ");
	postorder(root);
	
	printf("\n");
	return 0;
}