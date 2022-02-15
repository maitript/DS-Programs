#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink,*rlink;
};
int lchild(struct node *tree)
{
    int choice;
    printf("Do want the left child for %d ? YES=1,NO=0\n",tree->data);
    scanf("%d",&choice);
    if(choice==1)
    return(1);
    else
    return(0);
}
int rchild(struct node *tree)
{
    int choice;
    printf("Do want the right child for %d ? YES=1,NO=0\n",tree->data);
    scanf("%d",&choice);
    if(choice==1)
    return(1);
    else
    return(0);
}
void create(struct node *tree)
{
    if(lchild(tree)==1)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:-\n");
        scanf("%d",&newnode->data);
        tree->llink=newnode;
        newnode->llink=NULL;
        newnode->rlink=NULL;
        create(newnode);
    }
    else
    tree->llink=NULL;
    if(rchild(tree)==1)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:-\n");
        scanf("%d",&newnode->data);
        tree->rlink=newnode;
        newnode->llink=NULL;
        newnode->rlink=NULL;
        create(newnode);
    }
    else
    tree->rlink=NULL;
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
    printf("Enter the Root Node:- \n");
    scanf("%d",&newnode->data);
    newnode->llink=NULL;
    newnode->rlink=NULL;
    root=newnode;
    create(root);
    printf("The inorder traversal of Binary Tree:-\n");
    inorder(root);
}