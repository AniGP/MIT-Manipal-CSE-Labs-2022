#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
   
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL)
        return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 
  
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL)
        return root; 
    
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  	
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        
        struct node* temp = minValueNode(root->right);
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
   
int main() 
{ 
    struct node *root = NULL; 
    
    printf("Enter root element : ");
    int k;
    scanf("%d",&k);
    
    root = insert(root,k);
    
    while(k!=-1)
    {
    	printf("Enter no. to insert (-1 to exit) : ");
    	scanf("%d",&k);
    	
        if(k!=-1)
    		insert(root,k);
    }
    
    printf("Inorder expression of BST : ");
    inorder(root); 

    printf("\nEnter no. of elements to be deleted : ");
    int n;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
    	printf("\nEnter no. to be deleted : ");
    	scanf("%d",&k); 
    	
        root = deleteNode(root, 20); 
    	
        printf("Inorder traversal of the modified tree \n"); 
    	inorder(root); 
    }
    
    printf("\n");
    return 0; 
} 