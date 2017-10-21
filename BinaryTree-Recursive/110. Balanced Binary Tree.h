//
// Created by Shinelon on 2017/10/21.
//

#ifndef ALGORITHM_INTERVIEW2_110_BALANCED_BINARY_TREE_H
#define ALGORITHM_INTERVIEW2_110_BALANCED_BINARY_TREE_H

#include "BinaryTree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >=0 ;
    }
private:
    int getHeight(TreeNode* node) {
        if(!node) return 0;
        int hl = getHeight(node->left);
        int hr = getHeight(node->right);
        if(hl<0 || hr<0 || abs(hl - hr) > 1) return -1;
        return max(hl, hr) + 1;
    }
};

class Test{
public:
    void test(){
//        int arr[] = {1,2,2,3,3,3,3,4,4,4,4,4,4,NULL,NULL,5,5};
        int arr[] = {1,2,3,4,5,6,NULL,7};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        cout<< Solution().isBalanced(root) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_110_BALANCED_BINARY_TREE_H
