/*
 * File:   graphList.h
 * Author: xsun
 *
 * Created on July 31, 2014, 8:31 PM
 */

#ifndef GRAPHLIST_H
#define    GRAPHLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 9
#define MAXVEX 9
#define MAXEDGE 15
#define INFINITY 65535

typedef int Status;
typedef int Boolean;
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode {
    int adjvex;
    char info;
    struct EdgeNode *next;

} EdgeNode;

typedef struct {
    int in;
    char data;
    EdgeNode *firstEdge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList, *pGraphAdjList;

typedef struct {
    int data[MAXSIZE];
    int front;
    int rear;
} Queue;

Status InitQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    return OK;
}

Status QueueEmpty(Queue *queue) {
    if (queue->front == queue->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status Enqueue(Queue *queue, int e) {
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return ERROR;
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MAXSIZE;

    return OK;
}

Status DeQueue(Queue *queue, int *e) {
    if (queue->front == queue->rear)
        return ERROR;
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return OK;
}

void CreateListMGraph(MGraph *G) {
    int i, j;

    G->numEdges = 15;
    G->numVertexes = 9;

    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';


    for (i = 0; i < G->numVertexes; i++) {
        for (j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    G->arc[1][2] = 1;
    G->arc[1][8] = 1;
    G->arc[1][6] = 1;

    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][7] = 1;
    G->arc[3][6] = 1;
    G->arc[3][8] = 1;

    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    G->arc[5][6] = 1;

    G->arc[6][7] = 1;


    for (i = 0; i < G->numVertexes; i++) {
        for (j = i; j < G->numVertexes; j++) {
            G->arc[j][i] = G->arc[i][j];
        }
    }

}

void CreateALGraph(MGraph G, GraphAdjList *GL) {

    EdgeNode *e;
    GL->numEdges = G.numEdges;
    GL->numVertexes = G.numVertexes;
    for (int i = 0; i < G.numVertexes; i++) {
        GL->adjList[i].data = G.vexs[i];
        GL->adjList[i].in = 0;
        GL->adjList[i].firstEdge = NULL;
    }

    for (int i = 0; i < G.numVertexes; i++) {
        for (int j = 0; j < G.numVertexes; j++) {
            if (G.arc[i][j] == 1) {
                e = (EdgeNode *) malloc(sizeof(EdgeNode));
                e->info = G.arc[i][j];
                e->adjvex = j;
                e->next = GL->adjList[i].firstEdge;
                GL->adjList[i].firstEdge = e;
                GL->adjList[j].in++;
            }
        }
    }

}

Boolean visited[MAXSIZE];

void DFSList(GraphAdjList GL, int i) {
    visited[i] = TRUE;
    printf("%c ", GL.adjList[i].data);
    EdgeNode *edgNode = GL.adjList[i].firstEdge;
    while (edgNode) {
        if (!visited[edgNode->adjvex]) {
            DFSList(GL, edgNode->adjvex);
        }
        edgNode = edgNode->next;
    }
}

void DFSListTraverse(GraphAdjList GL) {

    int i;
    for (i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    for (i = 0; i < GL.numVertexes; i++) {
        if (!visited[i]) {
            DFSList(GL, i);
        }
    }
}

void DGSListTraverse(GraphAdjList GL) {
    int i, j;
    Queue Q;
    InitQueue(&Q);
    for (i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    for (i = 0; i < GL.numVertexes; i++) {
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", GL.adjList[i].data);
        }
        Enqueue(&Q, i);
        while (!QueueEmpty(&Q)) {
            DeQueue(&Q, &j);
            EdgeNode *p = GL.adjList[j].firstEdge;
            while (p) {
                if(visited[!p->adjvex]) {
                    visited[p->adjvex] = TRUE;
                    printf("%c ", GL.adjList[p->adjvex].data);
                    Enqueue(&Q, p->adjvex);
                }
                p = p->next;
            }
        }
    }
}


#endif	/* GRAPHLIST_H */


