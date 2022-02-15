#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type)            \
p=(type*)malloc(n*sizeof(type));    \
if(p==NULL)                         \
{                                   \
    printf("Insufficient Memory");  \
    exit(0);                        \
}

struct node
{
    int data;
    struct node *link;
};

struct node *start=NULL,*cur,*temp,*prev;

void insert(int item)
{
    MALLOC(temp,1,struct node);
    temp->data=item;
    temp->link=NULL;
    if(start==NULL)
       start=temp;
       else{
cur=start;
while(cur->link!=NULL)
    cur=cur->link;
    cur->link=temp;
}
}
void display()
{
    if(start==NULL)
    printf("The list is empty\n");
    else{
        cur=start;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    
    }

}

void reverse()
{
        prev=start;
        cur=start->link;
        start=start->link;
        prev->link=NULL;
        while(start!=NULL)
        {
            start=start->link;
        cur->link=prev;
        prev=cur;
        cur=start;
    }
    start=prev;
  
}

void main()
{
    int item;
    start=NULL;
    printf("Enter the elements(Enter -1 to stop)\n");
    while(1)
    {
        scanf("%d",&item);
        if(item==-1)
        break;
        else
        insert(item);
    }
    printf("\nBefore reversal\n");
    display();
    reverse();
    printf("\nAfter reversal\n");
    display();

} 


