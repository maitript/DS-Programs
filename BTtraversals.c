#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *temp, *newnode,*root=NULL ,*tree;

 int llchild(struct node * tree)
 {
     int ch;
     printf(" Press 1 to create left child or 0 to not for %d \n",tree->data );
     scanf("%d",&ch);
     return (ch);
}


int rrchild(struct node * tree)
 {
     int ch;
     printf(" Press 1 to create right child or 0 to not for %d \n",tree->data );
     scanf("%d",&ch);
     return (ch);
      }

    
void create (struct node* tree)
      {
          if(llchild(tree)==1)
          {
              struct node*newnode;
              newnode=(struct node*)malloc(sizeof(struct node));
              printf("Enter the value \n");
              scanf("%d",&newnode->data);
              tree->llink=newnode;
              newnode->llink=NULL;
              newnode->rlink = NULL;
              create(tree->llink);
          }
          else {
              tree->llink= NULL;
          }
            if(rrchild(tree)==1)
          {
              struct node*newnode;
              newnode=(struct node*)malloc(sizeof(struct node));
              printf("Enter the value \n");
              scanf("%d",&newnode->data);
              tree->rlink=newnode;
              newnode->llink=NULL;
              newnode->rlink = NULL;
              create(tree->rlink);
          }
          else {
              tree->rlink= NULL;
          }
       }



       void inorder(struct node* tree)
       {
           if(tree)
           {
               inorder(tree->llink);
               printf("%d  ",tree->data);
               inorder(tree->rlink);
           }
       }


       void preorder(struct node* tree)
       {
           if(tree)
           {
               printf("%d  ",tree->data);
               preorder(tree->llink);
               preorder(tree->rlink);
           }
       }


       void postorder(struct node* tree)
       {
           if(tree)
           {
               postorder(tree->llink);
               postorder(tree->rlink);
               printf("%d  ",tree->data);
           }
       }

       
       void main()
       {
           struct node *root;
           root = (struct node*)malloc(sizeof(struct node));
           printf("Enter the root node \n");
           scanf("%d",&root ->data);
           create (root);
           printf("\n Inorder \n");
           inorder(root);
           printf("\n Preorder \n");
           preorder(root);
           printf("\n Postorder \n");
           postorder(root);
       }