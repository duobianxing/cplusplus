//
//  findLargestBSTsubtree.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/1/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//

#include "findLargestBSTsubtree.h"
#include "BinaryTree.h"

int findLargestBSTsubtree(BinaryTree *p, int &min, int &max, int &maxNodes, BinaryTree *BST){
    if (!p) return 0;
    bool isBST = true;
    int leftNodes = findLargestBSTsubtree(p->left, min, max, maxNodes, BST);
    int currMin = (leftNodes == 0) ? p->data : min;
    if (leftNodes == -1 || (leftNodes != 0 && p->data >max)) {
        isBST = false;
    }
    int rightNodes = findLargestBSTsubtree(p->right, min, max, maxNodes, BST);
    int currMax = (rightNodes == 0) ? p->data : max;
    if (rightNodes == -1 || (rightNodes != 0 && p->data <min)) {
        isBST = false;
    }
    if (isBST) {
        min = currMin;
        max = currMax;
        int totalNodes = leftNodes + rightNodes + 1;
        if (maxNodes < totalNodes) {
            maxNodes = totalNodes;
            BST = p;
        }
        return totalNodes;
        
    }else return -1;
}

BinaryTree * findLargestBSTsubtree(BinaryTree *root){
    int min = INT_MIN;
    int max = INT_MAX;
    int maxNodes = INT_MIN;
    BinaryTree *BST = NULL;
    findLargestBSTsubtree(root, min, max, maxNodes, BST);
    return BST;
}