#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

void insert(int* heap,int k,int ele)
{
	heap[k] = ele;
	while(k!=1 && heap[k/2]<heap[k])
	{
		swap(&heap[k/2],&heap[k]);
		k/=2;
	}
}

int main(int argc, char const *argv[])
{
	int n,i;
	printf("Enter no. of nodes to be inserted.\n");
	scanf(" %d",&n);
	int* heap =(int*)calloc(n+1,sizeof(int));
	
	printf("Enter %d values\n", n);
	int ele;
	for(i=1;i<=n;i++)
	{
		scanf(" %d",&ele);
		insert(heap,i,ele);
	}

	for(i=1;i<=n;i++)
		printf("%d,", heap[i]);
	return 0;
}
