//
// Created by Shinelon on 2017/10/19.
//

#ifndef ALGORITHM_INTERVIEW2_16_3SUM_CLOSEST_H
#define ALGORITHM_INTERVIEW2_16_3SUM_CLOSEST_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sub = INT32_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int lt = i+1, gt = nums.size()-1;
            while(lt < gt){
                int sum = nums[i] + nums[lt] + nums[gt];
                if(sum == target) return target;

                int tmp = abs(target-sum);
                if(sub > tmp){
                    sub = tmp;
                    res = sum;
                }

                if(sum < target){
                    ++lt;
                }else{
                    --gt;
                }
            }
        }
        return res;
    }
};

class Test{
public:
    void test(){
//        vector<int> nums = {1,1,1,0};
        vector<int> nums = {0,2,1,-3};
//        int target = 100;
        int target = 1;
        cout << Solution().threeSumClosest(nums, target) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_16_3SUM_CLOSEST_H
