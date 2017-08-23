#include<stdio.h>
#include<stdlib.h>
int selectionSort(int a[],int n)
{
	int i,j,temp,opcount=0,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{	
			opcount++;	
			if(a[j]<a[min])
				min=j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min]= temp;
	}
	return opcount;
}

int main()
{
	int *a;
	int n=5,i,j,k;
	for(j=0;j<10;j++)
	{
		a=(int*)malloc(sizeof(int)*n);
		for(k=0;k<n;k++)
			a[k]=n-k;
		int opcount = selectionSort(a,n);
		printf("Elements after selection sort: ");
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		printf("\n%d\n",opcount);
		free(a);
		n+=5;
	}
	return 0;
}