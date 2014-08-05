#include <stdio.h>
#include <stdlib.h>
#import "graphVetex.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

typedef int Status;

typedef struct {
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph *G)
{
    int i, j;

    G->numEdges=15;
    G->numVertexes=9;

    for (i = 0; i < G->numVertexes; i++)
    {
        for ( j = 0; j < G->numVertexes; j++)
        {
            if (i==j)
                G->arc[i][j]=0;
            else
                G->arc[i][j] = G->arc[j][i] = INFINITY;
        }
    }

    G->arc[0][1]=10;
    G->arc[0][5]=11;
    G->arc[1][2]=18;
    G->arc[1][8]=12;
    G->arc[1][6]=16;
    G->arc[2][8]=8;
    G->arc[2][3]=22;
    G->arc[3][8]=21;
    G->arc[3][6]=24;
    G->arc[3][7]=16;
    G->arc[3][4]=20;
    G->arc[4][7]=7;
    G->arc[4][5]=26;
    G->arc[5][6]=17;
    G->arc[6][7]=19;

    for(i = 0; i < G->numVertexes; i++)
    {
        for(j = i; j < G->numVertexes; j++)
        {
            G->arc[j][i] =G->arc[i][j];
        }
    }

}

void MiniSpanTreePrim(MGraph G)
{
    int min, i, j,k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];

    adjvex[0] = 0;

    for(i = 1; i<G.numVertexes; i++)
    {
        adjvex[i] =0;
        lowcost[i]=G.arc[0][i];
    }

    for(i=1; i<G.numVertexes; i++)
    {
        min = INFINITY;
        while(j<G.numVertexes)
        {
            if(adjvex[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        lowcost[k] = 0;
        printf("%d - %d", adjvex[k], k);

        for(j=1; j<G.numVertexes; j++)
        {
            if(adjvex[j] != 0 && lowcost[j] > G.arc[k][j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }

}
