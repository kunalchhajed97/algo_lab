#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tablesize 30 
typedef struct node{
	char* string;
	struct node* next;
}Node;
Node* newTable(int n)
{
	Node* a=(Node*)malloc(sizeof(Node));int i;
	Node* head = a;
	for(i=0;i<n-1;i++)
	{
		a->string = NULL;
		a->next = (Node*)malloc(sizeof(Node));
		a=a->next;
	}
	a->next = head;
	return head;
}
int hashcode(char* string)
{
	int i,count = 0;
	for(i=0;i<strlen(string);i++)
		count+=string[i]-65;
	return count%tablesize;
}
int insert(Node* head,char* str)
{
	while(head->string!=NULL)
		head = head->next;
	head->string = (char*)malloc((strlen(str)+1)*sizeof(char));;
	strcpy(head->string,str);
}
int search(Node* head,char* buffer)
{
	while(head!=NULL || strcmp(head->string,buffer)==0)
		head=head->next;
	if(head==NULL) return 0; else return 1;
}
int main()
{
	int n,i,j;
	printf("Enter no. of words to be inserted: ");
	scanf("%d",&n);
	char buffer[100];
	Node* table = newTable(30);
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		insert(table+code,buffer);
	}
	printf("Enter number of words to be searched: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		if(search(table+code,buffer))
			printf("Found\n");
		else
			printf("Not Found\n");
	}
	return 0;
}