//
//  main.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/1/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//
#include <iostream>
#include "BinaryTree.h"
#include "printEdgenode.h"
void sum (int a, int b){
    int c = a +b;
    std::cout<<c<<'\n';
}

void sum (int c){
    std::cout<<c<<'\n';
}

int main(int argc, const char * argv[])
{
    bool t = true;
    int i = 30;
    BinaryTree *root = new BinaryTree(i);
    // insert code here...
    //std::cout << root->data;
    //std::cout << '\n';
    //int a = 3, b = 4, d =5;
    //sum(a, b);
    //sum(d);
    root->insert(root, 2);
    root->insert(root, 4);
    root->insert(root, 5);
    root->insert(root,10);
    root->insert(root,50);
    root->insert(root,20);
    root->insert(root,45);
    root->insert(root, 35);
   // root->insert(root, 3);
//std::cout<<root->right->data;
    std::cout<<root->data<<" ";
    printLeftEdge(root->left, t);
    printRightEdge(root->right, t);
}

