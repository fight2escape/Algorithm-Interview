//
// Created by Shinelon on 2017/10/13.
//

#ifndef ALGORITHM_INTERVIEW2_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
#define ALGORITHM_INTERVIEW2_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H

#include "BinaryTree.h"
#include <queue>
#include <algorithm>


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        if(!root){ return res; }
        q.push( make_pair(root, 0) );
        while(!q.empty()){
            TreeNode* first = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == res.size()){
                res.emplace_back(vector<int>());
            }
            res[level].push_back(first->val);

            if(first->left){
                q.push( make_pair(first->left, level+1) );
            }
            if(first->right){
                q.push( make_pair(first->right, level+1) );
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Test{
public:
    void test(){
        TreeNode* root = CreateBinaryTree();
        for(auto res : Solution().levelOrderBottom(root)){
            for(auto r : res){
                cout<<r<<" -> ";
            }
            cout<<"NULL"<<endl;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
