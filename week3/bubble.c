#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;
int bubbleSort(int a[],int n)
{
	int i,j,temp,opcount=0;
	bool flag=true;
	for(i=0;flag && i<n;i++)
	{
		flag=false;
		for(j=0;j<n-1-i;j++)
		{	
			opcount++;	
			if(a[j]>a[j+1])
			{
				flag=true;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]= temp;
			}
		}
	}
	return opcount;
}

int main()
{
	// int m,i=0,j=0,arr[100];
	// printf("Enter the array which has to be sorted, terminated by -1\n");
	// while(scanf("%d",&arr[i++]) && arr[i-1]!=-1);
	// bubbleSort(arr,--i);
	// printf("Sorted array is : ");
	// while(j != i)
	// 	printf("%d ",arr[j++]);
	// return 0;

	int *a;
	int n=5,i,j,k;
	for(j=0;j<10;j++)
	{
		a=(int*)malloc(sizeof(int)*n);
		for(k=0;k<n;k++)
			a[k]=n-k;
		int opcount = bubbleSort(a,n);
		printf("Elements after bubble sort: ");
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		printf("\n%d\n",opcount);
		free(a);
		n+=5;
	}
	return 0;
}