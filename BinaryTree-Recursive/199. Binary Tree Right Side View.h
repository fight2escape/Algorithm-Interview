//
// Created by Shinelon on 2017/10/19.
//

#ifndef ALGORITHM_INTERVIEW2_199_BINARY_TREE_RIGHT_SIDE_VIEW_H
#define ALGORITHM_INTERVIEW2_199_BINARY_TREE_RIGHT_SIDE_VIEW_H

#include "BinaryTree.h"
#include <queue>
#include <vector>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        if(!root) return res;
        q.push( make_pair(root, 0) );
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == res.size()){
                res.push_back(node->val);
            }

            if(node->right){
                q.push( make_pair(node->right, level+1) );
            }
            if(node->left){
                q.push( make_pair(node->left, level+1) );
            }
        }
        return res;
    }
};

class Test{
public:
    void test(){
        int arr[] = {1,2,3,NULL,5,NULL,NULL};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        for(auto res : Solution().rightSideView(root)){
            printf("%d ", res);
        }
        cout<<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_199_BINARY_TREE_RIGHT_SIDE_VIEW_H
