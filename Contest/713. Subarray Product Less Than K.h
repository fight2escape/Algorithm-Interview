//
// Created by Shinelon on 2017/10/22.
//

#ifndef ALGORITHM_INTERVIEW2_713_SUBARRAY_PRODUCT_LESS_THAN_K_H
#define ALGORITHM_INTERVIEW2_713_SUBARRAY_PRODUCT_LESS_THAN_K_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] >= k) continue;
            int mul = 1;
            for(int j=i; j<nums.size(); ++j){
                mul *= nums[j];
                if(mul >= k) {
                    break;
                }else{
                    res++;
                }
            }
        }
        return res;
    }
};

class Test{
public:
    void test(){
        vector<int> nums = {10, 5, 2, 6};
//        vector<int> nums = {1,1,1};
        int k = 100;
//        int k = 2;
        cout<< Solution().numSubarrayProductLessThanK(nums, k) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_713_SUBARRAY_PRODUCT_LESS_THAN_K_H
