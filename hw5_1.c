#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int adjust(int *a,int k,int length,int flg)
{
	int temp;
	int max;
	//k means location
	while(flg==1&k>1)
	{
		if(a[k]>a[k/2])
		{
			temp=a[k];
			a[k]=a[k/2];
			a[k/2]=temp;
			k=k/2;
		}
		else
		{
			break;
		}
		
	}
	while(flg==0&&2*k<=length)
	{
		if(2*k==length)
		{
			temp=a[k];
			a[k]=a[2*k];
			a[2*k]=temp;
			k=k*2;
		}
		else
		{
			if(a[2*k]>a[2*k+1])
			{
				temp=a[k];
				a[k]=a[2*k];
				a[2*k]=temp;
				k=k*2;
			}
			else if(a[2*k]<a[2*k+1])
			{
				temp=a[k];
				a[k]=a[2*k+1];
				a[2*k+1]=temp;
				k=2*k+1;
			}
			else
			{
				break;
			}
		}


	}
	for(int i=1;i<length;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;

}
int main()
{
	char input[1000];
	char splitstring[100][100];
	int i,j,cnt;
	j=0;
	cnt=1;
	scanf("%[^\n]s",input);
	for(i=0;i<=strlen(input);i++)
	{
		if(input[i]==' '||input[i]=='\0')
		{
			splitstring[cnt][j]='\0';
			cnt++;
			j=0;
		}
		else
		{
			splitstring[cnt][j]=input[i];
			j++;
		}
	}
	int *heap;
	heap = malloc(cnt*sizeof(int));
	for(i=1;i<cnt;i++)
	{
		heap[i]=atoi(splitstring[i]);
	}
	char replace[1000];
	char replacenum[10][10];
	int rnum1,rnum2,flag=0;	
	scanf("%s",replacenum[0]);
	scanf("%s",replacenum[1]);
	rnum1=atoi(replacenum[0]);
	rnum2=atoi(replacenum[1]);
	if(rnum1<rnum2)
	{
		flag=1;
	}
	for(i=1;i<cnt;i++)
	{
		if(heap[i]==rnum1)
		{
			heap[i]=rnum2;
			adjust(heap,i,cnt,flag);
		}
	}
	
	return 0;
}
