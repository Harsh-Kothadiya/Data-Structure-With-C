//UNDIRECTED GRAPH WITH ADJACENCY MATRIX
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Graph
{
    int V;
    int E;
    int **Adj;
};
void createGraph(int,int);
void main()
{
    int v,e;
    printf("\n\n\t ENTER TOTAL NUMBER OF VERTEX(NODE) : ");
    scanf("%d",&v);
    printf("\n\n\t ENTER TOTAL NUMBER OF EDGES : ");
    scanf("%d",&e);

    createGraph(v,e);
    printf("\n\n");
    getch();
}
void createGraph(int v,int e)
{
    struct Graph *G;
    G=(struct Graph*)malloc(sizeof(struct Graph));
    G->V=v;
    G->E=e;
    G->Adj=(int**)malloc(sizeof(int*)*v);
    int i,j,k;
    for(i=0;i<v;i++)
        G->Adj[i]=(int*)malloc(sizeof(int*)*v);

    //now all value is zero in matrix
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            G->Adj[i][j]=0;
        }
    }
    printf("\n\n----------INITIAL UNDIRECTED GRAPH----------------------\n\n");
    for(i=0;i<v;i++)
        printf("\tv%d",i+1);
    printf("\n------------------------------------------\n");
    for(i=0;i<v;i++)
    {
        printf("v%d|",i+1);
        for(j=0;j<v;j++)
        {
            printf("\t%d",G->Adj[i][j]);
        }
        printf("\n");
    }
    for(k=0;k<e;k++)
    {
        printf("\n\n\t ENTER VERTEX NUMBER CONNECTED BY THIS EDGES : ");
        scanf("%d%d",&i,&j);
        G->Adj[i-1][j-1]=1;
        G->Adj[j-1][i-1]=1;
    }
    printf("\n\n----------AFTER DATA ENTER UNDIRECTED GRAPH----------------------\n\n");
    for(i=0;i<v;i++)
        printf("\tv%d",i+1);
    printf("\n-------------------------------------------\n");
    for(i=0;i<v;i++)
    {
        printf("v%d|",i+1);
        for(j=0;j<v;j++)
        {
            printf("\t%d",G->Adj[i][j]);
        }
        printf("\n");
    }
}

