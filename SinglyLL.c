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


void insert_beg()
{
	MALLOC(newnode, 1, struct node);
	printf("\n Enter the data ");
	scanf("%d",&(newnode->data));
	newnode->link=NULL;
	if (start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->link=start;
		start=newnode;
	}

	
}

void locbased_insert()
{	int count=0,pos,i;
	
	ptr=start;
	while (ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("enter the position");
	scanf("%d",&pos);
	if (pos==1)
	{
	insert_beg();
	}
	else
	if (pos>1 && pos<=count)
	{	
	MALLOC(newnode, 1, struct node);
	printf("\n Enter the data ");
	scanf("%d",&(newnode->data));
	newnode->link=NULL;	
		ptr=start;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
	newnode->link=ptr->link;
	ptr->link=newnode;
	}
	else 
	if (pos==count+1)
	insert_end();
	else
	printf("position wrong");
}
		

void del_end()
{	if (start==NULL)
	{
		printf("the list is empty");
	}
	else
	if (start->link == NULL) 
	{	
		ptr = start;
		start = NULL;
	}
else
{
		ptr=start;
		while (ptr->link!=NULL)
		{	
			temp=ptr;
			ptr= ptr->link;
			
		}
		temp->link=NULL;
		free(ptr);
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

void locbased_del()
{	int count=0,pos,i;
	
	ptr=start;
	while (ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("enter the position");
	scanf("%d",&pos);
	if (pos==1)
	{
	del_beg();
	}
	else if(pos==count)
    del_end();
    else if (pos>1 && pos<count)
	{		
		ptr=start;
		for(i=1;i<pos;i++)
		{	temp=ptr;
			ptr=ptr->link;
		}
	temp->link=ptr->link;
	free(ptr);
	}
	else 
	printf("position wrong");
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
		printf("\n Menu \n 1. Insert_end  \n 2. Insert_beg  \n 3. Display  \n 4.Location based \n \n 5. Delete_end \n6. Delete_beg\n7. Loc_based_del\n8.Exit");
		scanf("%d",&ch);
		switch(ch)
		{ 
			case 1: insert_end();
				break;
			case 2: insert_beg();
				break;
			case 3: display();
				break;
			case 4: locbased_insert();
				break;
			case 5: del_end();
				break;
			case 6: del_beg();
				break;
			case 7: locbased_del();
				break;
			case 8: exit(0);
			default: printf("Enter a valid choice");
		}
	}
}


