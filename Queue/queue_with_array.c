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
struct QUEUE* ENQUEUE(struct QUEUE*,int);
struct QUEUE* DEQUEUE(struct QUEUE*);
struct QUEUE* view(struct QUEUE*);

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
                Q=ENQUEUE(Q,val);
                break;
            case 2 :
                Q=DEQUEUE(Q);
                break;
           case 3 :
                Q=view(Q);
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
    struct QUEUE *tmp;
    tmp=(struct QUEUE*)malloc(sizeof(struct QUEUE));
    tmp->size=s;
    tmp->front=-1;
    tmp->rear=-1;
    tmp->ptr=(int*)malloc(sizeof(int)*s);
    return tmp;
}

struct QUEUE* ENQUEUE(struct QUEUE *tmp,int val)
{
    if( (tmp->front==0&&tmp->rear==tmp->size-1) || (tmp->front==tmp->rear+1) )
    {
        printf("\n\nOVERFLOW...\n\n");
    }
    else if( ((tmp->front==tmp->rear)&&(tmp->rear==tmp->size-1)) || ((tmp->rear==tmp->size-1)&&(tmp->front!=0)) )
    {
        tmp->rear=0;
        tmp->ptr[tmp->rear]=val;
        printf("\n\n ENQUEUE VALUE : %d && INDEX : %d\n\n",val,tmp->rear);
    }
    else
    {
       tmp->rear++;
       if(tmp->front==-1)
          tmp->front=0;
       tmp->ptr[tmp->rear]=val;
       printf("\n\n ENQUEUE VALUE : %d && INDEX : %d\n\n",val,tmp->rear);
    }
    return tmp;
}
struct QUEUE* DEQUEUE(struct QUEUE *tmp)
{
    if(tmp->front == -1)
    {
        printf("\n\nUNDER_FLOW...\n\n");
    }
    else if(tmp->front==tmp->rear)
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",tmp->ptr[tmp->front],tmp->front);
        tmp->front=-1;
        tmp->rear=-1;
    }
    else if((tmp->front==tmp->size-1)&&(tmp->rear!=tmp->front))
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",tmp->ptr[tmp->front],tmp->front);
        tmp->front=0;
    }
    else
    {
        printf("\n\nDEQUEUE VALUE : %d && INDEX : %d\n\n",tmp->ptr[tmp->front],tmp->front);
        tmp->front++;
    }
    return tmp;
}
struct QUEUE* view(struct QUEUE *tmp)
{
  int i;
  if(tmp->front==-1)
  {
      printf("\n\n UNDER_FLOW...\n\n");
  }
  else
  {
      printf("\n\n");
      if(tmp->front<=tmp->rear)
      {
          for(i=tmp->front;i<=tmp->rear;i++)
            printf("\n VALUE : %d && INDEX : %d \n",tmp->ptr[i],i);
      }
      if(tmp->front > tmp->rear)
      {
          for(i=tmp->front;i<tmp->size;i++)
           printf("\n VALUE : %d && INDEX : %d \n",tmp->ptr[i],i);

          for(i=0;i<=tmp->rear;i++)
            printf("\n VALUE : %d && INDEX : %d \n",tmp->ptr[i],i);
      }
      printf("\n\n");
  }
  return tmp;
}
