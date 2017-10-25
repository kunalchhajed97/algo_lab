#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minDistance(int dist[],int sptSet[],int n)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < n; v++)
		if (sptSet[v] == 0 && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	return min_index;
}
int printMatrix(int dist[], int n)
{
	printf("Vertex \t Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t %d\n", i, dist[i]);
}
void dijkstra(int** graph, int src,int n)
{
	int* dist = (int*)calloc(n,sizeof(int));
	int* sptSet = (int*)calloc(n,sizeof(int));
	int i,count,u;
	for (i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	for (count = 0; count < n-1; count++)
	{
		u = minDistance(dist, sptSet,n);
		sptSet[u] = 1;
		
		for (int v = 0; v < n; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printMatrix(dist, n);
}

int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,src;scanf("%d",&n);
	int** arr = (int**)calloc(n,sizeof(int*));
	printf("Enter distance matrix\n");
	for(i=0;i<n;i++)
	{
		arr[i]=(int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
	printf("Enter source vertex number\n");
	scanf("%d",&src);
	dijkstra(arr,src,n);
}