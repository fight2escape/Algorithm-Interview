//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_226_INVERT_BINARY_TREE_H
#define ALGORITHM_INTERVIEW2_226_INVERT_BINARY_TREE_H

#include "BinaryTree.h"
#include <algorithm>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

#endif //ALGORITHM_INTERVIEW2_226_INVERT_BINARY_TREE_H
