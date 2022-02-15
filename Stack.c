#include <stdio.h>
#define stacksize 10
#include<stdlib.h>


int top=-1;
int s[stacksize];

void push()
{
    int item;
    if(top==stacksize-1)
    printf("Stack overflow\n");
    else
    {
        printf("enter item");
        scanf("%d",&item);
        ++top;
        s[top]=item;
    }
}

void pop()
{
    int delit;
    if(top==-1)
    printf("stack underflow\n");
    else
    {
        delit=s[top];
        --top;
    }
    
}

void display()
{
    int i;
    if(top==-1)
    printf("stack underflow\n");
    else
    {
        for(i=top;i>=0;i--)
        printf("%d\n",s[i]);
    }
}

void main()
{
    int n;
 
    while(1)
{
   
           printf("Enter 1.Push  2.Pop  3.Display  4.Exit\n");
              printf("Enter your choice: ");
             scanf("%d",&n);
              switch(n)
    {
        case 1: push();
            break;
        
        case 2: pop();
              break;
              
        case 3: display();
              break;
              
        case 4: exit(0);
        
        default:printf("Invalid choice\n");
        
    }
}

}