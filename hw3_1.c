#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
int main()
{
	Node *first,*current,*previous;
	int flag=0;
	int number;
	first = NULL;
	char input[1000];
	char word[100][100];
	char *token;
	int p=0,j=0;
	while(1)
	{
		fgets(input,1000,stdin);
		token = strtok(input," ");
		token = strtok(NULL," ");
		if(input[0]=='s')
		{
			current = first;
			if(current==NULL)
			{
				printf("Queue is empty\n");
			}
			else
			{
				while(current != NULL)
				{
					printf("%d\t",current->data);
					current=current->next;
				}
				printf("\n");
			}
		}
		else if(input[0]=='p' && input[1]=='u' && input[5]=='b')
		{
			Node *temp;
			number = atoi(token);
			current=(Node *)malloc(sizeof(Node));
			current->data=number;
			if(flag == 0)
			{
				first=current;
				flag = 1;
			}
			else
			{
				temp=first;
				while(temp->next != NULL)
				{
					temp=temp->next;
				}
				temp->next=current;
			}
		
		current->next=NULL;
		}
		else if(input[0]=='p' && input[1]=='u' && input[5]=='f')
		{
			Node *temp;
			number = atoi(token);
			current=(Node *)malloc(sizeof(Node));
			current->data=number;
			if(flag==0)
			{
				first=current;
				flag = 1; 
				current->next=NULL;
			}
			else
			{
				current->next=first;
				first=current;
			}

		}
		else if(input[0]=='p' && input[1]=='o' && input[4]=='f')
		{
			Node *temp;
			current=first;
			temp=current;
			current=current->next;
			first = current;
			free(temp);
		}
		else if(input[0]=='p' && input[1]=='o' && input[4]=='b')
		{
			Node *temp,*pre;
			current=first;
			while(current->next != NULL)
			{
				pre=current;
				current=current->next;
			}
			pre->next = NULL;
			temp = current;
			free(temp);

		}
		
		
	}

}
