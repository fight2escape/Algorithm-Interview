//
// Created by Shinelon on 2017/10/16.
//

#ifndef ALGORITHM_INTERVIEW2_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define ALGORITHM_INTERVIEW2_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

#include "BinaryTree.h"
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue< pair<int, TreeNode*> > q;
        q.push( make_pair(0, root) );

        while(!q.empty()){
            TreeNode* cur = q.front().second;
            int level = q.front().first;
            q.pop();

            if(level == res.size()){
                res.emplace_back( vector<int>() );
            }
            res[level].push_back( cur->val );
            if(cur->left){
                q.push( make_pair(level+1, cur->left) );
            }
            if(cur->right){
                q.push( make_pair(level+1, cur->right) );
            }
        }
        for(int i=0, n=res.size(); i<n; ++i){
            if(i%2){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};

class Test{
public:
    void test(){
        int arr[] = {3,9,20,NULL,NULL,15,7};
        int n = sizeof(arr)/sizeof(int);
        TreeNode* root = CreateBinaryTree(arr, n);
        for(auto res : Solution().zigzagLevelOrder(root)){
            printf("[ ");
            for(auto r : res){
                printf("%d ", r);
            }
            printf(" ]\n");
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
