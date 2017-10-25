#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	float freq;
	int leaf;
	char ch;
	struct node *left,*right;
}Node;
Node** sort(Node** nodes,int n)
{
	int i,j;
	for (i = 0; i < n; ++i)	
		for(j=0;j<n-1-i;j++)
			if(nodes[j]->freq>nodes[j+1]->freq)
			{
				Node* n =nodes[j];
				nodes[j] = nodes[j+1];
				nodes[j+1] = n; 
			}
	return nodes;
}
Node* HuffmanCodes(Node** nodes,int n)
{
	int i;
	for(i=0;i<n-1;i+=2)
	{
		Node* new = (Node*)malloc(sizeof(Node));
		new->left = nodes[i];
		new->right = nodes[i+1];
		new->leaf = 0;
		new->freq = nodes[i]->freq+nodes[i+1]->freq;
		nodes[n] = new;
		n++;
		nodes = sort(nodes,n);
	}
	return nodes[n-1];
}
int printCodes(Node* tree,int arr[],int i)
{
	if(tree->leaf == 1)
	{
		printf("%c-->",tree->ch);
		int k;
		for(k=0;k<i;k++)
			printf("%d",arr[k]);
		printf("\n");
	}
	else
	{
		arr[i]=0;
		printCodes(tree->left,arr,i+1);
		arr[i]=1;
		printCodes(tree->right,arr,i+1);
	}

}
int main()
{
	int n,i,j;
	printf("Input size of alphabet: ");scanf("%d",&n);
	Node** nodes = (Node**) calloc(n*n,sizeof(Node*));
	printf("Input alphabet\n");
	for(i=0;i<n;i++)
	{
		nodes[i]=(Node*)malloc(sizeof(Node));
		scanf(" %c",&(nodes[i]->ch));
	}
	printf("Input frequencies\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&(nodes[i]->freq));
		nodes[i]->leaf = 1;
	}
	//sort
	nodes = sort(nodes,n);
	Node* tree = HuffmanCodes(nodes,n);
	int* arr = (int*)calloc(n*n,sizeof(int));
	printCodes(tree,arr,0);
    return 0;
}
