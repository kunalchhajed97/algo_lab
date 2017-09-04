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
int nodes(Tree* root,int* opcount)
{
    if(root == NULL)
        return 0;
    else
    {
    	(*opcount)+=2;
        return nodes(root->left,opcount) + nodes(root->right,opcount) + 1;
    }
}

int main()
{
    Tree* h1=NULL;
    h1=insertBinaryTree(h1);
    int opcount = 0;
    int count = nodes(h1,&opcount);
    printf("Number of nodes are : %d\n",count);
    printf("Opcount: %d\n",opcount);
    return 0;
}
