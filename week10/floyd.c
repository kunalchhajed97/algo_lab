#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,k,x;scanf("%d",&n);
	int** arr = (int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{
		arr[i] = (int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			if(x==-1)
				x=INT_MAX/2;
			arr[i][j]=x;
		}
	}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				arr[i][j]=min(arr[i][j],(arr[i][k]+arr[k][j]));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

