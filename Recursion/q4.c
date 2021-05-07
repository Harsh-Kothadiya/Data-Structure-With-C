/*
write a recursive function to print first n even natural numbers in reverse order.
*/

#include<stdio.h>
#include<conio.h>

void fun(int n)
{
    if(n>1)
    {
        if(n%2==0)
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
    fun(n*2);
    printf("\n\n");
    getch();
}


