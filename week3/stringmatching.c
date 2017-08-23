#include<stdio.h>

int stringmatching(char text[],int m,char pattern[],int n)
{
	int i,j;
	for(i=0;i<=m-n;i++)
	{
		j=0;
		while(j<n && text[i+j]==pattern[j])
			j++;
		if(j==n)
			return i;
	}
	return -1;
}

void flushstdin()
{
	int c;
	while((c=getchar())!='\n' && c!= EOF);
}

int main()
{
	char a[100],b[20];
	int m=0,n=0;
	printf("Enter text: ");
	scanf("%[^\n]s",a);
	flushstdin();
	while(a[m]!='\0')m++;
	printf("Enter pattern: ");
	scanf("%[^\n]s",b);
	flushstdin();
	while(b[n]!='\0')n++;
	int pos = stringmatching(a,m,b,n);
	printf("%d\n",pos);
	return 0;

}