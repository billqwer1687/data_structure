#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length;
char stack_T[100][100];
char stack[100][100];
int top=0,top_t=0,k=0;
void pop_scope();
void push_s(char* str);
void pop_s();
void push_t(char* str);
char *pop_t();
int main()
{
	int p=0,j=0;
	char input[10000];
	scanf("%[^\n]s",input);
	char word[100][100];
	for(int i=0;i<strlen(input);i++)
	{
		if(input[i]==' '||input[i]=='\0')
		{
			word[p][j]='\0';
			p++;
			j=0;
		}
		else
		{
			word[p][j]=input[i];
			j++;
		}
	}
/*	for(int i=0;i<=p;i++)
	{
		printf("%s\n",word[i]);
	}*/
	length=p;
	while(length>=0)
	{
		if(!(strcmp(word[length],"+")))
		{
			while(/*!(strcmp(stack[top-1],"+")) || !(strcmp(stack[top-1],"-")) ||*/ !(strcmp(stack[top-1],"*")) || !(strcmp(stack[top-1],"/")))
			{
				pop_s();
			}
			push_s(word[length]);
		}
		else if(!(strcmp(word[length],"-")))
		{
			while(/*!(strcmp(stack[top-1],"+")) || !(strcmp(stack[top-1],"-")) ||*/ !(strcmp(stack[top-1],"*")) || !(strcmp(stack[top-1],"/")))
			{
				pop_s();
			}
			push_s(word[length]);
		}
		else if(!(strcmp(word[length],"*")))
		{
			/*while(!(strcmp(stack[top-1],"*")) || !(strcmp(stack[top-1],"/")))
			{
				pop_s();
			}*/
			push_s(word[length]);
		}
		else if(!(strcmp(word[length],"/")))
		{
			/*while(!(strcmp(stack[top-1],"*")) || !(strcmp(stack[top-1],"/")))
			{
				pop_s();
			}*/
			push_s(word[length]);
		}
		else if(!(strcmp(word[length],")")))
		{
			push_s(word[length]);
		}
		else if(!(strcmp(word[length],"(")))
		{
			pop_scope();
		}
		else
		{
			push_t(word[length]);
		}
		length--;
	}
	while(top!=0)
	{
		pop_s();
	}
	while(top_t >0)
	{
		
		printf("%s ",pop_t());
	}
	printf("\n");
	
}
void pop_scope()
{
	top--;
	while(strcmp(stack[top],")"))
	{
		push_t(stack[top]);
		top--;
	}
}
void push_s(char *str)
{
	k=0;
	for(int i=0;i<strlen(str);i++)
	{
		stack[top][i]=str[i];
	}
	top++;
}
void pop_s()
{
	top--;
	push_t(stack[top]);
}
void push_t(char* str)
{
	k=0;
	for(int i=0;i<strlen(str);i++)
	{
		stack_T[top_t][i]=str[i];
	}
	top_t++;
}
char* pop_t()
{
	top_t--;
	return stack_T[top_t];
}
