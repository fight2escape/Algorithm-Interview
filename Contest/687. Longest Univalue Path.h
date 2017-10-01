//
// Created by Shinelon on 2017/10/1.
//

#ifndef ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H
#define ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H

#include "../BinaryTree-Recursive/BinaryTree.h"

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int* res = __longestUnivaluePath(root);
        int ret = max(res[0], max(res[1], res[2]));
        return max(0,ret-1);
    }
private:
    int* __longestUnivaluePath(TreeNode* root){
        int* include = new int[3]{0};
        if(root==NULL){
            return include;
        }
        int res = 0;
        int* left = __longestUnivaluePath(root->left);
        int* right = __longestUnivaluePath(root->right);
        if(root->left && root->val == root->left->val){
            res = left[0];
        }
        if(root->right && root->val == root->right->val){
            res = max(res, right[0]);
        }
        res++;
        include[0] = res;

        res = max(left[0], max(left[1],left[2]));
        res = max(res, max(right[0], max(right[1], right[2])));
        include[1] = res;

        res = 0;
        if(root->left && root->right && root->val==root->left->val && root->val==root->right->val){
            res = 1 + left[0] + right[0];
        }
        include[2] = res;

        return include;
    }
};

#endif //ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H
//    int arr[] = {};
//    int arr[] = {1,4,5,4,4,5};
//    int arr[] = {5,4,5,1,1,5};
//    int arr[] = {1,4,5,4,4,NULL,5};
//    int n = sizeof(arr)/sizeof(int);
//    TreeNode* root = CreateBinaryTree(arr, n);
//    int res = Solution().longestUnivaluePath(root);
//    cout<<res<<endl;