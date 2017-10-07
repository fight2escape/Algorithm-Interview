
//
// Created by Shinelon on 2017/10/7.
//

#ifndef ALGORITHM_INTERVIEW2_101_SYMMETRIC_TREE_H
#define ALGORITHM_INTERVIEW2_101_SYMMETRIC_TREE_H

#include "BinaryTree.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return __isSymmetric(root->left, root->right);
    }
private:
    bool __isSymmetric(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(p && q && p->val==q->val) return __isSymmetric(p->left, q->right) && __isSymmetric(p->right, q->left);
        else return false;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,2,3,4,4,3};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        cout<< Solution().isSymmetric(root) <<endl;
        return;
    }
};
#endif //ALGORITHM_INTERVIEW2_101_SYMMETRIC_TREE_H
