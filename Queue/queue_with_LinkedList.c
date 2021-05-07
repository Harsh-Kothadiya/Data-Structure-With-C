//Implement QUEUE using LINKED LIST : means use inked list data structure

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void ENQUEUE(int);
void DEQUEUE();
void view();

void main()
{
    int choice;
    int val;
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
                ENQUEUE(val);
                break;
            case 2 :
                DEQUEUE();
                break;
           case 3 :
                view();
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

void ENQUEUE(int val)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node*));
    tmp->item=val;
    tmp->next=NULL;

    if(rear==NULL)
    {
        rear=tmp;
        front=tmp;
    }
    else
    {
        rear->next=tmp;
        rear=tmp;
    }
    printf("\n\n ENQUEUE VALUE : %d\n\n",val);
}
void DEQUEUE()
{
    struct node *del;
    if(front == NULL)
    {
        printf("\n\nUNDER_FLOW...\n\n");
    }
    else
    {
        printf("\n\n DEQUEUE VALUE : %d\n\n",front->item);
        del=front;
        front=front->next;
        free(del);
    }
}
void view()
{
    struct node *traval;
    if(front == NULL)
    {
        printf("\n\nUNDER_FLOW...\n\n");
    }
    else
    {
        traval=front;
        printf("\n\n");
        while(1)
        {
            printf("%d\t",traval->item);
            if(traval==rear)
                break;
            traval=traval->next;
        }
        printf("\n\n");
    }
}
