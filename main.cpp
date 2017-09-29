#include<iostream>
#include<iomanip>
#include "Dynamic/337. House Robber III.h"

using namespace std;

int main(){

//    int arr[] = {3,2,3,NULL,3,NULL,1};
//    int arr[] = {3,4,5,1,3,NULL,1};
    int arr[] = {3,4,5};
    int n= sizeof(arr)/sizeof(int);
    TreeNode* root = CreateBinaryTree(arr, n);
    int res = Solution().rob(root);
    cout<<res<<endl;

    return 0;
}