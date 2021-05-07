//Tower of hanoi

#include<stdio.h>
#include<conio.h>
int count=1;
void TOH(int n,char BEG,char AUX,char END)
{
    if(n>0)
    {
        TOH(n-1,BEG,END,AUX);
        printf("\n%d) %c --> %c",count,BEG,END);
        count++;
        TOH(n-1,AUX,BEG,END);
    }
}
void main()
{
    int n;
    printf("\n\n ENTER ANY  NATURAL NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    TOH(n,'A','B','C');
    printf("\n\n");
    getch();
}
