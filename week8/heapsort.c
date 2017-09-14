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
int* max(int* a,int* b)
{
	return ((*a>*b)?a:b);
}
void sort(int heap[],int n)
{
	swap(&heap[1],&heap[n]);
	n--;
	int k=1;
 	while(2*k<=n)
 	{
 		int flag = 0;
 		if(2*k+1<=n)
 		{
 			int* maxp=max(&heap[2*k+1],&heap[2*k]);
 			if(*maxp>heap[k])
 			{
 				flag=(int)(maxp-heap);
 				swap(maxp,&heap[k]);
 			}
 		}
 		else if(2*k==n)
 			if(heap[2*k]>heap[k])
 			{
 				flag=2*k;
 				swap(&heap[2*k],&heap[k]);
 			}
 		if(!flag)
 			break;
 		k=flag;
 	}
}
int main(int argc, char const *argv[])
{
	int n,i;
	printf("Enter no. of nodes to be inserted.\n");
	scanf(" %d",&n);
	int* heap =(int*)calloc(n+1,sizeof(int));
	//Heap Construction
	
	printf("Enter %d values\n", n);
	int ele;
	for(i=1;i<=n;i++)
	{
		scanf(" %d",&ele);
		insert(heap,i,ele);
	}
	printf("\nHeap:");
	for(i=1;i<=n;i++)
		printf("%d,", heap[i]);
	for(i=n;i>1;i--)
		sort(heap,i);
	printf("\nSort:");
	for(i=1;i<=n;i++)
		printf("%d,", heap[i]);

}
