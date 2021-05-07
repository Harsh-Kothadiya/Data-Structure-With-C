/*
write a recursive function to print first n natural numbers.
*/

#include<stdio.h>
#include<conio.h>

void fun(int n)
{
    if(n==1)
        printf("1\t");
    else
    {
        fun(n-1);
        printf("%d\t",n);
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
