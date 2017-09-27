//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_112_PATH_SUM_H
#define ALGORITHM_INTERVIEW2_112_PATH_SUM_H

#include "BinaryTree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return sum == root->val;
        }else{
            return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right, sum-root->val);
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_112_PATH_SUM_H
