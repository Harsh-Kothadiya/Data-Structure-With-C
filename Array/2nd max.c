//Find second largest elements in the array.
// int secondLargest(int A[],int size)

#include<stdio.h>
#include<conio.h>

int secondLargest(int A[],int size);

void main()
{
    int s;
    printf("\n\n\tENTER ARRAY SIZE : ");
    scanf("%d",&s);
    int A[s];
    int i;
    printf("\n\n\t ENTER %d ELEMENT\n",s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n\n------ARRAY ELEMENT--------\n");
    for(i=0;i<s;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n\n---------------------------\n");
    int sl=secondLargest(A,s);
    printf("\n\n 2nd MAX VALUE IS : %d",sl);
    getch();
}

int secondLargest(int A[],int size)
{
    int i,j,tmp=0;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if( A[j] > A[j+1] )
            {
                tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
            }
        }
    }

    return A[size-2];
}
