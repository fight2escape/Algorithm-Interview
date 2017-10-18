//
// Created by Shinelon on 2017/10/18.
//

#ifndef ALGORITHM_INTERVIEW2_18_4SUM_H
#define ALGORITHM_INTERVIEW2_18_4SUM_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0, n=nums.size(); i<n-3; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            // 转化为3sum问题
            int three = target - nums[i];
            for(int j=i+1; j<n-2; ++j){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                // 转化为2sum问题
                int two = three - nums[j];
                int lt=j+1, gt=n-1;
                while(lt < gt){
                    if(nums[lt] + nums[gt] > two){
                        --gt;
                    }
                    else if(nums[lt] + nums[gt] < two){
                        ++lt;
                    }
                    else {
                        res.emplace_back( vector<int>{nums[i], nums[j], nums[lt], nums[gt]});
                        // 先移动，再跳过重复值
                        do{ ++lt; }while(lt < gt && nums[lt] == nums[lt-1]);
                        do{ --gt; }while(lt < gt && nums[gt] == nums[gt+1]);
                    }
                }
            }
        }
        return res;
    }
};

class Test{
public:
    void test(){
//        vector<int> nums = {1, 0, -1, 0, -2, 2};
//        vector<int> nums = {0, 0, 0, 0, 0};
        vector<int> nums = {-3,-2,-1,0,0,1,2,3};
//        vector<int> nums = {-1,0,1,2,-1,-4};
//        int target = -1;
        int target = 0;
        for(auto res : Solution().fourSum(nums, target)){
            for(auto r : res){
                printf("%d ", r);
            }
            printf("\n");
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_18_4SUM_H
