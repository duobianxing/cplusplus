//
//  saveBSTtoFile.cpp
//  cplusplus
//
//  Created by Peng Zhang on 6/3/14.
//  Copyright (c) 2014 Peng Zhang. All rights reserved.
//
// save will be using pre-order traversal, will not code here.
// code below is to restore from file
#include "saveBSTtoFile.h"
#include "BinaryTree.h"
#include <fstream>

void readBSTfromFile(int min, int max, int insertVal, BinaryTree *p, std::ifstream &fin){
    while (insertVal> min && insertVal < max) {
        p = new BinaryTree(insertVal);
        int val;
        if(fin>>val){
              readBSTfromFile(min, insertVal, val, p, fin);
              readBSTfromFile(insertVal, max, val, p, fin);
        }
    }
}