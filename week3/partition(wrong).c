#include<stdio.h>
#include<stdlib.h>
int* cpy(int arr[],int pos)
{
	int* arr2 = (int*)calloc(pos+1,sizeof(int));
	while(pos-- >-1)
		arr2[pos]=arr[pos];
	return arr2;
}

void partitions(int target,int max,int arr[],int pos)
{
	int i=0;
	if(target==0)
	{
		for(i=0;i<pos;i++)
			printf("%d + ",arr[i]);
		printf("\n");
	}
	else
	{
		for(i=1;i<=max && i<=target;i++)
		{
			int* arrcpy = cpy(arr,pos);
			arrcpy[pos]=i;
			partitions(target-i,i,arrcpy,pos+1);	
		}
	}
}

int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	int m=n;
	int arr[100];
	partitions(n,m,arr,0);
	return 0;
}