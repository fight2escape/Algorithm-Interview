//
// Created by Shinelon on 2017/10/13.
//

#ifndef ALGORITHM_INTERVIEW2_98_VALIDATE_BINARY_SEARCH_TREE_H
#define ALGORITHM_INTERVIEW2_98_VALIDATE_BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

class Solution {
    /**
     * 递归判断每个节点是否合法
     */
public:
    bool isValidBST(TreeNode* root) {
        return __isValidBST(root, nullptr, nullptr);
    }
private:
    bool __isValidBST(TreeNode* node, TreeNode* Min, TreeNode* Max){
        if(!node){ return true; }
        else if(Max && node->val >= Max->val || Min && node->val <= Min->val){ return false; }
        else { return __isValidBST(node->left, Min, node) && __isValidBST(node->right, node, Max); }
    }

    /**
     * 中序遍历看是否为升序
     */
public:
    bool isValidBST2(TreeNode* root) {
        in.clear();
        inOrder(root);
        for(int i=1; i<in.size(); ++i){
            if(in[i-1] >= in[i]){
                return false;
            }
        }
        return true;
    }

private:
    vector<int> in;
    void inOrder(TreeNode* node){
        if(!node){ return; }
        inOrder(node->left);
        in.push_back(node->val);
        inOrder(node->right);
    }
};

class Test{
public:
    void test(){
//        int arr[] = {2147483647};
        int arr[] = {3,1,4,NULL,NULL};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        cout<< Solution().isValidBST(root)<< endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_98_VALIDATE_BINARY_SEARCH_TREE_H
