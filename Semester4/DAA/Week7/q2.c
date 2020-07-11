#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left,*right;
	int data;
	int balance;
};

typedef struct node Node;

int max(int a,int b)
{
	return a>b? a: b;
}

int height(Node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

void balance_factor(Node *root,Node *st[],int *top)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		
		return;
	}
	balance_factor(root->left,st,top);
	int bf = height(root->left)-height(root->right);
	root->balance=bf;
	if(bf>1 || bf<-1)
		st[++(*top)]=root;
	balance_factor(root->right,st,top);
}

Node *leftrotate(Node *root)
{
	Node *z=root;
	Node *y=root->right;
	z->right=y->left;
	y->left=z;
	return y;
}

Node *rightrotate(Node *root)
{
	Node *z=root;
	Node *y=root->left;
	z->left=y->right;
	y->right=z;
	return y;
}

Node *avl(Node *root,int key)
{
	Node *st[10];
	int top=-1;
	balance_factor(root,st,&top);
	if(top==-1)
		return root;
	//search the node
	//printf("hi\n");
	Node *snode;
	if(top==1)
		snode=st[top-1];
	else
		snode=st[top];
	Node *nd=root;
	//printf("hi\n");
	//left case
	//printf("%d ",snode->data);
	if(snode->balance>1 && key<nd->left->data)
		root=rightrotate(snode);
	//right case
	else if(snode->balance<-1 && key>nd->right->data)
		root=leftrotate(snode);
	//left right case
	else if(snode->balance>1 && key>nd->left->data)
	{
		snode->left =leftrotate(snode->left);
		root=rightrotate(snode);
	}
	//right left case
	else if(snode->balance<1 && key<nd->right->data)
	{
		snode->right =rightrotate(snode->right);
		root=leftrotate(snode);
	}
	return root;
}

Node *newNode(int data,Node *root)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	node->balance=0;
	if(root==NULL)
	{
		return node;
	}

	Node *nd=root;
	Node *parent;
	while(nd)
	{
		parent=nd;
		if(nd->data<data)
			nd=nd->right;
		else
			nd=nd->left;
	}
	if(parent->data<data)
		parent->right=node;
	else
		parent->left=node;
	root=avl(root,data);
	return root;
}

void print(Node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	print(root->left);
	print(root->right);
}

int main()
{
	int n;
	Node *root=NULL;
	printf("Enter the Number of Nodes of The AVL Tree : \n");
	scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++)
	{
		printf("Enter the %d Node in the AVL Tree \n",(i+1));
		scanf("%d",&x);
		root=newNode(x,root);
	}
	printf("The AVL Tree Inserted has the Preorder Traversal given by : \n");
	print(root);
	printf("\n");
}