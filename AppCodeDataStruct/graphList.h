#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXVEX 100
typedef struct EdgeNode
{
    int adjvex;
    char info;
    struct EdgeNode *next;

};
