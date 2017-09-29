//
// Created by Shinelon on 2017/9/29.
//

#ifndef ALGORITHM_INTERVIEW2_337_HOUSE_ROBBER_III_H
#define ALGORITHM_INTERVIEW2_337_HOUSE_ROBBER_III_H

#include "../BinaryTree-Recursive/BinaryTree.h"
#include <unordered_map>

class Solution {
public:
    int rob(TreeNode* root) {
        int* res = __rob(root);
        return max(res[0], res[1]);
    }

private:

    int* __rob(TreeNode* root) {
        int* res = new int[2]{0};
        if(root == NULL){
            return res;
        }

        int* left = __rob(root->left);
        int* right = __rob(root->right);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_337_HOUSE_ROBBER_III_H
