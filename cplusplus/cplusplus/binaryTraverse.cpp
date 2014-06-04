//
//  binaryTraverse.cpp
//  binary traverse non recursive
//  cplusplus
//
//  Created by Peng Zhang on 6/2/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//
#include <stack>
#include "binaryTraverse.h"
#include "BinaryTree.h"
void preOrder(BinaryTree *root){
    std::stack<BinaryTree *> stk;
    stk.push(NULL);
    while (root) {
        std::cout<<root->data<<";";
        if (root->right) {
            stk.push(root->right);
        }
        if (root->left) {
            stk.push(root->left);
        }
        root = stk.top();
        std::cout<<root->data<<"\n";
        stk.pop();
    }
}

void inOrder(BinaryTree *root){
    std::stack<BinaryTree *> stk;
    while (root || !stk.empty()) {    //why we need to check stack empty? Because we might have continuous left leaf  and it will be all in stack, we need to print them out.
        if (root) {
            stk.push(root);
            root = root->left;
            
        }else{
            BinaryTree *a = stk.top();
            stk.pop();
            std::cout<<a->data<<"\n";
            root =root->right;
        }
    }
}


// idea:
//1.go left all the way down, and keep all not null point into stack untill we find the first left node == null.
//2. If we found this node.
//     I. find out if this node have right node, if so, search on the right tree untill find the first node that has left node ==null.
//     II If found. check if
void postOrder(BinaryTree *root){
    std::stack<BinaryTree *> stk;
    BinaryTree *lastvisit = NULL;
    while (root || !stk.empty()) {
        if (root) {
            stk.push(root);
            root = root->left;
        } else{
            root = stk.top();
            if (root->right && lastvisit != root->right) {
                root = root->right;
            }else{
                root = stk.top();
                std::cout<<root->data<<"\n";
                stk.pop();
                lastvisit = root;
            }
        }
    }
    
}