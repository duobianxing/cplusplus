//
//  printEdgenode.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/3/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//

#include "printEdgenode.h"
#include "BinaryTree.h"

void printLeftEdge(BinaryTree *root, bool print){
    if (!root) {
        print = false;
        return;
    }
    if (print) {
        std::cout<<root->data<<" ";
    }
    if (!print && !root->left && !root->right) {
        std::cout<<root->data<<" ";
    }
    printLeftEdge(root->left, print);
    printLeftEdge(root->right, print);
    
}

void printRightEdge(BinaryTree *root, bool print){
    if (!root) {
        //print = false;
        return;
    }
    printRightEdge(root->left, false);
    printRightEdge(root->right, print);
    if (print || (!root->left && !root->right)) {
        std::cout<<root->data<<" ";
    }
}

void printEdge(BinaryTree *root){
    if (!root) {
        return;
    }
    std::cout<<root->data<<" ";
    bool t = true;
    printLeftEdge(root, t);
    printRightEdge(root, t);
    
}