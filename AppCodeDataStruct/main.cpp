//
//  main.cpp
//  AppCodeDataStruct
//
//  Created by Xin Sun on 2014-07-07.
//  Copyright (c) 2014 Xin Sun. All rights reserved.
//

#include "graphVetex.h"

int main(void)
{
    MGraph G;
    CreateMGraph(&G);
    DFSTraverse(G);
    return 0;
}
