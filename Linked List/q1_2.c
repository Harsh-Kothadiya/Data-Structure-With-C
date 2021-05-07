//student data : roll number,first name,last name
//Singly linked list
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
#include<string.h>
struct student
{
  int roll;
  char fname[10];
  char lname[10];
};
//item means : struct student na data
struct node
{
    struct student *stu;
    struct node *next;
};
struct node *Start=NULL;

void insertFirst(int,char [],char []);
void insertLast(int,char [],char []);
void insertGivenNode(int,int,char [],char []);
void deleteFirst();
void deleteLast();
void deleteGivenNode(int);
void view();
void count();
int Count=0;

void main()
{
   int choice;
   int no;
   int r;
   char fn[10],ln[10];
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
                printf("\n\n\t ENTER STUDENT DATA \n\n");
                printf("\n\n\t ENTER ROLL NUMBER : ");
                scanf("%d",&r);
                printf("\n\t ENTER FIRST NAME : ");
                scanf("%s",fn);
                printf("\n\t ENTER LAST NAME : ");
                scanf("%s",ln);
                insertFirst(r,fn,ln);
                break;
            case 2 :
                printf("\n\n\t ENTER STUDENT DATA \n\n");
                printf("\n\n\t ENTER ROLL NUMBER : ");
                scanf("%d",&r);
                printf("\n\t ENTER FIRST NAME : ");
                scanf("%s",fn);
                printf("\n\t ENTER LAST NAME : ");
                scanf("%s",ln);
                insertLast(r,fn,ln);
                break;
            case 3 :
                printf("\n\n\t ENTER ROLL NUMBER IN LIST : ");
                scanf("%d",&n1);
                printf("\n\n\t ENTER ANY ROLL NUMBER : ");
                scanf("%d",&n2);
                printf("\n\t ENTER FIRST NAME : ");
                scanf("%s",fn);
                printf("\n\t ENTER LAST NAME : ");
                scanf("%s",ln);
                insertGivenNode(n1,n2,fn,ln);
                break;
            case 4 :
                deleteFirst();
                break;
            case 5 :
                deleteLast();
                break;
            case 6 :
                printf("\n\n\t ENTER ROLL NUMBER : ");
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

void insertFirst(int r,char fn[],char ln[])
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->stu=(struct student*)malloc(sizeof(struct student));
    tmp->stu->roll=r;
    strcpy(tmp->stu->fname,fn);
    strcpy( tmp->stu->lname,ln);
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
void insertLast(int r,char fn[],char ln[])
{
    struct node *traval;
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->stu=(struct student*)malloc(sizeof(struct student));
    tmp->stu->roll=r;
    strcpy(tmp->stu->fname,fn);
    strcpy( tmp->stu->lname,ln);
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

void insertGivenNode(int oldR,int newR,char fn[],char ln[])
{
    struct node *traval;
    struct node *lastNode;
    int c1=0;
    int c2=0;
    int ch;
    int i;
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->stu=(struct student*)malloc(sizeof(struct student));
    tmp->stu->roll=newR;
    strcpy(tmp->stu->fname,fn);
    strcpy( tmp->stu->lname,ln);
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
            if( traval->stu->roll == oldR )
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
                if( traval->stu->roll == oldR )
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

void deleteGivenNode(int val) // val : roll number
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
   else if( (Start->stu->roll==val)&&(Start->next==NULL) )
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
           if( traval->stu->roll == val )
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
               if(traval->stu->roll==val)
                c2++;
               if(c2==ch)
               {
                   if( (Start->stu->roll==val)&&(x==1)&&(c2==1) )
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
       printf("ROLL NO\tFIRST NAME\tLAST NAME\n\n");
       while(1)
       {
           printf("%d \t %s \t %s\n\n",tmp->stu->roll,tmp->stu->fname,tmp->stu->lname);
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
