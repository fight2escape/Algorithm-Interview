//
// Created by Shinelon on 2017/10/1.
//

#ifndef ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H
#define ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H

#include "../BinaryTree-Recursive/BinaryTree.h"

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int grup = 0;
        if(root) __longestUnivaluePath(root, grup);
        return grup;
    }
private:
    int __longestUnivaluePath(TreeNode* root, int& grup){
        int left = root->left ? __longestUnivaluePath(root->left, grup) : 0;
        int right = root->right ? __longestUnivaluePath(root->right, grup) : 0;
        int resl = root->left && root->left->val == root->val ? left+1 : 0;
        int resr = root->right && root->right->val == root->val ? right+1 : 0;
        grup = max(grup, resl + resr);
        return max(resl, resr);
    }
};

class Test{
public:
    void test(){
//        int arr[] = {1,4,5,4,4,NULL,5};
        int arr[] = {1,1,1,1,1,NULL,5};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        int res = Solution().longestUnivaluePath(root);
        cout<<res<<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_687_LONGEST_UNIVALUE_PATH_H