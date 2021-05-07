/*
write a recursive function to calculate sum of digits of a given numbers.
*/

#include<stdio.h>
#include<conio.h>

int fun(int n)
{
    int t;
   if(n>0)
    {
      t=n%10;
      n=n/10;
      return t+fun(n);
    }
}


void main()
{
    int n;
    printf("\n\n ENTER  NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    int sum=fun(n);
    printf("\nSUM=%d",sum);
    printf("\n\n");
    getch();
}


