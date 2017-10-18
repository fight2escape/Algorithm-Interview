//
// Created by Shinelon on 2017/10/18.
//

#ifndef ALGORITHM_INTERVIEW2_二维数组中的查找_H
#define ALGORITHM_INTERVIEW2_二维数组中的查找_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > arr) {
        int row = arr.size()-1;
        int col = 0;
        while(row>=0 && col<arr[row].size()){
            if(arr[row][col] < target){
                col++;
            }else if(arr[row][col] > target){
                row--;
            }else{
                return true;
            }
        }
        return false;
    }
};

class Test{
public:
    void test(){
        int target = 2;
        vector<vector<int>> arr = {{1,2,3,4,5},{3,4,5,6,7}};
        cout<< Solution().Find(target, arr)<<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_二维数组中的查找_H
