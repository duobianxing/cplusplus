//
//  BinaryTree.h
//  cplusplus
//
//  Created by Peng Zhang on 6/1/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//

#ifndef __cplusplus__BinaryTree__
#define __cplusplus__BinaryTree__

#include <iostream>

class BinaryTree {
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree (int i){
        data = i;
    }
    BinaryTree * insert (BinaryTree *tree, int i);
};

#endif /* defined(__cplusplus__BinaryTree__) */
