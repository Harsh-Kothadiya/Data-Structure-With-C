//implement Stack using Dynamic Array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct STACK
{
    int size; // size:Capacity
    int top;
    int *ptr;
};
struct STACK* CreateSTACK(int);
struct STACK* PUSH(struct STACK*,int);
struct STACK* POP(struct STACK*);
struct STACK* PEEK(struct STACK*);
struct STACK* count(struct STACK*);
struct STACK* getItemWithIndex(struct STACK*,int);
struct STACK* Edit(struct STACK*,int,int);
struct STACK* SearchWithValue(struct STACK*,int);
struct STACK* PrintData(struct STACK*);
struct STACK* findCapacity(struct STACK*);
struct STACK* withOutRealloc(struct STACK*,int);
void main()
{
    struct STACK *t;
    int s;
    int choice;
    int no;
    int Index;

    printf("\n\n\t ENTER SIZE : ");
    scanf("%d",&s);
    t=CreateSTACK(s);

    do
    {
        printf("\n\n\t ENTER-1 : PUSH");
        printf("\n\n\t ENTER-2 : POP");
        printf("\n\n\t ENTER-3 : PEEK");
        printf("\n\n\t ENTER-4 : Count total present item");
        printf("\n\n\t ENTER-5 : Get item at given index");
        printf("\n\n\t ENTER-6 : Edit an item");
        printf("\n\n\t ENTER-7 : Search an item");
        printf("\n\n\t ENTER-8 : Print Data");
        printf("\n\n\t ENTER-9 : Capacity(size)");
        printf("\n\n\t ENTER-10: EXIT");

        printf("\n\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                    printf("\n\n\t ENTER A NO : ");
                    scanf("%d",&no);
                    t=PUSH(t,no);
                break;
            case 2 :
                   t=POP(t);
                break;
            case 3 :
                t=PEEK(t);
                break;
            case 4:
                t=count(t);
                break;
            case 5 :
                printf("\n\n\t ENTER INDEX : ");
                scanf("%d",&Index);
                t=getItemWithIndex(t,Index);
                break;
            case 6 :
                printf("\n\n\t ENTER INDEX : ");
                scanf("%d",&Index);
                printf("\n\n\t ENTER A NO : ");
                scanf("%d",&no);
                t=Edit(t,Index,no);
                break;
            case 7 :
                printf("\n\n\t ENTER A NO : ");
                scanf("%d",&no);
                t=SearchWithValue(t,no);
                break;
            case 8 :
                t=PrintData(t);
                break;
            case 9 :
                t=findCapacity(t);
                break;
            case 10 :
                break;
            default :
                printf("\n\n IN_VALIED CHOICE...\n\n");
                break;
        }
    }while(choice!=10);
    printf("\n\n");
    getch();
}

struct STACK* CreateSTACK(int s)
{
    struct STACK *tmp;
    tmp=(struct STACK*)malloc(sizeof(struct STACK));
    tmp->ptr=(int*)malloc(sizeof(int)*s);
    tmp->top=-1;
    tmp->size=s;
    return tmp;
}

struct STACK* PUSH(struct STACK *tmp,int val)
{
    int ch;
    int s1;

    if( tmp->top == tmp->size-1 )
    {
        printf("\n\n OVER_FLOW...SO ENTER NEW SIZE GREATAR THAN %d",tmp->size);
        printf("\n\n NOW ENTER NEW ARRAY SIZE : ");
        scanf("%d",&s1);
        tmp->size=s1;

        printf("\n\n ENTER-1 : USING REALLOC FUNCTION");
        printf("\n\n ENTER-2 : WITHOUT REALLOC FUNCTION");
        printf("\n\n ENTER YOUR CHOICE 1 OR 2 : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :
                tmp->ptr=realloc(tmp->ptr,s1);
                break;
            case 2 :
                tmp=withOutRealloc(tmp,s1);
                break;
            default :
                break;
        }
    }
    tmp->top++;
    tmp->ptr[tmp->top]=val;
 return tmp;
}
struct STACK* POP(struct STACK *tmp)
{
    int i;
    if( tmp->top == -1)
       printf("\n\n UNDER_FLOW...\n\n");
    else
       tmp->top--;
  return tmp;
}

struct STACK* PEEK(struct STACK *tmp)
{
   if(tmp->top==-1)
    printf("\n\n UNDER_FLOW...");
   else
    printf("\n\n PEEK VALUE IS : %d",tmp->ptr[tmp->top]);

  printf("\n\n");
  return tmp;
}

struct STACK* count(struct STACK *tmp)
{
     if( tmp->top == -1)
        printf("\n\n UNDER_FLOW...\n\n");
     else
        printf("\n\n TOTAL PRESENT ITEM : %d\n\n",tmp->top+1);

     return tmp;
}
struct STACK* getItemWithIndex(struct STACK *tmp,int index)
{
    if( tmp->top == -1 )
        printf("\n\n UNDER_FLOW...\n\n");
    else if( index<0 || index>tmp->top )
        printf("\n\n IN_VALIED INDEX...\n\n");
    else
        printf("\n\n GET VALUE BY INDEX : %d",tmp->ptr[index]);

    return tmp;
}

struct STACK* Edit(struct STACK *tmp,int index,int val)
{
        if( tmp->top == -1 )
            printf("\n\n UNDER_FLOW...\n\n");
        else if( index<0 || index>tmp->top )
            printf("\n\n IN_VALIED INDEX...\n\n");
        else
            tmp->ptr[index]=val;

    return tmp;
}
struct STACK* SearchWithValue(struct STACK *tmp,int val)
{
      int i;
      int a=0;

      if( tmp->top == -1 )
            printf("\n\n UNDER_FLOW...\n\n");
      else
      {
          for(i=0;i<=tmp->top;i++)
          {
              if( tmp->ptr[i] == val )
              {
                  a=1;
                  break;
              }
              else
                a=0;
          }

          if( a==1 )
            printf("\n\n VALUE FOUND...\n\n");
          else
            printf("\n\n VALUE NOT FOUND...\n\n");
      }

      return tmp;
}

struct STACK* PrintData(struct STACK *tmp)
{
       int i;
       if( tmp->top == -1 )
            printf("\n\n UNDER_FLOW...\n\n");
       else
       {
           printf("\n\n");
           for(i=0;i<=tmp->top;i++)
            printf("%d\t",tmp->ptr[i]);

            printf("\n\n");
       }

       return tmp;
}
struct STACK* findCapacity(struct STACK *tmp)
{
        printf("\n\n TOTAL CAPACITY : %d\n\n",tmp->size);
        return tmp;
}

struct STACK* withOutRealloc(struct STACK *t1,int s1)
{
  int a[t1->top];
  int i;
  for(i=0;i<=t1->top;i++)
  {
    a[i]=t1->ptr[i];
  }
  free(t1->ptr);
  t1->ptr=(int*)malloc(sizeof(int)*s1);
  for(i=0;i<=t1->top;i++)
  {
     t1->ptr[i]=a[i];
  }
 return t1;
}
