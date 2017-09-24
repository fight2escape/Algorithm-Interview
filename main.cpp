#include <iostream>
#include "Stack-Queue/144. Binary Tree Preorder Traversal.h"
using namespace std;

int main() {

    TreeNode *root = CreateBinaryTree();
    vector<int> res = Solution().preorderTraversal(root);

    for(auto i=res.begin(); i!=res.end(); i++){
        cout<<*i<<" ";
    }

    return 0;
}