#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tablesize 13
typedef struct node{
	char* string;
}Node;
int hashcode(char* string)
{
	int i,count = 0;
	for(i=0;i<strlen(string);i++)
		count+=string[i]-64;
	return count%tablesize;
}
int insert(Node* head,int pos,char* str)
{
	while(head[pos].string!=NULL)
		pos = (pos+1)%tablesize;

	head[pos].string = (char*)malloc((strlen(str)+1)*sizeof(char));;
	strcpy(head[pos].string,str);
}
int search(Node head[],int pos,char* buffer)
{
	while(head[pos].string!=NULL)
	{
		if(strcmp(head[pos].string,buffer)==0)
			return 1;
		pos=(pos+1)%tablesize;
	}
	return 0;	
}
int main()
{
	int n,i,j;
	printf("Enter no. of words to be inserted: ");
	scanf("%d",&n);
	char buffer[100];
	Node* table = (Node*)calloc(tablesize,sizeof(Node));
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		insert(table,code,buffer);
	}
	for(i=0;i<tablesize;i++)
	{
		if(table[i].string!=NULL)
			printf("%s\n",table[i].string);
		else
			printf("NULL\n");
	}

	printf("Enter number of words to be searched: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		if(search(table,code,buffer))
			printf("Found\n");
		else
			printf("Not Found\n");
	}
	return 0;
}
