#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int l,int r,int* opcount)
{
	int pivot = arr[l];
	int i = l,j = r+1,k;
	do
	{
		do
		{
			i++; (*opcount)++;
		}while(i<r && arr[i]<pivot);
		
		do
		{ 
			j--; (*opcount)++;
		}while(arr[j]>pivot);
		swap(&arr[i],&arr[j]);
		
	}while(i<j);
	swap(&arr[i],&arr[j]);
	swap(&arr[l],&arr[j]);
	return j;
}

void quicksort(int arr[],int l,int r,int* opcount)
{
	if(l<r)
	{
		int s = partition(arr,l,r,opcount);
		quicksort(arr,l,s-1,opcount);
		quicksort(arr,s+1,r,opcount);
	}
}

int main()
{
	// int m,i=0,j=0,arr[100];
	// printf("Enter the array which has to be sorted, terminated by -1\n");
	// while(scanf("%d",&arr[i++]) && arr[i-1]!=-1);
	// int len = i-1;
	// quicksort(arr,0,len-1);
	// printf("Sorted array is : ");
	// while(j<i-1)
	// 	printf("%d ",arr[j++]);
	// printf("\n");


	int *a;
	int n=5,i,j,k;
	for(j=0;j<1;j++)
	{
		a=(int*)malloc(sizeof(int)*n);
		for(k=0;k<n;k++)
			a[k]=n-k;
		int opcount = 0;
		quicksort(a,0,n-1,&opcount);
		printf("Elements after bubble sort: ");
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		printf("%d,%d\n",n,opcount);
		free(a);
		n+=25;
	}
	return 0;
}