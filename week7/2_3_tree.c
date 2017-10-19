#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key1,key2,keyCount;
    struct node *left,*mid,*right,*parent;
}Tree;


Tree* getNode(int item)
{
    Tree* t=(Tree*)malloc(sizeof(Tree));
    if(t==NULL) printf("Insufficient Memory");
    else
    {
    	t->left=t->right=t->parent=NULL;
    	key1=item;
    	keyCount=1;
    }
    return t;
}

Tree* insert(Tree* root,Tree* parent,int item)
{
	if(root == NULL)
	{
		Tree* node = getNode(item);
		node->parent = parent;
		return node;
	}
	else if(root->left || root->right)
	{
		if(root->key1 > item)
			insert(root->left,root,item);
		else if (root->keyCount == 2 && root->key2 > item)
			insert(root->mid,root,item); 
		else
			insert(root->right,root,item);
	}
	else if(!root->left && !root->right )
	{
		if(root->keyCount == 1)
		{
			root->keyCount++;
			if(root->key1<item)
				root->key2 = item;
			else
			{
				root->key2 = root->key1;
				root->key1 = item;
			}
			return root;
		}
		else if(root->keyCount == 2)
		{
			int a=root->key1,b=root->key2,c=item,mid;
			int small = (a<b)?(a<c)?a:c:(c<b)?c:b;
			int large = (a>b)?(c>a)?c:a:(c>b)?c:b;
			int mid = (small == a && large == b)?c:(small == b && large == c)?a:b;
			if (root->parent == NULL)
			{
				Tree* node = getNode(mid);
				node->left = getnode(small);
				node->right = getnode(large);
				node->left->parent = node;
				node->right->parent = node;
				return node;
			}
			else if(root->parent->keyCount == 1)
			{
				root->parent->keyCount++;
				if(root->parent->key1<mid)
					root->parent->key2 = mid;
				else
				{
					root->parent->key2 = root->parent->key1;
					root->parent->key1 = mid;
				}
			}
			else if(root->parent->keyCount == 2)
			{
				if(root->parent->mid == root)
				{
					while(root->parent->keyCount == 2)
					{
						Tree* left = getNode(small);
						Tree* right = getNode(large);
						INCOMPLETE
					}
				}
			}
			else
				printf("Other case\n");
		}

	}
	else
		printf("Other case 2\n");
}

int main()
{
	Tree* t = NULL;
	t = insert(t,NULL,item);

}