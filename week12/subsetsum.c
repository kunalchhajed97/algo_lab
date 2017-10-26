#include <stdio.h>
#include <stdlib.h> 
void printSubset(int A[], int size)
{
	int i;
    for(i = 0; i < size; i++)
        printf("%d,", A[i]);
    printf("\n");
}
int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}
void subset_sum(int s[], int t[],int s_size, int t_size,int sum, int ite,int const target_sum)
{
	int i;
    if( target_sum == sum )
    {
        printSubset(t, t_size);
        if( ite + 1 < s_size && sum - s[ite] + s[ite+1] <= target_sum )
            subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else
        if( ite < s_size && sum + s[ite] <= target_sum )
            for(i = ite; i < s_size; i++ )
            {
                t[t_size] = s[i];
                if( sum + s[i] <= target_sum )
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
            }
}
 
int main()
{
	int n,i,sum;
	printf("Enter set size\n");scanf("%d",&n);
	printf("Enter set of size %d\n",n);
	int* arr=(int*)calloc(n,sizeof(int));
	int *tuple_vector = (int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
    printf("Enter target sum\n");scanf("%d",&sum);
    qsort(arr, n, sizeof(int), &comparator);
    subset_sum(arr, tuple_vector, n, 0, 0, 0,sum);
    return 0;
}