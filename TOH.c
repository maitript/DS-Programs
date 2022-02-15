#include <stdio.h>
 
int towers(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("\n Move disk %d from peg %c to peg %c",n,s,d);
        return 0;
    }
    towers(n - 1,s,d,t);
    printf("\n Move disk %d from peg %c to peg %c", n,s,d);
    towers(n - 1, t, s,d);
}
 
int main()
{
    int n;
 
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(n, 'A', 'B', 'C');
    return 0;
}
