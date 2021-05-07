/*
Define linked list with following services
a. Insert list item as first node
b. Insert list item as last node
c. Insert list item after a given node
d. Delete first list item
e. Delete last list item
f. Delete a particular node
g. View all list elements
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};
struct node *Start=NULL;

void insertFirst(int);
void insertLast(int);
void insertGivenNode(int,int);
void deleteFirst();
void deleteLast();
void deleteGivenNde(int);
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
       printf("\n\n\t ENTER-1 : INSERT LIST ITEM AS FIRST NODE");
       printf("\n\n\t ENTER-2 : INSERT LIST ITEM AS LAST NODE");
       printf("\n\n\t ENTER-3 : INSERT LIST ITEM AFTER A GIVEN NODE");
       printf("\n\n\t ENTER-4 : DELETE FIRST LIST ITEM");
       printf("\n\n\t ENTER-5 : DELETE LAST LIST ITEM");
       printf("\n\n\t ENTER-6 : DELETE A PARTICULAR NODE");
       printf("\n\n\t ENTER-7 : VIEW ALL LIST ELEMENTS");
       printf("\n\n\t ENTER-8 : COUNT TOTAL NODE");
       printf("\n\n\t ENTER-9 : EXIT");

       printf("\n\n\n\t ENTER YOUR CHOICE : ");
       scanf("%d",&choice);

       switch(choice)
       {
            case 1 :
                printf("\n\n\t ENTER NUMBER : ");
                scanf("%d",&no);
                insertFirst(no);
                break;
            case 2 :
                printf("\n\n\t ENTER NUMBER : ");
                scanf("%d",&no);
                insertLast(no);
                break;
            case 3 :
                printf("\n\n\t ENTER NUMBER IN LIST : ");
                scanf("%d",&n1);
                printf("\n\n\t ENTER ANY NUMBER : ");
                scanf("%d",&n2);
                insertGivenNode(n1,n2);
                break;
            case 4 :
                deleteFirst();
                break;
            case 5 :
                deleteLast();
                break;
            case 6 :
                printf("\n\n\t ENTER NUMBER : ");
                scanf("%d",&no);
                deleteGivenNde(no);
                break;
            case 7 :
                view();
                break;
            case 8 :
                count();
                break;
            case 9 :
                break;
            default :
                printf("\n\nIN VALIED CHOICE...\n\n");
                break;
       }
   }while(choice!=9);
   printf("\n\n");

getch();
}

void insertFirst(int val)
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

void insertLast(int val)
{
    struct node *traval;
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->item=val;
    tmp->next=NULL;
    if(Start == NULL )
        Start=tmp;
    else
    {
        traval=Start;
        while(1)
        {
            if(traval->next==NULL)
                break;

            traval=traval->next;
        }
        traval->next=tmp;
    }
    Count++;
}

void insertGivenNode(int val1,int val2)
{
    struct node *traval;
    struct node *lastNode;
    int c1=0;
    int c2=0;
    int ch;
    int i;
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->item=val2;
    tmp->next=NULL;

    if( Start == NULL )
    {
        Start=tmp;
        Count++;
    }
    else
    {
        traval=Start;
        while( traval!=NULL )
        {
            if( traval->item == val1 )
                c1++;

            lastNode=traval;
            traval=traval->next;
        }

        if( c1>0 )
        {
            for(i=1;i<=c1;i++)
            {
                printf("\n\n\t ENTER %d MEANS VALUE %d TIME FIND AFTER INSERTION",i,i);
            }
            printf("\n\n\t ENTER YOUR CHOICE : ");
            scanf("%d",&ch);

            traval=Start;
            while(1)
            {
                if( traval->item == val1 )
                c2++;

                if( c2 == ch )
                {
                    tmp->next=traval->next;
                    traval->next=tmp;
                    break;
                }
                traval=traval->next;
            }
        }
        else
        {
            lastNode->next=tmp;
        }
        Count++;
    }
}

void deleteFirst()
{
    struct node *delp; //delp : delete node address contain
   if( Start == NULL )
        printf("\n\nLIST EMPTY...\n\n");
   else
   {
       delp=Start;
       Start=Start->next;
       free(delp);
       Count--;
   }
}

void deleteLast()
{
    struct node *traval;
    struct node *delp;
   if( Start == NULL )
        printf("\n\nLIST EMPTY...\n\n");
   else if( Start->next == NULL )
   {
       delp=Start;
       Start=NULL;
       free(delp);
       Count--;
   }
   else
   {
       delp=Start;
       while(1)
       {
           if( delp->next == NULL )
            break;
           traval=delp;
           delp=delp->next;
       }
       free(delp);
       traval->next=NULL;
       Count--;
   }
}

void deleteGivenNde(int val)
{
   struct node *traval;
   struct node *preTraval;
   int c1=0;
   int ch;
   int c2=0;
   int i;
   int x=1;

   if( Start == NULL )
    printf("\n\n LIST EMPTY...\n\n");
   else if( (Start->item==val)&&(Start->next==NULL) )
   {
        traval=Start;
        Start=NULL;
        Count--;
        free(traval);
   }
   else
   {
       traval=Start;
       while(traval!=NULL)
       {
           if( traval->item == val )
              c1++;
           traval=traval->next;
       }
       if(c1>0)
       {
           for(i=1;i<=c1;i++)
           {
               printf("\n\n\t ENTER %d MEANS VALUE %d TIME FIND AND DELETION THIS VALUE NODE",i,i);
           }
           printf("\n\n\t ENTER YOUR CHOICE : ");
           scanf("%d",&ch);
           traval=Start;
           while(1)
           {
               if(traval->item==val)
                c2++;
               if(c2==ch)
               {
                   if( (Start->item==val)&&(x==1)&&(c2==1) )
                   {
                       Start=Start->next;
                       break;
                   }
                   else
                   {
                       preTraval->next=traval->next;
                       break;
                   }
               }
               preTraval=traval;
               traval=traval->next;
           }
           Count--;
           free(traval);
       }
       else
       {
           printf("\n\nDELETION NOT POSSIBLE...\n\n");
       }

   }
}
void view()
{
   struct node *tmp;
   int i;
   if(Start == NULL )
    printf("\n\n LIST EMPTY...\n\n");
   else
   {
       tmp=Start;
       printf("\n\n");
       while(1)
       {
           printf("%d\t",tmp->item);
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
        printf("\n\n LIST EMPTY...\n\n");
    else
        printf("\n\n TOTAL NODE IN LIST : %d\n\n",Count);
}
