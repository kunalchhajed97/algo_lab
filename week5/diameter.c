#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int item;
struct node* left;
struct node* right;
}Tree;

typedef enum{false,true}bool;

Tree* getNode()
{
    Tree* t=(Tree*)malloc(sizeof(Tree));
    if(t==NULL) printf("Insufficient Memory");
    else t->left=t->right=NULL;
    return t;
}
Tree* insertBinaryTree(Tree* h)
{
    int i;
    scanf("%d",&i);
    if(i!=-1)
    {
        h=getNode();
        h->item=i;
        printf("Enter left of %d:",i);
        h->left=insertBinaryTree(h->left);
        printf("Enter right of %d:",i);
        h->right=insertBinaryTree(h->right);
    }
    else return NULL;

    return h;
}
int diameter(Tree* root,int* max)
{
    if(root == NULL)
        return 0;
    else
    {
        int leftDepth = diameter(root->left,max);
        int rightDepth = diameter(root->right,max);  
        if(leftDepth+rightDepth+1 > *max)
            *max = leftDepth+rightDepth+1;
        if(leftDepth > rightDepth)
            return leftDepth+1;
        else
            return rightDepth+1;
    }
}

int main()
{
    Tree* h1=NULL;
    h1=insertBinaryTree(h1);
    int* max = (int*)malloc(sizeof(int));
    *max = 0;
    diameter(h1,max);
    printf("Diameter is: %d\n",*max);
    return 0;
}
