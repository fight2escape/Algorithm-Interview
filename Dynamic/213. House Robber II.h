//
// Created by Shinelon on 2017/9/28.
//

#ifndef ALGORITHM_INTERVIEW2_213_HOUSE_ROBBER_II_H
#define ALGORITHM_INTERVIEW2_213_HOUSE_ROBBER_II_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){ return n>0? nums[0] : 0;}
        return max(__rob(nums,0,n-2), __rob(nums,1,n-1));
    }
private:
    int __rob(vector<int> nums, int left, int right){
        int first = 0, second = 0, val = 0;
        for(int i=left; i<=right; i++){
            val = max(first+nums[i], second);
            first = second;
            second = val;
        }
        return val;
    }
};

#endif //ALGORITHM_INTERVIEW2_213_HOUSE_ROBBER_II_H
