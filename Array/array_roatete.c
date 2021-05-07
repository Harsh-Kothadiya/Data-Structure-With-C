/*
write a function that rotates A[] of size n by d elements in given direction(-1 for left & +1 for right)

void rotate(int A[],int n,int dir)
*/
#include<stdio.h>
#include<conio.h>
void rotate(int A[],int n,int dir);
void main()
{
    int n;
    printf("\n\n\tENTER ARRAY SIZE : ");
    scanf("%d",&n);
    int A[n];
    int i;
    int choice;
    printf("\n\n\t ENTER %d ELEMENT\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n\n------ARRAY ELEMENT--------\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n\n---------------------------\n");
    printf("\n\n\t ENTER:1    RIGHT ROTATE");
    printf("\n\n\t ENTER:(-1) LEFT  ROTATE");
    printf("\n\n\t ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    rotate(A,n,choice);
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n\n");
    getch();
}
void rotate(int A[],int n,int dir)
{
    int tmp;
    int i;
    if(dir==1)
    {
        printf("\n\n right rotate\n\n");
        tmp=A[n-1];
        for(i=n-1;i>=1;i--)
            A[i]=A[i-1];

        A[0]=tmp;
    }
    if(dir==-1)
    {
        printf("\n\nleft rotate\n\n");
        tmp=A[0];
        for(i=0;i<n-1;i++)
            A[i]=A[i+1];

        A[n-1]=tmp;
    }
}
