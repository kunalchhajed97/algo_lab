#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,k,x;scanf("%d",&n);
	int** arr = (int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{
		arr[i] = (int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			if(i!=j)
			{
				scanf("%d",&x);
				arr[i][j]=x;
			}
	}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				arr[i][j]=arr[i][j]||(arr[i][k]&&arr[k][j]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

