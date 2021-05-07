/*BST : binary search tree
this case for duplicate value are not allowed
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *left;
    struct node *right;
};
struct node *ROOT=NULL;

void exit(int);

void insert(int);
void f(struct node*,struct node*,int);
void f1(struct node*,struct node*,int);
void f2(struct node*,struct node*,int);

void travse();
void inOrder(struct node*);
void preOrder(struct node*);
void postOrder(struct node*);

void Delete();
void checkData(struct node*,int);
void nochild(struct node*,struct node*);
void onechild(struct node*,struct node*);
void twochild(struct node*,struct node*);
void predecessor(struct node*,struct node*);
void successor(struct node*,struct node*);

int check=0;
void main()
{
    int choice;
    int no;

    do
    {
        printf("\n\n\t ENTER-1 : INSERT");
        printf("\n\n\t ENTER-2 : TRAVASE");
        printf("\n\n\t ENTER-3 : DELETE");
        printf("\n\n\t ENTER-4 : EXIT");
        printf("\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                printf("\n\n\t ENTER A NUMBER : ");
                scanf("%d",&no);
                insert(no);
                break;
            case 2 :
                travse();
                break;
            case 3 :
                printf("\n\n\t ENTER A NUMBER : ");
                scanf("%d",&no);
                Delete(no);
                break;
            case 4 :
                exit(0);
                break;
            default :
                printf("\n\n IN_VALIED CHOICE...\n\n");
                break;
        }
    }while(choice!=4);
    printf("\n\n");
    getch();
}

void insert(int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->left=NULL;
    n->right=NULL;

    if(ROOT==NULL)
    {
        ROOT=n;
        printf("\n\n%d : inserted\n",data);
        return;
    }
    else
    {
        f(ROOT,n,data);
        return;
    }
}
void f(struct node *tmp,struct node *n,int data)
{
   if(data == tmp->item)
   {
       printf("\n\n %d : not insert",data);
       return;
   }
   if(data < tmp->item)
   {
       f1(tmp,n,data);
       return;
   }
   if(data > tmp->item)
   {
       f2(tmp,n,data);
       return;
   }
}
void f1(struct node *tmp,struct node *n,int data)
{
    if(tmp->left==NULL)
    {
        tmp->left=n;
        printf("\n\n%d : inserted\n",data);
       // main();
       return;
    }
    else
    {
        tmp=tmp->left;
        f(tmp,n,data);
    }
}
void f2(struct node *tmp,struct node *n,int data)
{
    if(tmp->right==NULL)
    {
        tmp->right=n;
        printf("\n\n%d : inserted\n",data);
        //main();
        return;
    }
    else
    {
        tmp=tmp->right;
        f(tmp,n,data);
    }
}

void travse()
{
    if(ROOT==NULL)
    {
       printf("\n\n TREE EMPTY...\n\n");
       return;
    }
    else
    {
        printf("\n\n------IN-ORDER TRAVERSING--------\n\n");
        inOrder(ROOT);
        printf("\n\n------PRE-ORDER TRAVERSING--------\n\n");
        preOrder(ROOT);
        printf("\n\n------POST-ORDERTRAVERSING--------\n\n");
        postOrder(ROOT);

    }
}
void inOrder(struct node *tmp)
{
    if(tmp!=NULL)
    {
        inOrder(tmp->left);
        printf("%d\t",tmp->item);
        inOrder(tmp->right);
    }
}
void preOrder(struct node *tmp)
{
   if(tmp!=NULL)
   {
        printf("%d\t",tmp->item);
        preOrder(tmp->left);
        preOrder(tmp->right);
   }
}
void postOrder(struct node *tmp)
{
   if(tmp!=NULL)
   {
        postOrder(tmp->left);
        postOrder(tmp->right);
        printf("%d\t",tmp->item);
   }
}

void Delete(int data)
{
    if(ROOT==NULL)
    {
       printf("\n\n TREE EMPTY...\n\n");
       return;
    }
    else if(ROOT->item==data)
    {
        struct node *t;
        struct node *tmp=ROOT;
        struct node *p=NULL;
        if(ROOT->left==NULL&&ROOT->right==NULL)//no child
        {
            free(ROOT);
            ROOT=NULL;
        }
        else if(ROOT->left==NULL&&ROOT->right!=NULL)//one child
        {
            t=ROOT;
            ROOT=ROOT->right;
            free(t);
        }
        else if(ROOT->left!=NULL&&ROOT->right==NULL)//one child
        {
            t=ROOT;
            ROOT=ROOT->left;
            free(t);
        }
        else //if(ROOT->left!=NULL&&ROOT->right!=NULL)
        {
            twochild(p,tmp);
        }
    }
    else
    {
        checkData(ROOT,data);
        if(check==1)
        {
            check=0;
            struct node *tmp=ROOT;
            struct node *p=NULL;
            printf("\n\n DATA FOUND...");
            while(1)
            {
                if(data==tmp->item)
                    break;
                else if(data<tmp->item)
                {
                    p=tmp;
                    tmp=tmp->left;
                }
                else //if(data>tmp->item)
                {
                    p=tmp;
                    tmp=tmp->right;
                }
            }

            if(tmp->left==NULL&&tmp->right==NULL)
            {
                nochild(p,tmp);
                return;
            }
            else if((tmp->left==NULL&&tmp->right!=NULL)||(tmp->left!=NULL&&tmp->right==NULL))
            {
                onechild(p,tmp);
                return;
            }
            else //if(tmp->left!=NULL&&tmp->right!=NULL)
            {
                twochild(p,tmp);
                return;
            }
        }
        else
        {
            printf("\n\n DATA NOT FOUND...");
            return;
        }
    }
}
void checkData(struct node *tmp,int data)
{
   if(tmp!=NULL)
   {
        if(tmp->item==data)
        {
            check=1;
            return;
        }
        checkData(tmp->left,data);
        checkData(tmp->right,data);
   }
}
void nochild(struct node *p,struct node *tmp)
{
    if(tmp->item<p->item)
    {
        p->left=NULL;
    }
    else //if(tmp->item>p->item)
    {
        p->right=NULL;
    }
    free(tmp);
}
void onechild(struct node *p,struct node *tmp)
{
    if(p->item<tmp->item)
    {
        if(tmp->right==NULL)
        {
            p->right=tmp->left;
        }
        else //if(tmp->left==NULL)
        {
            p->right=tmp->right;
        }
    }
    else //if(p->item>tmp->item)
    {
        if(tmp->right==NULL)
        {
            p->left=tmp->left;
        }
        else //if(tmp->left==NULL)
        {
            p->left=tmp->right;
        }
    }
    free(tmp);
}
void twochild(struct node *p,struct node *tmp)
{
    int ch;
    do
    {
        printf("\n\n\t ENTER-1 : USING PREDECESSOR");
        printf("\n\n\t ENTER-2 : USING SUCCESSOR");
        printf("\n\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                predecessor(p,tmp);
                break;
            case 2:
                successor(p,tmp);
                break;
            default:
                printf("\n\n IN_VALIED CHOICE");
                break;
        }
    }while(!(ch>=1&&ch<=2));
}
void predecessor(struct node *p,struct node *tmp)
{
    struct node *t;
    p=tmp;
    t=tmp->left;
    while(1)
    {
        if(t->right==NULL)
            break;
        else
        {
            p=t;
            t=t->right;
        }
    }
    tmp->item=t->item;
    if(tmp==p)
    {
        if(t->left==NULL)
            p->left=NULL;
        else
            p->left=t->left;
    }
    else if(t->left==NULL)
        p->right=NULL;
    else
        p->right=t->left;
    free(t);
}
void successor(struct node *p,struct node *tmp)
{
    struct node *t;
    p=tmp;
    t=tmp->right;
    while(1)
    {
        if(t->left==NULL)
            break;
        else
        {
            p=t;
            t=t->left;
        }
    }
    tmp->item=t->item;
    if(tmp==p)
    {
        if(t->right==NULL)
            p->right=NULL;
        else
            p->right=t->right;
    }
    else if(t->right==NULL)
        p->left=NULL;
    else
        p->left=t->right;
    free(t);
}
