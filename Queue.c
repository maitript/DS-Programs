#include <stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue();
void dequeue();
void display();

int rear=-1;
int front=-1;
int q[MAX];

void main()
{
    int n;
   while(1)
   {
       printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
       printf("Enter your choice: ");
       scanf("%d",&n);
       switch(n)
       {
           case 1: enqueue();
                break;
                
            case 2: dequeue();
                 break;
                 
            case 3: display();
                    break;
                    
            case 4: exit(0);
            
            default:printf("invalid");
       }
   }

    
}

void enqueue()
{
    int item;
    printf("enter item to be inserted");
    scanf("%d",&item);
    if(front==-1 && rear==-1)
    {
      front=0;
      rear=0;
      q[rear]=item;
    }
    else if(rear==MAX-1)
    {
        printf("queue is full");
    }
    else 
    {
        rear++;
        q[rear]=item;
    }
}


void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("empty");
    }
    else if(front==rear)
    {
        printf("deleted item is %d",q[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("deleted item is %d",q[front]);
        front++;
    }
}

void display()
{
    int i;
    i=rear;
    if(front==-1 && rear==-1)
    {
        printf("empty");
    }
    else
    {
     for(i=front;i<=rear;i++)
     {
         printf("%d ",q[i]);
     }
    }
}