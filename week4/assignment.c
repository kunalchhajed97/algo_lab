#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minsum=INT_MAX;
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

void assign(int** mat,int arr[],int n)
{
	int i,sum=0,j;
	for (i=0;i<n;i++)
		sum+=mat[i][arr[i]];
	
	if (sum<minsum)
		minsum = sum;
}

void permute(int arr[],int j,int n,int** mat)
{
	int i;
	if(j==n)
		assign(mat,arr,n+1);
	else
	{
		for(i=j;i<=n;i++)
		{
			swap(&arr[j],&arr[i]);
			permute(arr,j+1,n,mat);
			swap(&arr[j],&arr[i]);
		}
	}
}
int main()
{
	int n,i,j;
	printf("Enter the number of jobs: ");
	scanf("%d",&n);

	int **mat = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
         mat[i] = (int *)malloc(n * sizeof(int));

	int* arr = (int*) malloc(n*sizeof(int));
	printf("Enter cost matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
		arr[i]=i;
	}
	permute(arr,0,n-1,mat);
	printf("%d\n",minsum);
}