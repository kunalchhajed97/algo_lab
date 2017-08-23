#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int disjoint(int a[],int m,int b[],int n)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(a[i]==b[j])
			return 0;
		else if(a[i]<b[j])
			j++;
		else
			i++;
	}
	return 1;
}
int solve(int arr[],int n,int arrsum)
{
	int i,j,k;
	int len=pow(2,n);
	int set[n];
	int complementset[n];
	for(i=0;i<len;i++)
	{
		int sum=0,m=0,p=0;
		for(j=n-1;j>=0;j--)
		{
			int bit=(i/(int)pow(2,j))%2;
			if(bit)
			{
				sum+=arr[j];
				set[m++]=arr[j];
			}
			else
			{
				complementset[p++]=arr[j];
			}
		}
		if(arrsum/2 == sum)
		{
			if(disjoint(set,m,complementset,p))
			{	
				for(k=0;k<m;k++)
					printf("%d,", set[k]);
				printf("   ");
				for(k=0;k<p;k++)
					printf("%d,", complementset[k]);
				printf("\n");
				return 0;
			}
		}
	}
	printf("Not possible\n");
	return 0;
}
int main()
{
	int n,i,sum=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	if(!(sum%2))
	{
		qsort(arr,n,sizeof(int),cmpfunc);
		solve(arr,n,sum);
	}
	else
		printf("Not possible\n");


	return 0;
}
