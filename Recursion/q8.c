/*
write a recursive function to calculate sum of first n even natural numbers.
*/

#include<stdio.h>
#include<conio.h>

int fun(int n)
{
    if(n==2)
        return 2;
    else
        return n+fun(n-2);
}

void main()
{
    int n;
    printf("\n\n ENTER ANY  NATURAL NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    int sum=fun(n*2);
    printf("\nSUM=%d",sum);
    printf("\n\n");
    getch();
}


