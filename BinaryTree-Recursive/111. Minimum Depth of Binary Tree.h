//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_111_MINIMUM_DEPTH_OF_BINARY_TREE_H
#define ALGORITHM_INTERVIEW2_111_MINIMUM_DEPTH_OF_BINARY_TREE_H

#include <queue>
#include "BinaryTree.h"

class Solution {
public:

    /**
     * 迭代版
     * BFS
     * @param root
     * @return
     */
    int minDepth(TreeNode* root){
        int res = 0;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ){
            ++res;
            for(int i=0, n=q.size(); i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left==NULL && cur->right==NULL){
                    return res;
                }
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
    }

    /**
     * 递归
     * DFS
     * @param root
     * @return
     */
    int minDepth1(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if(minLeft == 0 || minRight == 0){
            return 1+max(minLeft, minRight);
        }
        return 1+min(minLeft, minRight);
    }
};

#endif //ALGORITHM_INTERVIEW2_111_MINIMUM_DEPTH_OF_BINARY_TREE_H
