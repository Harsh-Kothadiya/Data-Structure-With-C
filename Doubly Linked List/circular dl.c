/*
Define a Circular Doubly linked list with following services
a. Insert list item as first node
b. Insert list item as last node
c. Delete first list item
d. Delete last list item
e. View all list elements
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *prev;
    struct node *next;
};
//LPTR : left to right direction traval
//RPTR : right to left direction traval
struct node *LPTR=NULL;
struct node *RPTR=NULL;

void insertFirst(int);
void insertFirstWithLPTR(int);
void insertFirstWithRPTR(int);

void insertLast(int);
void insertLastWithLPTR(int);
void insertLastWithRPTR(int);


void deleteFirst();
void deleteFirstWithLPTR();
void deleteFirstWithRPTR();

void deleteLast();
void deleteLastWithLPTR();
void deleteLastWithRPTR();

void view();
void viewWithLPTR();
void viewWithRPTR();

void count();

void main()
{
   int choice;
   int no;
   int n1,n2;
   do
   {
       printf("\n\n\t ENTER-1 : INSERT LIST ITEM AS FIRST NODE");
       printf("\n\n\t ENTER-2 : INSERT LIST ITEM AS LAST NODE");

       printf("\n\n\t ENTER-3 : DELETE FIRST LIST ITEM");
       printf("\n\n\t ENTER-4 : DELETE LAST LIST ITEM");

       printf("\n\n\t ENTER-5: VIEW ALL LIST ELEMENTS");
       printf("\n\n\t ENTER-6 : COUNT TOTAL NODE");
       printf("\n\n\t ENTER-7 : EXIT");

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
                deleteFirst();
                break;
            case 4 :
                deleteLast();
                break;
            case 5 :
                view();
                break;
            case 6 :
                count();
                break;
            case 7 :
                break;
            default :
                printf("\n\nIN VALIED CHOICE...\n\n");
                break;
       }
   }while(choice!=7);
   printf("\n\n");

getch();
}

void insertFirst(int data)
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :
            insertFirstWithLPTR(data);
            break;
        case 2 :
            insertFirstWithRPTR(data);
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }
}
void insertFirstWithLPTR(int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->item=data;
    tmp->prev=NULL;
    tmp->next=NULL;

    if(LPTR==NULL)
    {
        LPTR=tmp;
        RPTR=tmp;
        tmp->prev=tmp;
        tmp->next=tmp;
    }
    else
    {
        tmp->prev=RPTR;
        tmp->next=LPTR;
        LPTR->prev=tmp;
        LPTR=tmp;
        RPTR->next=tmp;
    }
}
void insertFirstWithRPTR(int data)
{
   struct node *tmp;
   tmp=(struct node*)malloc(sizeof(struct node));
   tmp->item=data;
   tmp->prev=NULL;
   tmp->next=NULL;

   if(RPTR==NULL)
   {
       RPTR=tmp;
       LPTR=tmp;
       tmp->prev=tmp;
       tmp->next=tmp;
   }
   else
   {
       tmp->prev=RPTR;
       tmp->next=LPTR;
       LPTR->prev=tmp;
       RPTR->next=tmp;
       RPTR=tmp;
   }
}

void insertLast(int data)
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            insertLastWithLPTR(data);
            break;
        case 2 :
            insertLastWithRPTR(data);
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }
}
void insertLastWithLPTR(int data)
{
    struct node *tmp;
    struct node *traval;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->item=data;
    tmp->prev=NULL;
    tmp->next=NULL;

    if(LPTR==NULL)
    {
        LPTR=tmp;
        RPTR=tmp;
        tmp->prev=tmp;
        tmp->next=tmp;

    }
    else
    {
        tmp->prev=RPTR;
        tmp->next=LPTR;
        LPTR->prev=tmp;
        RPTR->next=tmp;
        RPTR=tmp;
    }
}
void insertLastWithRPTR(int data)
{
   struct node *tmp;
   struct node *traval;
   tmp=(struct node*)malloc(sizeof(struct node));
   tmp->item=data;
   tmp->prev=NULL;
   tmp->next=NULL;

   if(RPTR==NULL)
   {
       RPTR=tmp;
       LPTR=tmp;
       tmp->prev=tmp;
       tmp->next=tmp;

   }
   else
   {
       tmp->prev=RPTR;
       tmp->next=LPTR;
       LPTR->prev=tmp;
       RPTR->next=tmp;
       LPTR=tmp;
   }
}

void deleteFirst()
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            deleteFirstWithLPTR();
            break;
        case 2 :
            deleteFirstWithRPTR();
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }

}
void deleteFirstWithLPTR()
{
    struct node *delp;
    if(LPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        delp=LPTR;
        if(delp->prev==delp->next)//only for one node
            LPTR=RPTR=NULL;
        else//two or more node
        {
            LPTR->next->prev=LPTR->prev;
            RPTR->next=LPTR->next;
            LPTR=LPTR->next;
        }
        free(delp);
    }
}
void deleteFirstWithRPTR()
{
    struct node *delp;
    if(RPTR==NULL) // no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        delp=RPTR;
        if(delp->prev==delp->next)//only for one node
            LPTR=RPTR=NULL;
        else//two or more node
        {
            RPTR=RPTR->prev;
            RPTR->next=LPTR;
            LPTR->prev=RPTR;
        }
        free(delp);
    }
}

void deleteLast()
{
     int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            deleteLastWithLPTR();
            break;
        case 2 :
            deleteLastWithRPTR();
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }

}
void deleteLastWithLPTR()
{
    struct node *delp;
    if(LPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
     else
    {
        delp=RPTR;
        if(delp->prev==delp->next)//only for one node
            LPTR=RPTR=NULL;
        else//two or more node
        {
            RPTR=RPTR->prev;
            RPTR->next=LPTR;
            LPTR->prev=RPTR;
        }
        free(delp);
    }
}
void deleteLastWithRPTR()
{
    struct node *delp;
    if(RPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        delp=LPTR;
        if(delp->prev==delp->next)//only for one node
            LPTR=RPTR=NULL;
        else//two or more node
        {
            LPTR->next->prev=LPTR->prev;
            RPTR->next=LPTR->next;
            LPTR=LPTR->next;
        }
        free(delp);
    }
}
void view()
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            viewWithLPTR();
            break;
        case 2 :
            viewWithRPTR();
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }

}
void viewWithLPTR()
{
    struct node *tmp;
    if(LPTR==NULL)
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        tmp=LPTR;
        printf("\n\n");
        while(1)
        {
            printf("%d\t",tmp->item);
            if(tmp->next==LPTR)
                break;
            tmp=tmp->next;
        }
        printf("\n\n");
    }
}
void viewWithRPTR()
{
    struct node *tmp;
    if(RPTR==NULL)
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        tmp=RPTR;
        printf("\n\n");
        while(1)
        {
            printf("%d\t",tmp->item);
            if(tmp->prev==RPTR)
                break;
            tmp=tmp->prev;
        }
        printf("\n\n");
    }
}
void count()
{
    struct node *traval;
    int Count=0;
    if(LPTR==NULL || RPTR==NULL)
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else
    {
        traval=LPTR;
        while(1)
        {
            Count++;
            if(traval->next==LPTR)
                break;
            traval=traval->next;
        }
        printf("\n\n TOTAL NODE PRESENT IN DOUBLY LINKED LIST : %d\n\n",Count);
    }
}
