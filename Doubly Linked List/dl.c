/*
Define a Doubly linked list with following services
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

void insertGivenNode(int,int);
void insertGivenNodeWithLPTR(int,int);
void insertGivenNodeWithRPTR(int,int);

void deleteFirst();
void deleteFirstWithLPTR();
void deleteFirstWithRPTR();

void deleteLast();
void deleteLastWithLPTR();
void deleteLastWithRPTR();

void deleteGivenNode(int);
void deleteGivenNodeWithLPTR(int);
void deleteGivenNodeWithRPTR(int);

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
                deleteGivenNode(no);
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
    }
    else
    {
        LPTR->prev=tmp;
        tmp->next=LPTR;
        LPTR=tmp;
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
   }
   else
   {
       RPTR->next=tmp;
       tmp->prev=RPTR;
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
    }
    else
    {
        traval=LPTR;
        while(traval->next!=NULL)
            traval=traval->next;

        traval->next=tmp;
        tmp->prev=traval;
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
   }
   else
   {
       traval=RPTR;
       while(traval->prev!=NULL)
        traval=traval->prev;

       traval->prev=tmp;
       tmp->next=LPTR;
       LPTR=tmp;
   }
}

void insertGivenNode(int ln,int en) // ln : list number & en : enter number
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            insertGivenNodeWithLPTR(ln,en);
            break;
        case 2 :
            insertGivenNodeWithRPTR(ln,en);
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }
}
void insertGivenNodeWithLPTR(int ln,int en)
{
   struct node *traval;
   struct node *tmp;
   int c1=0,c2=0;
   int ch;
   int i;
   tmp=(struct node*)malloc(sizeof(struct node));
   tmp->item=en;
   tmp->prev=NULL;
   tmp->next=NULL;
   if(LPTR==NULL)
   {
       LPTR=tmp;
       RPTR=tmp;
   }
   else
   {
       traval=LPTR;
       while(traval!=NULL)
       {
           if(traval->item==ln)
              c1++;
           traval=traval->next;
       }
       if(c1>0)
       {
          for(i=1;i<=c1;i++)
            printf("\n\t ENTER : %d MEANS %d TIMES VALUE FIND AND AFTER ENTER NEW VALUE ",i,i);
        printf("\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        traval=LPTR;
        while(traval!=NULL)
        {
            if(traval->item==ln)
                c2++;
            if(c2==ch)
            {
                if(traval->next==NULL)
                {
                    tmp->prev=traval;
                    traval->next=tmp;
                    RPTR=tmp;
                }
                else
                {
                    tmp->prev=traval;
                    tmp->next=traval->next;
                    traval->next->prev=tmp;
                    traval->next=tmp;
                }

                break;
            }
            traval=traval->next;
        }

       }
       else
       {
            tmp->prev=RPTR;
            RPTR->next=tmp;
            RPTR=tmp;
       }
   }
}
void insertGivenNodeWithRPTR(int ln,int en)
{
   struct node *traval;
   struct node *tmp;
   int c1=0,c2=0;
   int i;
   int ch;
   tmp=(struct node*)malloc(sizeof(struct node));
   tmp->item=en;
   tmp->prev=NULL;
   tmp->next=NULL;
   if(RPTR==NULL)
   {
      RPTR=tmp;
      LPTR=tmp;
   }
   else
   {
       traval=RPTR;
       while(traval!=NULL)
       {
           if(traval->item==ln)
              c1++;
           traval=traval->prev;
       }
       if(c1>0)
       {
          for(i=1;i<=c1;i++)
            printf("\n\t ENTER : %d MEANS %d TIMES VALUE FIND AND AFTER ENTER NEW VALUE ",i,i);
        printf("\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        traval=RPTR;
        while(traval!=NULL)
        {
            if(traval->item==ln)
                c2++;
            if(c2==ch)
            {
                if(traval->prev==NULL)
                {
                    tmp->next=traval;
                    traval->prev=tmp;
                    LPTR=tmp;
                }
                else
                {
                    tmp->prev=traval->prev;
                    tmp->next=traval;
                    traval->prev->next=tmp;
                    traval->prev=tmp;
                }

                break;
            }
            traval=traval->prev;
        }

       }
       else
       {
            tmp->next=LPTR;
            LPTR->prev=tmp;
            LPTR=tmp;
       }
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
    struct node *traval;
    if(LPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else if(LPTR->next==NULL)//only for one node
    {
        traval=LPTR;
        LPTR=RPTR=NULL;
        free(traval);
    }
    else//two or more node
    {
        traval=LPTR;
        traval->next->prev=NULL;
        LPTR=traval->next;
        free(traval);
    }
}
void deleteFirstWithRPTR()
{
    struct node *traval;
    if(RPTR==NULL) // no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else if(RPTR->prev==NULL) //only for one node
    {
        traval=RPTR;
        RPTR=LPTR=NULL;
        free(traval);
    }
    else// two or more node
    {
        traval=RPTR;
        traval->prev->next=NULL;
        RPTR=traval->prev;
        free(traval);
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
    struct node *traval;
    if(LPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else if(LPTR->next==NULL)//only one node
    {
        traval=LPTR;
        LPTR=RPTR=NULL;
        free(traval);
    }
    else//two or more node
    {
        traval=RPTR;
        RPTR=RPTR->prev;
        RPTR->next=NULL;
        free(traval);
    }
}
void deleteLastWithRPTR()
{
    struct node *traval;
    if(RPTR==NULL)//no node
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
    else if(RPTR->prev==NULL)//only one node
    {
        traval=RPTR;
        RPTR=LPTR=NULL;
        free(traval);
    }
    else//two or more node
    {
        traval=LPTR;
        LPTR=LPTR->next;
        LPTR->prev=NULL;
        free(traval);
    }
}
void deleteGivenNode(int ln) // ln : list number
{
    int ch;
    printf("\n\n\t ENTER-1 : LEFT  TO RIGHT DIRECTION");
    printf("\n\n\t ENTER-2 : RIGHT TO LEFT  DIRECTION");
    printf("\n\n\t ENTER YOUR CHOICE 1 OR 2 : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            deleteGivenNodeWithLPTR(ln);
            break;
        case 2 :
            deleteGivenNodeWithRPTR(ln);
            break;
        default :
            printf("\n\n\t IN_VALIED CHOICE...");
            break;
    }
}
void deleteGivenNodeWithLPTR(int ln)
{
   struct node *traval,*preTraval;
   int c1=0,c2=0;
   int ch;
   int i;

   if(LPTR==NULL)
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
   else
   {
       traval=LPTR;
       while(traval!=NULL)
       {
           if(traval->item==ln)
              c1++;
           traval=traval->next;
       }
       if(c1>0)
       {
          for(i=1;i<=c1;i++)
            printf("\n\t ENTER : %d MEANS %d TIMES VALUE FIND  ",i,i);
        printf("\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        preTraval=NULL;
        traval=LPTR;
        while(traval!=NULL)
        {
            if(traval->item==ln)
                c2++;
            if(c2==ch)
            {
                if(traval->prev==NULL)
                {
                   traval=LPTR;
                   LPTR=LPTR->next;
                   if(LPTR==NULL)
                     RPTR=NULL;
                    else
                        LPTR->prev=NULL;
                }
                else if(traval->next==NULL)
                {
                    traval=RPTR;
                    RPTR=RPTR->prev;
                    if(RPTR==NULL)
                        LPTR=NULL;
                    else
                        RPTR->next=NULL;
                }
                else
                {
                    preTraval->next=traval->next;
                    traval->next->prev=preTraval;
                }
                free(traval);
                break;
            }
            preTraval=traval;
            traval=traval->next;
        }

       }
       else
         printf("\n\n DELETION NOT POSSIBLE IN DOUBLY LINKED LIST...\n\n");
   }
}
void deleteGivenNodeWithRPTR(int ln)
{
   struct node *traval,*preTraval;
   int c1=0,c2=0;
   int i;
   int ch;

   if(RPTR==NULL)
        printf("\n\n DOUBLY LINKED LIST IS EMPTY...\n\n");
   else
   {
       traval=RPTR;
       while(traval!=NULL)
       {
           if(traval->item==ln)
              c1++;
           traval=traval->prev;
       }
       if(c1>0)
       {
          for(i=1;i<=c1;i++)
            printf("\n\t ENTER : %d MEANS %d TIMES VALUE FIND  ",i,i);
        printf("\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        preTraval=NULL;
        traval=RPTR;
        while(traval!=NULL)
        {
            if(traval->item==ln)
                c2++;
            if(c2==ch)
            {
               if(traval->next==NULL)
               {
                    traval=RPTR;
                    RPTR=RPTR->prev;
                    if(RPTR==NULL)
                        LPTR=NULL;
                    else
                        RPTR->next=NULL;
               }
               else if(traval->prev==NULL)
               {
                   traval=LPTR;
                   LPTR=LPTR->next;
                   if(LPTR==NULL)
                    RPTR=NULL;
                   else
                    LPTR->prev=NULL;
               }
               else
               {
                   preTraval->prev=traval->prev;
                   traval->prev->next=preTraval;
               }
               free(traval);

                break;
            }
            preTraval=traval;
            traval=traval->prev;
        }

       }
       else
        printf("\n\n DELETION NOT POSSIBLE IN DOUBLY LINKED LIST...\n\n");
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
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->item);
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
        while(tmp!=NULL)
        {
            printf("%d\t",tmp->item);
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
        while(traval!=NULL)
        {
            Count++;
            traval=traval->next;
        }
        printf("\n\n TOTAL NODE PRESENT IN DOUBLY LINKED LIST : %d\n\n",Count);
    }
}
