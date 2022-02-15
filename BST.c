#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink,*rlink;
};
void create(struct node *tree)
{
    while(1>0)
    {
        int ch;
        printf("Do you want to enter the data: YES=1; NO=0\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            struct node *newnode,*ptr,*temp;
            int c=0;
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("Enter the data:- \n");
            scanf("%d",&newnode->data);
            newnode->rlink=NULL;
            newnode->llink=NULL;
            ptr=tree;
            while(ptr!=NULL)
            {
                if(newnode->data>ptr->data)
                {
                    temp=ptr;
                    ptr=ptr->rlink;
                    c=1;
                }
                else
                {
                    temp=ptr;
                    ptr=ptr->llink;
                    c=-1;
                }
            }
            if(c==1)
            {
                temp->rlink=newnode;
            }
            else
            temp->llink=newnode;    
        }
        else
        break;
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d ",tree->data);
        inorder(tree->rlink);
    }
}
void main()
{
    struct node *newnode,*root;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the ROOT node:-\n");
    scanf("%d",&newnode->data);
    newnode->llink=NULL;
    newnode->rlink=NULL;
    root=newnode;
    create(root);
    printf("Inorder traversal of Binary Tree:- \n");
    inorder(root);
}