#include <stdio.h>
#include <stdlib.h>
void merge(int b[],int p,int c[],int q,int a[],int* opcount)
{
	int i=0,j=0,k=0;
	while(i<p && j<q)
	{
		(*opcount)++;
		if(b[i]<=c[j])
			a[k++]=b[i++];
		else
			a[k++]=c[j++];
	}
	if(i==p)
		for(i=j;i<q;i++)
			a[k++]=c[i];
	else
		for(j=i;j<p;j++)
			a[k++]=b[j];
}

void mergesort(int arr[],int l,int r,int* opcount)
{
	int i;
	int n = r-l+1;
	if(n>1)
	{
		int* a = (int*)calloc(n/2,sizeof(int));
		for(i=0;i<n/2;i++)
			a[i]=arr[i];

		int* b = (int*)calloc(n-n/2,sizeof(int));
		for(i=0;i<n-n/2;i++)
			b[i]=arr[n/2 + i];

		mergesort(a,0,n/2-1,opcount);
		mergesort(b,0,n-n/2-1,opcount);

		merge(a,n/2,b,n-n/2,arr,opcount);
	}
}

int main()
{
	// int m,i=0,j=0,arr[100];
	// printf("Enter the array which has to be sorted, terminated by -1\n");
	// while(scanf("%d",&arr[i++]) && arr[i-1]!=-1);
	// int len = i-1,opcount = 0;
	// mergesort(arr,0,len-1,&opcount);
	// printf("Sorted array is : ");
	// while(j<i-1)
	// 	printf("%d ",arr[j++]);

	// printf("\nOpcount is: %d\n",opcount);


	int *a;
	int n=5,i,j,k;
	for(j=0;j<20;j++)
	{
		a=(int*)malloc(sizeof(int)*n);
		for(k=0;k<n;k++)
			a[k]=n-k;
		int opcount = 0;
		mergesort(a,0,n-1,&opcount);
		// printf("Elements after bubble sort: ");
		// for(i=0;i<n;i++)
		// 	printf("%d ",a[i]);
		// printf("\n");
		printf("%d,%d\n",n,opcount);
		free(a);
		n+=25;
	}
	return 0;
}