//
//  main.cpp
//  AppCodeDataStruct
//
//  Created by Xin Sun on 2014-07-07.
//  Copyright (c) 2014 Xin Sun. All rights reserved.
//

//#include "graphVetex.h"
#include "graphList.h"


int main(void)
{
    MGraph G;

    //CreateMGraph(&G);
    //DFSTraverse(G);
    CreateListMGraph(&G);
    GraphAdjList GL;
    CreateALGraph(G, &GL);
    DFSListTraverse(GL);
    printf("\n");
    //DGSTraverse(G);
    return 0;
}
