//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_257_BINARY_TREE_PATHS_H
#define ALGORITHM_INTERVIEW2_257_BINARY_TREE_PATHS_H

#include "BinaryTree.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL){
            return res;
        }
        vector<int> path;
        return __binaryTreePaths(root, path, res);
    }

private:
    vector<string> __binaryTreePaths(TreeNode* root, vector<int> path, vector<string>& res) {
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            string str;
            for(int i=0; i<path.size(); i++){
                if(i>0){
                    str += "->";
                }
                str += to_string(path[i]);
            }
            res.push_back(str);
        }
        if(root->left){
            __binaryTreePaths(root->left, path, res);
        }
        if(root->right){
            __binaryTreePaths(root->right, path, res);
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_257_BINARY_TREE_PATHS_H
