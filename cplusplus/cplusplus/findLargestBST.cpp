//
//  findLargestBST.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/1/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//

#include "findLargestBST.h"
#include "BinaryTree.h"
int findLargestBST(BinaryTree *p, int min, int max, BinaryTree *& BST, int MaxNodes, BinaryTree *topNode){
    if (!p){
        return 0;}
    if (p->data > min && p->data < max) {
        int leftNodes = findLargestBST(p->left, min, p->data,BST, MaxNodes, topNode);
        BinaryTree *leftChild = (leftNodes ? topNode : NULL);
        int rightNodes = findLargestBST(p->right, p->data, max, BST, MaxNodes, topNode);
        BinaryTree *rightChild = (rightNodes ? topNode : NULL );
        int TotalNodes = leftNodes + rightNodes + 1;
        BinaryTree *parent = new BinaryTree(p->data);
        parent->left = leftChild;
        parent->right = rightChild;
        topNode = parent;
        if (TotalNodes > MaxNodes) {
            MaxNodes = TotalNodes;
            BST = parent;
        }
        return TotalNodes;
    }else{
        findLargestBST(p, min, max, BST, MaxNodes, topNode);
        // return 0 to exclude this Node??
        return 0;
    }
}

BinaryTree * findLargestBST(BinaryTree *p){
    int min = INT_MIN;
    int max = INT_MAX;
    int MaxNodes = 0;
    BinaryTree *BST = NULL;
    BinaryTree *topNode = NULL;
    findLargestBST(p, min, max, BST, MaxNodes, topNode);
    return BST;
}