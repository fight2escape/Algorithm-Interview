//
// Created by Shinelon on 2017/10/4.
//

#ifndef ALGORITHM_INTERVIEW2_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
#define ALGORITHM_INTERVIEW2_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

//        _______6______
//       /              \
//    ___2__          ___8__
//   /      \        /      \
//   0       4       7       9
//          /  \
//          3   5

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==NULL || q==NULL){ return NULL; }
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
//    int arr[] = {6,2,8,0,4,7,9,NULL,NULL,3,5};
//    int n = sizeof(arr)/sizeof(int);
//    TreeNode* root = CreateBinaryTree(arr, n);
//    auto p = new TreeNode(5);
//    auto q = new TreeNode(1);
//    cout << Solution().lowestCommonAncestor(root, p, q)->val << endl;