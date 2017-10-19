//
// Created by Shinelon on 2017/10/19.
//

#ifndef ALGORITHM_INTERVIEW2_222_COUNT_COMPLETE_TREE_NODES_H
#define ALGORITHM_INTERVIEW2_222_COUNT_COMPLETE_TREE_NODES_H

#include "BinaryTree.h"
#include <queue>

class Solution {
public:

    /**
     * 左右子树深度相同则直接计算，否则递归
     * 位运算代替pow性能翻番
     * @param root
     * @return 
     */
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl = 0, hr = 0;
        TreeNode* rl = root, *rr = root;
        while(rl){
            ++hl;
            rl = rl->left;
        }
        while(rr){
            ++hr;
            rr = rr->right;
        }
        if(hl == hr){
            return (1<<hl) - 1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    /**
     * 递归超时
     * @param root
     * @return
     */
    int countNodes1(TreeNode* root) {
        if(!root) return 0;
        return countNodes1(root->left) + countNodes1(root->right) + 1;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,3};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        cout<< Solution().countNodes(root) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_222_COUNT_COMPLETE_TREE_NODES_H
