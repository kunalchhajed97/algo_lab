#include <stdio.h>
#include <stdlib.h>
int inArray(int arr[],int len,int ele)
{
	int i;
	for(i=0;i<len;i++)
		if(ele == arr[i])
			return 1;
	return 0;
}
int dfs(int** arr, int visited[],int i,int n,int stack[],int* index)
{
	int j;
	visited[i]=1;
	stack[(*index)++] = i;
	for(j=0;j<n;j++)
	{
		if(arr[i][j] && visited[j] && inArray(stack,(*index)-2,j))
			return 0;
		if(arr[i][j] && !visited[j])
			if (!dfs(arr,visited,j,n,stack,index))
				return 0;
	}
	(*index)--;
	return 1;
}
int cyclic(int** arr,int n)
{
	int i,j,index=0;
	int* visited = (int*)calloc(n,sizeof(int));
	int* stack = (int*)calloc(n,sizeof(int));
	for (i = 0; i < n; i++)
		if(!visited[i])
			if(!dfs(arr,visited,i,n,stack,&index))
				return 1;
	return 0;
}
int** kruskals(int n,int** edges,int x)
{
	int k=0,i,ecounter=0;
	int** arr = (int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
		arr[i] = (int*)calloc(n,sizeof(int));
	while(ecounter<n-1 && k<x)
	{
		arr[edges[k][0]][edges[k][1]]=arr[edges[k][1]][edges[k][0]]=edges[k][2];
		if(!cyclic(arr,n))
			ecounter++;
		else
			arr[edges[k][0]][edges[k][1]]=arr[edges[k][1]][edges[k][0]]=0;
		k++;
	}
	return arr;
}
int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,k,x=0;scanf("%d",&n);
	int** edges = (int**)calloc(n*(n-1),sizeof(int*));
	printf("Enter distance matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&k);
			if(j>i && k!=0)
			{
				edges[x]=(int*)calloc(3,sizeof(int));
				edges[x][0] = i;
				edges[x][1] = j;
				edges[x][2] = k;
				x++;
			}
		}
	//sort
	for(i=0;i<x;i++)
	{
		for(j=0;j<x-1-i;j++)
		{
			if(edges[j][2]>edges[j+1][2])
			{
				int* temp = edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=temp;
			}
		}
	}
	int** arr = kruskals(n,edges,x);
	printf("Output\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}