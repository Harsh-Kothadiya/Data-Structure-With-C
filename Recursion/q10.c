/*
write a recursive function to calculate sum of squares of  first n natural numbers.
*/

#include<stdio.h>
#include<conio.h>

int fun(int n)
{
    if(n==1)
        return 1;
    else
        return ( (n*n)+fun(n-1) );
}

void main()
{
    int n;
    printf("\n\n ENTER ANY  NATURAL NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    int sum=fun(n);
    printf("\nSUM=%d",sum);
    printf("\n\n");
    getch();
}


