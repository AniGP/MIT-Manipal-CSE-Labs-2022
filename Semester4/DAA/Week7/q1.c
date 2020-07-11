#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

int max(int a, int b)
{
    return (a>b)?a:b;
}

Node* getNode(Node* t, int data)
{
	if(t == NULL)
	{
    	t = (Node*)malloc(sizeof(Node));
    	t->data = data;
    	t->right = t->left = NULL;
    }
    else if(data > t->data)
    	t->right = getNode(t->right, data);
    else if(data < t->data)
    	t->left = getNode(t->left, data);
    else
    {
    	printf("Duplicate Node Inserted!\n");
    	exit(0);
    }
    return t;
}

int getHeight(Node* root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + max(getHeight(root->left), getHeight(root->right));
}

void balfact(Node* root)
{
    if(root != NULL)
    {
        balfact(root->left);
        printf("Balance Factor for %d is : %d\n", root->data, (getHeight(root->left) - getHeight(root->right)));
        balfact(root->right);
    }
}

int main()
{
	int n, x, ch, i;
	Node *root;
	root = NULL;
	while(1)
	{
		printf("Enter: \n1 to Insert\n2 to Exit and Find Balance Factor of Each Node\n");
		printf("Enter Choice : \n");
		scanf("%d", &ch);
		if(ch == 1)
		{
			printf("Enter the Node (Do NOT Enter Duplicates!) : \n");
			scanf("%d", &x);
			root = getNode(root, x);
		}
		else if(ch == 2)
		{
			printf("Printing Balance Factors....\n");
			balfact(root);
			break;
		}
		else
		{
			printf("WRONG CHOICE! Please Try Again!!\n");
			exit(0);
		}
	}

	return 0;
}