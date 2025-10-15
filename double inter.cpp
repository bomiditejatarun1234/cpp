#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
typedef struct node NODE;
NODE *create();
void insert();
void deleteatbegin();
void traverse();
int size=0;
NODE *head=NULL;
NODE *create()
{
	NODE *newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter data");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	size++;
	return newnode;
}
void insert()
{
	NODE *newnode=create();
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->right=head;
		head=newnode;
	}
	
}
void deleteatbegin()
{
	NODE *t;
	if(head==NULL)
	printf("deletion is not possible");
	else
	{
		printf("%d is removed\n",head->data);
		t=head;
		head=head->right;
		head->left=NULL;
		size--;
		free(t);
	}
}
void traverse()
{
	NODE *t;
	if(head==NULL)
	printf("list is empty");
	else
	{
		t=head;
		while(t!=NULL)
		{
		printf("->%d",t->data);
		t=t->right;
		}
		printf("\n");
	}
}
int main()
{
		int ch;
	do
	{
		printf("1.insert\n2.delete\n3.traverse\n4.size\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:deleteatbegin();
			break;
			case 3:traverse();
			break;
			case 4:printf("%d\n",size);
			break;
			default:exit(0);
		}
		
	}while(1);
	return 0;

}
