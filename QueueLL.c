#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p, n, type)		\
p = (type*)malloc(n*sizeof(type));	\
if(p == NULL)				\
{					\
	printf("Insuficient memory\n");	\
	exit(0);			\
}
struct node
{
	int data;
	struct node* link;
};
struct node *start=NULL,*temp,*ptr,*newnode;
int n;

void insert_end()
{

		MALLOC(newnode, 1, struct node);
		printf("\n Enter the data ");
		scanf("%d", &(newnode->data));
		newnode->link=NULL;

		if (start==NULL)
		{		
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->link!=NULL)
			{	
				ptr=ptr->link;		

			}
			ptr->link=newnode;
	
		}
	
}

void del_beg()
{	if (start==NULL)
	{
		printf("the list is empty");
	}
	else
	if (start->link == NULL)
		start = NULL;
	else
	{
		temp=start;
		start=start->link;
		free(temp);
		
	}
}

void display()
{
	if (start==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=start;
		while (ptr!=NULL)
		{	
			printf("\t %d --> ",ptr->data);
			ptr=ptr->link;		

		}
	}
}

void main()
{
	int ch;
	
	while (1)
	{
		printf("\n Menu \n 1. Insert_end\n2.Delete Beg\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: insert_end();
				break;
			case 2: del_beg();
				break;
			case 3: display();
				break;
			
			case 4: exit(0);
			default: printf("Enter a valid choice");
		}
	}
}
