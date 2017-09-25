//
// Created by Shinelon on 2017/9/25.
//

#ifndef ALGORITHM_INTERVIEW2_145_BINARY_TREE_POSTORDER_TRAVERSAL_H
#define ALGORITHM_INTERVIEW2_145_BINARY_TREE_POSTORDER_TRAVERSAL_H

#include "BinaryTree.h"
#include <stack>

struct Command{
    string s;   // go, print;
    TreeNode* node;
    Command(string str, TreeNode* treeNode):s(str), node(treeNode) {}
};

class Solution {
public:

    /**
     * 迭代实现
     * 模拟系统调度栈执行
     * @param root
     * @return
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<Command> com;
        com.push(Command("go", root));
        while(!com.empty()){
            Command cur = com.top();
            com.pop();
            if(cur.s == "go" && cur.node != NULL){
                com.push(Command("print", cur.node));
                com.push(Command("go", cur.node->right));
                com.push(Command("go", cur.node->left));
            }else if(cur.s == "print"){
                res.push_back(cur.node->val);
            }
        }
        return res;
    }


    /**
     * 递归实现
     * @param root
     * @return
     */
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> res;
        __postorderTraversal(root, res);
        return res;
    }

private:
    void __postorderTraversal(TreeNode *root, vector<int>& res){
        if(root == NULL){
            return;
        }
        __postorderTraversal(root->left, res);
        __postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
};

#endif //ALGORITHM_INTERVIEW2_145_BINARY_TREE_POSTORDER_TRAVERSAL_H
