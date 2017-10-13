
//
// Created by Shinelon on 2017/10/13.
//

#ifndef ALGORITHM_INTERVIEW2_113_PATH_SUM_II_H
#define ALGORITHM_INTERVIEW2_113_PATH_SUM_II_H

#include "BinaryTree.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        if(!root){
            return res;
        }
        vector<int> p;
        __pathSum(root, sum, p);
        return res;
    }

private:
    vector<vector<int>> res;
    void __pathSum(const TreeNode* root, const int sum, vector<int> &p){
        if(root && root->val==sum && !root->left && !root->right){
            p.push_back(root->val);
            res.push_back(p);
            p.pop_back();
        }else{
            int val = root->val;
            if(root->left){
                p.push_back(val);
                __pathSum(root->left, sum - val, p);
                p.pop_back();
            }
            if(root->right){
                p.push_back(val);
                __pathSum(root->right, sum - val, p);
                p.pop_back();
            }
        }
        return;
    }
};

class Test{
public:
    void test(){
//        int arr[] = {1,2};
        int arr[] = {-2, NULL, -3};
//        int sum = 1;
        int sum = -5;
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        for(auto res : Solution().pathSum(root, sum)){
            for(auto r : res){
                printf("%d -> ", r);
            }
            printf("NULL\n");
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_113_PATH_SUM_II_H
