//
//  BinaryTree.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/1/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//

#include "BinaryTree.h"


BinaryTree * BinaryTree::insert (BinaryTree *tree, int i){
    if (!tree){
        BinaryTree *node = new BinaryTree(i);
        return node;
    }else if (tree->data > i){
        tree->left = insert(tree->left, i);
        
    }else if (tree->data < i){
        tree->right = insert(tree->right, i);
    }
    return tree;
}