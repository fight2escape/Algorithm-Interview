//
// Created by Shinelon on 2017/9/25.
//

#ifndef ALGORITHM_INTERVIEW2_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define ALGORITHM_INTERVIEW2_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "BinaryTree.h"
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue< pair<TreeNode*,int> > que;
        que.push(make_pair(root,0));
        while( !que.empty() ){
            TreeNode* node = que.front().first;
            int level =  que.front().second;
            que.pop();

            if( level == res.size() ){
                res.push_back( vector<int>() );
            }
            res[level].push_back(node->val);
            if(node->left){
                que.push( make_pair(node->left, level+1) );
            }
            if(node->right){
                que.push( make_pair(node->right, level+1) );
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
