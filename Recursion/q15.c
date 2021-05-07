/*
write a recursive function to find nth term of a fibonacci series.
*/

#include<stdio.h>
#include<conio.h>
int t1,t2,t3;
void fun(int n)
{
  if(n>2)
  {
      fun(n-1);
      t3=t1+t2;
      t1=t2;
      t2=t3;
      printf("%d\t",t3);
  }
  if(n==2)
  {
      t1=0;
      t2=1;
      printf("%d\t%d\t",t1,t2);
  }
}


void main()
{
    int n;
    printf("\n\n ENTER  NUMBER : ");
    scanf("%d",&n);
    printf("\n\n");
    fun(n);

    printf("\n\n");
    getch();
}


