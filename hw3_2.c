#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int push_stack(int );
int pop_stack();
int top=0;
int stack_arr[10000];
int main()
{
	int length;
	int top=0,k=0,l=0,p=0,j=0;
	int x1,x2,result,answer,int_input;
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
	length=p;
	while(length>=0)
	{
		//printf("%s\n",word[length]);
		if(!(strcmp(word[length],"+")))
		{
			x1=pop_stack();
			x2=pop_stack();
			result=x1+x2;
			push_stack(result);
		}
		else if(!(strcmp(word[length],"-")))
		{
			x1=pop_stack();
			x2=pop_stack();
			result=x1-x2;
			push_stack(result);
		}
		else if(!(strcmp(word[length],"*")))
		{
			x1=pop_stack();
			x2=pop_stack();
			result=x1*x2;
			push_stack(result);
		}
		else if(!(strcmp(word[length],"/")))
		{
			x1=pop_stack();
			x2=pop_stack();
			result=x1/x2;
			push_stack(result);
		}
		else
		{
			int_input=atoi(word[length]);
			push_stack(int_input);
		}
		length--;
	}
	answer=pop_stack();
	printf("answer:%d\n",answer);
}
int push_stack(int a)
{
	stack_arr[top]=a;
	//printf("stack:%d",stack_arr[top]);
	top++;
}
int pop_stack()
{	
	top --;
	//printf("pop:%d",stack_arr[top]);
	return stack_arr[top];
}
