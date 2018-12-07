#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50
typedef enum {head,entry} tagfield;
typedef struct entryNode
{
	int row;
	int col;
	int value;
};
typedef struct matrixNode
{
	struct matrixNode* down;
	struct matrixNode* right;
	tagfield tag;
	union
	{
		struct matrixNode *next;
		struct entryNode entry;
	}u;
};
typedef struct matrixNode *matrixPointer;
matrixPointer hdnode[MAX_SIZE];
matrixPointer mread(void)
{
	int numRows,numCols,numTerms,numHeads,i;
	int row,col,value,currentRow;
	matrixPointer temp,last,node;

	printf("Enter the number of row,columns and numTerms\n");
	scanf("%d%d%d",&numRows,&numCols,&numTerms);
	numHeads=(numCols>numRows)? numCols:numRows;
	node = malloc(sizeof(*node));
	node -> tag=entry;
	node ->u.entry.row=numRows;
	node ->u.entry.col=numCols;
	if(!numHeads) node->right=node;
	else
	{
		for(i=0;i<numHeads;i++)
		{
			temp = malloc(sizeof(*node));
			hdnode[i] = temp;
			hdnode[i]->tag=head;
			hdnode[i]->right = temp;
			hdnode[i]->u.next=temp;

		}
		currentRow=0;
		last = hdnode[0];
		for(i=0;i<numTerms;i++)
		{
			printf("Enter row,column and value:");
			scanf("%d%d%d",&row,&col,&value);
			if(row>currentRow)
			{
				last->right=hdnode[currentRow];
				currentRow=row;
				last=hdnode[row];
			}
			temp = malloc(sizeof(*temp));
			temp->tag=entry;
			temp->u.entry.row=row;
			temp->u.entry.col=col;
			temp->u.entry.value=value;
			last->right=temp;
			last = temp;
			hdnode[col]-> u.next->down = temp;
			hdnode[col]->u.next=temp;
		}
		last->right = hdnode[currentRow];
		for(i=0;i<numCols;i++)
		{
			hdnode[i]->u.next->down=hdnode[i];
		}
		for(i=0;i<numHeads - 1;i++)
		{
			hdnode[i]->u.next=hdnode[i+1];
		}
		hdnode[numHeads-1]->u.next=node;
		node->right = hdnode[0];
	}
	//////////////////matrixB//////////////////////////////

	/*int numRows,numCols,numTerms,numHeads,i;
	int row,col,value,currentRow;
	matrixPointer temp,last,node;

	printf("Enter the number of row,columns and numTerms\n");
	scanf("%d%d%d",&numRows2,&numCols2,&numTerms2);
	numHeads2=(numCols2>numRows2)? numCols2:numRows2;
	node2 = malloc(sizeof(*node2));
	node2 -> tag=entry;
	node2 ->u.entry.row=numRows2;
	node2 ->u.entry.col=numCols2;
	if(!numHeads2) node2->right=node2;
	else
	{
		for(i=0;i<numHeads2;i++)
		{
			temp2 = malloc(sizeof(*node2));
			hdnode2[i] = temp2;
			hdnode2[i]->tag=head;
			hdnode2[i]->right = temp2;
			hdnode2[i]->u.next=temp2;

		}
		currentRow2=0;
		last2 = hdnode2[0];
		for(i=0;i<numTerms2;i++)
		{
			printf("Enter row,column and value:");
			scanf("%d%d%d",&row2,&col2,&value2);
			if(row2>currentRow2)
			{
				last2->right=hdnode2[currentRow];
				currentRow2=row2;
				last2=hdnode2[row2];
			}
			temp2 = malloc(sizeof(*temp2));
			temp2->tag=entry;
			temp2->u.entry.row=row2;
			temp2->u.entry.col=col2;
			temp2->u.entry.value=value2;
			last2->right=temp2;
			last2 = temp2;
			hdnode2[col]-> u.next->down = temp2;
			hdnode2[col]->u.next=temp2;
		}
		last2->right = hdnode2[currentRow2];
		for(i=0;i<numCols2;i++)
		{
			hdnode2[i]->u.next->down=hdnode2[i];
		}
		for(i=0;i<numHeads2 - 1;i++)
		{
			hdnode2[i]->u.next=hdnode2[i+1];
		}
		hdnode2[numHeads2-1]->u.next=node2;
		node2->right = hdnode2[0];
	}*/
	return node;
}
multiplier(matrixPointer node1,matrixPointer node2)
{
	printf("a*b transpose:\n");
	printf("numRows=%d,numCols=%d\n",node1->u.entry.row,node2->u.entry.row);
	
	int tmp,i,j,count=0;
	int number=0;
	matrixPointer temp1,head1=node1->right,head2=node2->right,temp2;
	temp1=head1->right;
	temp2=head2->right;
	for(i=0 ;i<node1->u.entry.row;i++)
	{
		for(j=0;j<node2->u.entry.row;j++)
		{
			while(1)
			{
				if(temp1->u.entry.col==temp2->u.entry.col)
				{
					printf("%d %d\n",temp1->u.entry.col,temp2->u.entry.col);
					number += temp1->u.entry.value * temp2->u.entry.value;
					temp1=temp1->right;
					temp2=temp2->right;
					
					
				}
				else if(temp1->u.entry.col>temp2->u.entry.col)
				{
					temp2=temp2->right;
				}
				else if(temp1->u.entry.col<temp2->u.entry.col)
				{
					temp1=temp1->right;
				}
				else if(temp1->u.entry.col==node1->u.entry.col||temp2->u.entry.col==node1->u.entry.col)
				{
					
					if(number==0)
					{
						break;
					}
					else
					{
						printf("%d %d %d\n",i-1,j-1,number);
						break;
					}
				}
				
			}
			number = 0;
		}
		head1=head1->u.next;
		head2=head2->u.next;
		
		
	}
}
matrixPointer transpose(matrixPointer node)
{
	int tmp,i,count=0;
	matrixPointer temp,head=node->right;
	printf("b transpose:\n");
	printf("numRows=%d,numCols=%d\n",node->u.entry.col,node->u.entry.row);
	printf("The matrix by row column and value:\n");
	for(i=0 ;i<node->u.entry.row;i++)
	{
		for(temp = head->right;temp!=head;temp=temp->right)
		{
			printf("%d %d %d\n",temp->u.entry.col,temp->u.entry.row,temp->u.entry.value);
		}
		head=head->u.next;
	}
}
void mwrite(matrixPointer node)
{
	printf("456456\n");
	int i,c;
	matrixPointer temp,head=node->right;
	for(i=0;i<node->u.entry.row;i++)
	{
		temp=head->right;
		for(c=0;c<node->u.entry.col;c++)
		{
			if(temp->u.entry.row==i && temp->u.entry.col==c)
			{
				printf("%d ",temp->u.entry.value);
				temp=temp->right;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
		head=head->u.next;
	}
}
void main()
{
	matrixPointer a,b;
	a=mread();
	b=mread();
	transpose(b);
	multiplier(a,b);
}
