//implement Stack using linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};
struct node *Start=NULL;

void PUSH(int);
void POP();
void PEEK();
void view();
void count();
int Count=0;

void main()
{
   int choice;
   int no;
   int n1,n2;
   do
   {
       printf("\n\n\t ENTER-1 : PUSH");
       printf("\n\n\t ENTER-2 : POP");
       printf("\n\n\t ENTER-3 : PEEK");
       printf("\n\n\t ENTER-4 : VIEW");
       printf("\n\n\t ENTER-5 : COUNT TOTAL NODE");
       printf("\n\n\t ENTER-6 : EXIT");

       printf("\n\n\n\t ENTER YOUR CHOICE : ");
       scanf("%d",&choice);

       switch(choice)
       {
            case 1 :
                printf("\n\n\t ENTER NUMBER : ");
                scanf("%d",&no);
                PUSH(no);
                break;
            case 2 :
                POP();
                break;
            case 3 :
                PEEK();
                break;
            case 4 :
               view();
                break;
            case 5 :
               count();
                break;
           case 6 :
                break;
            default :
                printf("\n\nIN VALIED CHOICE...\n\n");
                break;
       }
   }while(choice!=6);
   printf("\n\n");

getch();
}

void PUSH(int val)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->item=val;
    tmp->next=NULL;

    if(Start == NULL )
        Start=tmp;
    else
    {
        tmp->next=Start;
        Start=tmp;
    }
    Count++;
}
void POP()
{
    struct node *delp; //delp : delete node address contain
   if( Start == NULL )
        printf("\n\nUNDER_FLOW...\n\n");
   else
   {
       delp=Start;
       Start=Start->next;
       free(delp);
       Count--;
   }
}
void PEEK()
{
  if(Start == NULL )
    printf("\n\n UNDER_FLOW...\n\n");
   else
       printf("\n\nPEEK VALUE IS : %d",Start->item);

    printf("\n\n");
}
void view()
{
   struct node *tmp;
   int i;
   if(Start == NULL )
    printf("\n\n UNDER_FLOW...\n\n");
   else
   {
       tmp=Start;
       printf("\n\n");
       while(1)
       {
           printf("%d\n",tmp->item);
           if(tmp->next == NULL )
            break;
           tmp=tmp->next;
       }
       printf("\n\n");
   }
}
void count()
{
    if(Start == NULL )
        printf("\n\n UNDER_FLOW...\n\n");
    else
        printf("\n\n TOTAL NODE IN LIST : %d\n\n",Count);
}
