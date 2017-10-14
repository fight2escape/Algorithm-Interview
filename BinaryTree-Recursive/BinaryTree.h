//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_BINARYTREE_H
#define ALGORITHM_INTERVIEW2_BINARYTREE_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateBinaryTree(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(8);
    return root;
}

/**
 * 根据给定的数组创建二叉树
 * 数组示例：相当于层序遍历的结果
 * int tree[] = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
 * @param arr
 * @param n
 * @return
 */
TreeNode* CreateBinaryTree(int arr[], int n){
    if(n <= 0){
        return NULL;
    }
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i=0;
    while( !q.empty() && i < n){
        TreeNode* cur = q.front();
        q.pop();
        if(++i < n && arr[i]!=NULL){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        if(++i < n && arr[i]!=NULL){
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
    }
    return root;
}

void InorderBST(TreeNode* root){
    if(root){
        if(root->left){
            InorderBST(root->left);
        }
        printf("%d ", root->val);
        if(root->right){
            InorderBST(root->right);
        }
    }
}

#endif //ALGORITHM_INTERVIEW2_BINARYTREE_H
