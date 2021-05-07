//with DMA
/*
Implement Array Data Structure with the following services
a. Append an item
// means example lastIndex+1 pe value store...
b. Insert an item
c. Count total items present
d. Delete an item from a given index
f. Edit an item
g. Search an item
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ADS  //ADS : Array Data Structure
{
    int size;  //Size : total Capacity
    int lastIndex;
    int *ptr;
};
struct ADS* CreateArray(int s);
struct ADS* Append(struct ADS*,int);
struct ADS* insert(struct ADS*,int,int);
struct ADS* CountTotal(struct ADS*); //CountTotal : count total items in present array
struct ADS* Delete(struct ADS*,int);
struct ADS* Edit(struct ADS*,int,int);
struct ADS* search(struct ADS*,int);
struct ADS* printArray(struct ADS*);

void main()
{
    struct ADS *arr;
    int s;
    int choice;
    int av; //av : append value
    int iv;//iv : insert value
    int Index;//Index: insert index
    int d_index; //d_index : delete index
    int ei; //ei : edit index
    int ev; //ev : edit value
    int si;//si : search index
    printf("\n\n\t ENTER ARRAY SIZE : ");
    scanf("%d",&s);
    arr=CreateArray(s);

    do
    {
        printf("\n\t ENTER-1 : Append an item");
        printf("\n\t ENTER-2 : Insert an item");
        printf("\n\t ENTER-3 : Count total items present");
        printf("\n\t ENTER-4 : Delete an item from a given index");
        printf("\n\t ENTER-5 : Edit an item");
        printf("\n\t ENTER-6 : Search an item");
        printf("\n\t ENTER-7 : Print Array Value");
        printf("\n\t ENTER-8 : Exit");
        printf("\n\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("\n\n\t ENTER A VALUE : ");
                scanf("%d",&av);
                arr=Append(arr,av);
                break;
            case 2 :
                printf("\n\n\t ENTER INSERT INDEX : ");
                scanf("%d",&Index);
                printf("\n\n\t ENTER A VALUE : ");
                scanf("%d",&iv);
                arr=insert(arr,Index,iv);
                break;
            case 3 :
                arr=CountTotal(arr);
                break;
            case 4 :
                printf("\n\n\t ENTER DELETE INDEX : ");
                scanf("%d",&d_index);
                arr=Delete(arr,d_index);
                break;
            case 5 :
                printf("\n\n\t ENTER EDIT INDEX : ");
                scanf("%d",&ei);
                printf("\n\n\t ENTER A NEW VALUE : ");
                scanf("%d",&ev);
                arr=Edit(arr,ei,ev);
                break;
            case 6 :
                printf("\n\n\t ENTER A SEARCH INDEX : ");
                scanf("%d",&si);
                arr=search(arr,si);
                break;
            case 7 :
                arr=printArray(arr);
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
struct ADS* CreateArray(int s)
{
    struct ADS *tmp;
    tmp=(struct ADS*)malloc(sizeof(struct ADS));
    tmp->size=s;
    tmp->lastIndex=-1;
    tmp->ptr=(int*)malloc(sizeof(int)*s);
    return tmp;
}

struct ADS* Append(struct ADS*tmp,int val)
{
    if(tmp->lastIndex==tmp->size-1)
    {
        printf("\n\nOVERFLOW...");
    }
    else
    {
       tmp->ptr[tmp->lastIndex+1]=val;
       tmp->lastIndex++;
    }
    return tmp;
}

struct ADS* insert(struct ADS* tmp,int index,int val)
{
    int i;
    if(tmp->lastIndex == tmp->size-1)
        printf("\n\nOVER_FLOW...\n\n");
    else if( index<0 || index>tmp->lastIndex+1 )
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
    {
        for(i=tmp->lastIndex;i>=index;i--)
        {
            tmp->ptr[i+1]=tmp->ptr[i];
        }
        tmp->ptr[index]=val;
        tmp->lastIndex++;
    }

      return tmp;
}
struct ADS* printArray(struct ADS* tmp)
{
  int i;
  if(tmp->lastIndex == -1)
        printf("\n\nEMPTY...\n\n");
  else
  {
      printf("\n\n");
      for(i=0;i<=tmp->lastIndex;i++)
      {
         printf("%d\t",tmp->ptr[i]);
      }
      printf("\n\n");
  }

  return tmp;
}
struct ADS*  CountTotal(struct ADS *tmp)
{
    if(tmp->lastIndex == -1)
        printf("\n\nEMPTY...\n\n");
    else
        printf("\n\nTOTAL ITEM PRESENT IN ARRAY : %d\n\n",tmp->lastIndex+1);

    return tmp;
}
struct ADS* Delete(struct ADS *tmp,int index)
{
    int i;
    if(tmp->lastIndex == -1)
        printf("\n\nEMPTY...\n\n");
    else if(index<0 || index>tmp->lastIndex)
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
    {
        for(i=index;i<tmp->lastIndex;i++)
        {
            tmp->ptr[i]=tmp->ptr[i+1];
        }
        tmp->lastIndex--;
    }

    return tmp;
}
struct ADS* Edit(struct ADS *tmp,int index,int val)
{
    if(tmp->lastIndex == -1)
        printf("\n\nEMPTY...\n\n");
    else if(index<0 || index>tmp->lastIndex)
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
        tmp->ptr[index]=val;

    return tmp;
}
struct ADS* search(struct ADS *tmp,int index)
{
    if(tmp->lastIndex == -1)
        printf("\n\nEMPTY...\n\n");
    else if(index<0 || index>tmp->lastIndex)
        printf("\n\nIN_VALIED INDEX...\n\n");
    else
        printf("\n\nSEARCH VALUE IS : %d\n\n",tmp->ptr[index]);

    return tmp;
}
