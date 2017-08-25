#include <stdio.h>
#include <stdlib.h>
void dfs(int** arr, int visited[],int i,int n,int* count,int* popped,int* k)
{
	int j;
	(*count)++;
	visited[i]=*count;
	for(j=0;j<n;j++)
		if(arr[i][j] && !visited[j])
			dfs(arr,visited,j,n,count,popped,k);
	popped[(*k)++] = i;
	for(j=0;j<(*k)-1;j++)
		if(arr[popped[j]][i])
		{
			printf("Topological sorting in not possible as the graph is not a DAG.\n");
			exit(1);
		}
}
void dfs_helper(int** arr,int visited[],int n,int* count,int* popped,int* k)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs(arr,visited,i,n,count,popped,k);
	}
}
int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,x;
	scanf("%d",&n);
	int** arr = (int**)calloc(n,sizeof(int*));
	int* visited = (int*)calloc(n,sizeof(int));
	int* count = (int*)malloc(sizeof(int));
	int* popped = (int*)calloc(n,sizeof(int));
	int* popIndex = (int*)malloc(sizeof(int));
	*popIndex = 0;
	*count = 0;
		
	for(i=0;i<n;i++)
	{
		arr[i] = (int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			if(i!=j)
			{
				printf("Is %c connected to %c? ",(char)(i+65),(char)(j+65));
				scanf("%d",&x);
				if(x == 1 || x == 0)
					arr[i][j]=x;
				else
					printf("Undefined Value. Default: 0\n");
			}
	}
	dfs_helper(arr,visited,n,count,popped,popIndex);

	printf("Topological Order:\n");
	for(i=*popIndex-1;i>=0;i--)
		printf("%c,",(char)(popped[i]+65));
	printf("\n");

}





