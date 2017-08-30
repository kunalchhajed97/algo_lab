#include <stdio.h>
#include <stdlib.h>
void source_removal(int** arr,int n,int* removed,int remaining)
{
	int j,i,m,count=0;
	if(remaining)
	{
		for (j = 0; j < n; j++)
		{
			if(!removed[j])
			{
				count=0;
				for(i = 0; i<n; i++)
				{
					count+=arr[i][j];
				}
				if(!count)
				{
					printf("%c,",(char)(j+65));
					for(m=0;m<n;m++)
						arr[j][m]=0;
					removed[j]=1;
					source_removal(arr,n,removed,remaining-1);
				}
			}
		}
		printf("\nTopological sorting not possible.\n");
		exit(1);
	}
}
int main()
{
	printf("Enter number of nodes\n");
	int n,i,j,x;
	scanf("%d",&n);
	int** arr = (int**)calloc(n,sizeof(int*));
	int* removed = (int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		arr[i] = (int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
			if(i!=j)
			{
				printf("Is %c connected to %c? ",(char)(i+65),(char)(j+65));
				scanf("%d",&x);
				if(x == 1 || x == 0)
					arr[i][j]=x;
				else
					printf("Undefined Value. Default: 0\n");
			}
	}
	source_removal(arr,n,removed,n);
	printf("\n");
}





