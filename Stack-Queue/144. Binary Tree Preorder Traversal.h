//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_144_BINARY_TREE_PREORDER_TRAVERSAL_H
#define ALGORITHM_INTERVIEW2_144_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "BinaryTree.h"
#include <stack>

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root != NULL){
            stk.push(root);
        }
        while(!stk.empty()){
            root = stk.top();
            res.push_back(root->val);
            stk.pop();

            if(root->right != NULL){
                stk.push(root->right);
            }
            if(root->left != NULL){
                stk.push(root->left);
            }
        }
        return res;
    }

    /**
     * 递归实现
     * @param root
     * @return
     */
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> res;
        __preorderTraversal(root, res);
        return res;
    }

private:
    void __preorderTraversal(TreeNode* root, vector<int>& res){
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        __preorderTraversal(root->left,res);
        __preorderTraversal(root->right,res);
    }
};

#endif //ALGORITHM_INTERVIEW2_144_BINARY_TREE_PREORDER_TRAVERSAL_H
