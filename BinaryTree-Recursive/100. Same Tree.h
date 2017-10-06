//
// Created by Shinelon on 2017/10/6.
//

#ifndef ALGORITHM_INTERVIEW2_100_SAME_TREE_H
#define ALGORITHM_INTERVIEW2_100_SAME_TREE_H

#include "BinaryTree.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        else return p->val == q->val && isSameTree(p->left, q->left) || isSameTree(p->right, q->right);
    }
};

class Test{
public:
    void test(){
        int arr1[] = {10,5,15};
        int arr2[] = {10,5,NULL,NULL,15};
        int n1 = sizeof(arr1)/sizeof(int);
        int n2 = sizeof(arr1)/sizeof(int);
        TreeNode* p = CreateBinaryTree(arr1, n1);
        TreeNode* q = CreateBinaryTree(arr2, n2);

        cout<< Solution().isSameTree(p, q) <<endl;
    }
};


#endif //ALGORITHM_INTERVIEW2_100_SAME_TREE_H
