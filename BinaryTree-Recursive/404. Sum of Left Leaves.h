//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_404_SUM_OF_LEFT_LEAVES_H
#define ALGORITHM_INTERVIEW2_404_SUM_OF_LEFT_LEAVES_H

#include "BinaryTree.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int res = 0;
        if(root->left){
            if(isLeaf(root->left)){
                res += root->left->val;
            }else{
                res += sumOfLeftLeaves(root->left);
            }
        }
        if(root->right && !isLeaf(root->right)){
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }

    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
};

#endif //ALGORITHM_INTERVIEW2_404_SUM_OF_LEFT_LEAVES_H
