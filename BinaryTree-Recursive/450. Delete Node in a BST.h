//
// Created by Shinelon on 2017/10/14.
//

#ifndef ALGORITHM_INTERVIEW2_450_DELETE_NODE_IN_A_BST_H
#define ALGORITHM_INTERVIEW2_450_DELETE_NODE_IN_A_BST_H

#include "BinaryTree.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->right){
                TreeNode* left = root->left;
                delete root;
                return left;
            }else{
                TreeNode* right = root->right;
                while(right->left){
                    right = right->left;
                }
                swap(root->val, right->val);
                root->right = deleteNode(root->right, right->val);
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

class Test{
public:
    void test(){
        int arr[] = {5,3,6,2,4,NULL,7};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        int k = 5;
        TreeNode* res = Solution().deleteNode(root, k);
        InorderBST(res);
    }
};

#endif //ALGORITHM_INTERVIEW2_450_DELETE_NODE_IN_A_BST_H
