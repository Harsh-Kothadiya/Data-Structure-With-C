/*
write a recursive function to print reverse of a given number.
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
int rev=0;
int t;
void fun(int n)
{
    if(n>0)
    {
        t=n%10;
        n=n/10;
        rev=(rev*10)+t;
        fun(n);
    }
}


void main()
{
    int n;
    printf("\n\n ENTER  NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    fun(n);
    printf("\n reverse number=%d",rev);
    printf("\n\n");
    getch();
}


