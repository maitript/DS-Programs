 #include<stdio.h>
 #include<ctype.h>
 #define SIZE 50
 int st[SIZE];
 int top=-1;
 void push(char elem)
 {
     st[++top]=elem;
 }
 char pop()
 {
     return st[top--];
 }
 int priority(char symbol)
 {
     if(symbol=='^')
     return (3);
     else if(symbol=='*' || symbol=='/')
     return (2);
     else if(symbol=='+' || symbol=='-')
     return (1) ;
     else
     return (0);
 }
 void main()
 {
     char infix[50],pofx[50],ch,temp;
     printf("\nEnter a valid infix expression");
     scanf("%s",infix);
     int i=0,k=0;
     push('#');
     while((ch=infix[i++])!='\0')
     {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            pofx[k++]=ch;
        }
        else if(ch==')')
        {
            while(st[top]!='(')
            {
                pofx[k++]=pop();
            }
            temp=pop();
        }
        else
        {
            while(priority(st[top])>=priority(ch))
            {
              pofx[k++]=pop(); 
            }
            push(ch);
        }
     }
     while(st[top]!='#')
     {
         pofx[k++]=pop();
     }
     pofx[k]='\0';
	printf("The postfix expression is:\n");
     printf("%s\n",pofx);
 }
 