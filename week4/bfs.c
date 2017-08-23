#include <stdio.h>
#include <stdlib.h>
void bfs(int** arr, int visited[],int i,int n,int* count)
{
	int* queue= (int*)calloc(n,sizeof(int));
	int front = -1,rear=-1;
	int j;
	(*count)++;
	visited[i]=*count;
	queue[++rear] = i;
	while(front != rear)
	{
		for(j=0;j<n;j++)
		{
			if(arr[queue[front+1]][j] && !visited[j])
			{
				(*count)++;
				visited[j]=*count;
				queue[++rear]=j;
			}
		}
		front++;
	}
}
void bfs_helper(int** arr,int visited[],int n,int* count)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if(!visited[i])
			bfs(arr,visited,i,n,count);
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
	*count = 0;
	for(i=0;i<n;i++)
		arr[i] = (int*)calloc(n,sizeof(int));

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			printf("Is %c connected to %c? ",(char)(i+65),(char)(j+65));
			scanf("%d",&x);
			if(x == 1 || x == 0)
				arr[i][j]=arr[j][i]=x;
			else
				printf("Undefined Value. Default: 0\n");
		}
	}
	bfs_helper(arr,visited,n,count);

	printf("BFS Order: \n");
	for(i=1;i<=n;i++)
		for(j=0;j<n;j++)
			if(i == visited[j])
				printf("%c,", (char)(j+65));

	

	printf("\n");

}
