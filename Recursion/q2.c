/*
write a recursive function to print first n natural numbers in reverse order.
*/

#include<stdio.h>
#include<conio.h>

void fun(int n)
{
    if(n==1)
        printf("1\t");
    else
    {
        printf("%d\t",n);
        fun(n-1);
    }
}
void main()
{
    int n;
    printf("\n\n ENTER ANY  NATURAL NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    fun(n);
    printf("\n\n");
    getch();
}

