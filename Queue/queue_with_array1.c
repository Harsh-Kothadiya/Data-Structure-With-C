//Implement QUEUE using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct QUEUE  //QUEUE : Data Structure
{
    int size;  //Size : total Capacity
    int front; //front using : deletion
    int rear;  //rear using : insertion
    int *ptr;
};
struct QUEUE* CreateQUEUE(int s);
void ENQUEUE(struct QUEUE*,int);
void DEQUEUE(struct QUEUE*);
void view(struct QUEUE*);

void main()
{
    struct QUEUE *Q;
    int s;
    int choice;
    int val;

    printf("\n\n\t ENTER SIZE : ");
    scanf("%d",&s);
    Q=CreateQUEUE(s);

    do
    {
        printf("\n\t ENTER-1 : ENQUEUE");
        printf("\n\t ENTER-2 : DEQUEUE");
        printf("\n\t ENTER-3 : VIEW");
        printf("\n\t ENTER-4 : Exit");
        printf("\n\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("\n\n\t ENTER A VALUE : ");
                scanf("%d",&val);
                ENQUEUE(Q,val);
                break;
            case 2 :
                DEQUEUE(Q);
                break;
           case 3 :
                view(Q);
                break;
           case 4 :
                break;
            default :
                printf("\n\n INVALIED CHOICE...\n\n");
                break;

        }
    }while(choice!=4);
    printf("\n\n");
    getch();
}
struct QUEUE* CreateQUEUE(int s)
{
    struct QUEUE *Q;
    Q=(struct QUEUE*)malloc(sizeof(struct QUEUE));
    Q->size=s;
    Q->front=-1;
    Q->rear=-1;
    Q->ptr=(int*)malloc(sizeof(int)*s);
    return Q;
}
void ENQUEUE(struct QUEUE *Q,int val)
{
    if( (Q->front==0&&Q->rear==Q->size-1) || (Q->front==Q->rear+1) )
    {
        printf("\n\nOVERFLOW...\n\n");
    }
    else if( ((Q->front==Q->rear)&&(Q->rear==Q->size-1)) || ((Q->rear==Q->size-1)&&(Q->front!=0)) )
    {
        Q->rear=0;
        Q->ptr[Q->rear]=val;
        printf("\n\n ENQUEUE VALUE : %d && INDEX : %d\n\n",val,Q->rear);
    }
    else
    {
       Q->rear++;
       if(Q->front==-1)
          Q->front=0;
       Q->ptr[Q->rear]=val;
       printf("\n\n ENQUEUE VALUE : %d && INDEX : %d\n\n",val,Q->rear);
    }
}
void DEQUEUE(struct QUEUE *Q)
{
    if(Q->front == -1)
    {
        printf("\n\nUNDER_FLOW...\n\n");
    }
    else if(Q->front==Q->rear)
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",Q->ptr[Q->front],Q->front);
        Q->front=-1;
        Q->rear=-1;
    }
    else if((Q->front==Q->size-1)&&(Q->rear!=Q->front))
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",Q->ptr[Q->front],Q->front);
        Q->front=0;
    }
    else
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",Q->ptr[Q->front],Q->front);
        Q->front++;
    }
}
void view(struct QUEUE *Q)
{
  int i;
  if(Q->front==-1)
  {
      printf("\n\n UNDER_FLOW...\n\n");
  }
  else
  {
      printf("\n\n");
      if(Q->front<=Q->rear)
      {
          for(i=Q->front;i<=Q->rear;i++)
            printf("\n VALUE : %d && INDEX : %d \n",Q->ptr[i],i);
      }
      if(Q->front > Q->rear)
      {
          for(i=Q->front;i<Q->size;i++)
           printf("\n VALUE : %d && INDEX : %d \n",Q->ptr[i],i);

          for(i=0;i<=Q->rear;i++)
            printf("\n VALUE : %d && INDEX : %d \n",Q->ptr[i],i);
      }
      printf("\n\n");
  }
}
