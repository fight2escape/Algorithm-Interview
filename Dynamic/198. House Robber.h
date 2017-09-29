//
// Created by Shinelon on 2017/9/28.
//

#ifndef ALGORITHM_INTERVIEW2_198_HOUSE_ROBBER_H
#define ALGORITHM_INTERVIEW2_198_HOUSE_ROBBER_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0){ return 0; }
        if(n >= 2 && nums[0] > nums[1]){
            nums[1] = nums[0];
        }
        for(int i=2; i<n; i++){
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        return nums[n-1];
    }
};

#endif //ALGORITHM_INTERVIEW2_198_HOUSE_ROBBER_H
