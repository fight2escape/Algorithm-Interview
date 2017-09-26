//
// Created by Shinelon on 2017/9/26.
//

#ifndef ALGORITHM_INTERVIEW2_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define ALGORITHM_INTERVIEW2_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include "BinaryTree.h"
#include <queue>

class Solution {
public:

    /**
     * 迭代版
     * 广度优先
     * @param root
     * @return
     */
    int maxDepth(TreeNode* root){
        int res = 0;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp;
        while( !q.empty() ){
            ++res;
            for(int i=0, n=q.size(); i<n; i++){
                tmp = q.front();
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
        }
        return res;
    }

    /**
     * 递归版
     * 深度优先
     * @param root
     * @return
     */
    int maxDepth1(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int res = 1;
        res += max(maxDepth(root->left),maxDepth(root->right));
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
//int tree[] = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
////    int tree[] = {0,NULL,4};
//int size = sizeof(tree)/sizeof(int);
//TreeNode *root = CreateBinaryTree(tree, size);
//
//int res = Solution().maxDepth(root);
//cout<<res<<endl;