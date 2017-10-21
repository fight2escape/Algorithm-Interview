//
// Created by Shinelon on 2017/10/21.
//

#ifndef ALGORITHM_INTERVIEW2_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
#define ALGORITHM_INTERVIEW2_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBst(nums, 0, nums.size()-1);
    }
private:
    TreeNode* toBst(vector<int>& nums, int l, int r) {
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        if((r-l)%2) mid += 1;
        auto* node = new TreeNode(nums[mid]);
        node->left = toBst(nums, l, mid-1);
        node->right = toBst(nums, mid+1, r);
        return node;
    }
};

class Test{
public:
    void test(){
        vector<int> nums = {1,2,3,4,5};
        TreeNode* res = Solution().sortedArrayToBST(nums);
        InorderBST(res);
    }
};

#endif //ALGORITHM_INTERVIEW2_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
