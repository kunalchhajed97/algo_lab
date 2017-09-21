#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tablesize 30 
typedef struct node{
	char* string;
	struct node* next;
}Node;
Node* newnode(char* str)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->string = (char*)malloc((strlen(str)+1)*sizeof(char));
	strcpy(temp->string,str);
	temp->next = NULL;
	return temp;
}
int hashcode(char* string)
{
	int i,count = 0;
	for(i=0;i<strlen(string);i++)
		count+=string[i]-65;
	return count%tablesize;
}
Node* insert(Node* head,char* str)
{
	Node* temp = head;
	if(temp == NULL)
		return newnode(str);
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = newnode(str);
	return head;
}
int search(Node* head,char* buffer)
{
	while(head!=NULL)
	{
		if(strcmp(buffer,head->string) == 0)
			return 1;
		head=head->next;
	}
	return 0;

}
int main()
{
	int n,i,j;
	Node** table = (Node**)calloc(tablesize,sizeof(Node*));
	printf("Enter no. of words to be inserted: ");
	scanf("%d",&n);
	char buffer[100];
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		table[code] = insert(table[code],buffer);
	}
	printf("Enter number of words to be searched: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		memset(buffer,0,100);
		scanf("%s",buffer);
		int code = hashcode(buffer);
		if(search(table[code],buffer))
			printf("Found\n");
		else
			printf("Not Found\n");
	}
	return 0;
}