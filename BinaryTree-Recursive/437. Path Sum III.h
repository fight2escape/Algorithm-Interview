//
// Created by Shinelon on 2017/10/4.
//

#ifndef ALGORITHM_INTERVIEW2_437_PATH_SUM_III_H
#define ALGORITHM_INTERVIEW2_437_PATH_SUM_III_H

#include "BinaryTree.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        res += __pathSum(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
private:
    int __pathSum(TreeNode* node, int count) {
        if(node == NULL){
            return 0;
        }
        int res = 0;
        if(node->val == count){
            res += 1;
        }

        res += __pathSum(node->left, count - node->val);
        res += __pathSum(node->right, count - node->val);

        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_437_PATH_SUM_III_H
//    int arr[] = {10,5,-3,3,2,NULL,11,3,-2,NULL,1};
//    int arr[] = {1,1,1};
//    int n = sizeof(arr)/sizeof(int);
//    TreeNode* root = CreateBinaryTree(arr, n);
//    cout << Solution().pathSum(root, 8) << endl;