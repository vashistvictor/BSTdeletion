#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node * create(int value)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void preorderdisplay(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorderdisplay(root->left);
        preorderdisplay(root->right);
    }
}

void insert(struct node *root,int value)
{
    struct node *prev,*new;
    new = create(value);
    while(root!=NULL)
    {
        prev = root; //to keep track of previous element of root node
        if(root->data > value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(prev->data > value)
    {
        prev->left = new;
    }
    else if(prev->data < value)
    {
        prev->right = new;
    }
}

struct node *inorderpost(struct node *root)
{
    root = root->right;
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node * deletenode(struct node *root,int item)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data > item)
    {
        root->left = deletenode(root->left,item);
    }
    else if(root->data < item)
    {
        root->right = deletenode(root->right,item);
    }
    else
    {
        struct node *ipost = inorderpost(root);
        root->data = ipost->data;
        root->right = deletenode(root->right,ipost->data); //if it would have been inorderpredecessor, we would use root->left
    }
    return root;
}

int main()
{
    int n,value,item;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    scanf("%d",&value); //for 1st value
    root = create(value);
    for(int i=1;i<n;i++) //loop for the remaining values
    {
        scanf("%d",&value);
        insert(root,value);
    }
    preorderdisplay(root); //preorder traversal display 
    scanf("%d",&item);
    deletenode(root,item);
    preorderdisplay(root);
    return 0;
}