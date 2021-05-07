//Implement STACK using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct STACK  //STACK : stay Data Structure
{
    int size;  //Size : total Capacity
    int top;
    int *ptr;
};
struct STACK* CreateStack(int s);
struct STACK* PUSH(struct STACK*,int);
struct STACK* POP(struct STACK*);
struct STACK* PEEK(struct STACK*);
struct STACK*  CountTotal(struct STACK*); //CountTotal : count total items in present stay
struct STACK* Edit(struct STACK*,int,int);
struct STACK* search(struct STACK*,int);
struct STACK* view(struct STACK*);

void main()
{
    struct STACK *st;
    int s;
    int choice;
    int val;
    int ei; //ei : edit index
    int ev; //ev : edit value
    int si;//si : search index
    printf("\n\n\t ENTER SIZE : ");
    scanf("%d",&s);
    st=CreateStack(s);

    do
    {
        printf("\n\t ENTER-1 : PUSH");
        printf("\n\t ENTER-2 : POP");
        printf("\n\t ENTER-3 : PEEK");
        printf("\n\t ENTER-4 : Edit an item");
        printf("\n\t ENTER-5 : Search an item");
        printf("\n\t ENTER-6 : Count total items present");
        printf("\n\t ENTER-7 : VIEW");
        printf("\n\t ENTER-8 : Exit");
        printf("\n\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("\n\n\t ENTER A VALUE : ");
                scanf("%d",&val);
                st=PUSH(st,val);
                break;
            case 2 :
                st=POP(st);
                break;
            case 3 :
                st=PEEK(st);
                break;
            case 4 :
                printf("\n\n\t ENTER EDIT INDEX : ");
                scanf("%d",&ei);
                printf("\n\n\t ENTER A NEW VALUE : ");
                scanf("%d",&ev);
                st=Edit(st,ei,ev);
                break;
            case 5 :
                printf("\n\n\t ENTER A SEARCH INDEX : ");
                scanf("%d",&si);
                st=search(st,si);
                break;
            case 6 :
                st=CountTotal(st);
                break;
            case 7 :
                st=view(st);
                break;
            case 8:
                break;
            default :
                printf("\n\n INVALIED CHOICE...\n\n");
                break;

        }
    }while(choice!=8);
    printf("\n\n");
    getch();
}
struct STACK* CreateStack(int s)
{
    struct STACK *tmp;
    tmp=(struct STACK*)malloc(sizeof(struct STACK));
    tmp->size=s;
    tmp->top=-1;
    tmp->ptr=(int*)malloc(sizeof(int)*s);
    return tmp;
}

struct STACK* PUSH(struct STACK*tmp,int val)
{
    if(tmp->top==tmp->size-1)
    {
        printf("\n\nOVERFLOW...\n\n");
    }
    else
    {
       tmp->top++;
       tmp->ptr[tmp->top]=val;

    }
    return tmp;
}
struct STACK* POP(struct STACK *tmp)
{
    if(tmp->top == -1)
        printf("\n\nUNDER_FLOW...\n\n");
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
struct STACK* Edit(struct STACK *tmp,int index,int val)
{
    if(tmp->top == -1)
        printf("\n\nUNDER_FLOW...\n\n");
    else if(index<0 || index>tmp->top)
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
        tmp->ptr[index]=val;

    return tmp;
}
struct STACK* search(struct STACK *tmp,int index)
{
    if(tmp->top == -1)
        printf("\n\nUNDER_FLOW...\n\n");
    else if(index<0 || index>tmp->top)
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
        printf("\n\nSEARCH VALUE IS : %d\n\n",tmp->ptr[index]);

    return tmp;
}
struct STACK*  CountTotal(struct STACK *tmp)
{
    if(tmp->top == -1)
        printf("\n\nUNDER_FLOW...\n\n");
    else
        printf("\n\nTOTAL PRESENT ITEM: %d\n\n",tmp->top+1);

    return tmp;
}
struct STACK* view(struct STACK* tmp)
{
  int i;
  if(tmp->top == -1)
        printf("\n\nUNDER_FLOW...\n\n");
  else
  {
      printf("\n\n");
      for(i=0;i<=tmp->top;i++)
      {
         printf("%d\t",tmp->ptr[i]);
      }
      printf("\n\n");
  }

  return tmp;
}
