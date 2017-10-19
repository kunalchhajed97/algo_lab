#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comparisons = 0;

void flushstdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int* computeShiftTable(char* pattern,int m)
{
	int* table = (int*)calloc(95,sizeof(int));
	int i;
	for(i=0;i<95;i++)
		table[i]=m;
	for(i=0;i<m-1;i++)
		table[pattern[i]-32] = m-1-i;
	return table;
}

int horspool(char* pattern,int m,char* text,int n)
{
	int* table = computeShiftTable(pattern,m);
	int i = m-1;
	while(i<=n-1)
	{
		int k = 0;
		while(k<=m-1 && pattern[m-1-k] == text[i-k])
		{	
			k++;
			comparisons++;
		}
		if(k==m)
			return i-m+1;
		else
			i+=table[text[i]-32];
	}
	return -1;
}
int main()
{
	printf("Enter text:\n");
	char text[1000],pattern[100];
	//flushstdin();
	fgets(text,sizeof(text),stdin);
	printf("Enter pattern to be searched:\n");
	fgets(pattern,sizeof(pattern),stdin);
	int n = strlen(text),m = strlen(pattern);
	text[n-1] = pattern[m-1] = '\0';
	//printf("%s",text);
	int i = horspool(pattern,m-1,text,n-1);
	if(i==-1)
		printf("Pattern not found.\n");
	else
		printf("Pattern found at position %d\n",i);
	printf("No. of key comparisons: %d.\n", comparisons);
}
