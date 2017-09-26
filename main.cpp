#include <iostream>
#include "BinaryTree-Recursive/111. Minimum Depth of Binary Tree.h"
using namespace std;

int main() {
//    int tree[] = {0,NULL};
    int tree[] = {0,NULL,4};
//    int tree[] = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
    int size = sizeof(tree)/sizeof(int);
    TreeNode *root = CreateBinaryTree(tree, size);

    int res = Solution().minDepth(root);
    cout<<res<<endl;

    return 0;
}