//indirect recursion

#include<stdio.h>
#include<conio.h>

void f1(int);
void f2(int);

void main()
{
    f1(5);
    printf("\n\n");
    getch();
}

void f1(int data)
{
    if(data<20)
    {
        printf("\n f1=%d",data);
        f2(data+2);
    }
}

void f2(int data)
{
    if(data<20)
    {
        printf("\n f2=%d",data);
        f1(data+3);
    }
}
