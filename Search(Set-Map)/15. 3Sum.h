//
// Created by Shinelon on 2017/10/16.
//

#ifndef ALGORITHM_INTERVIEW2_15_3SUM_H
#define ALGORITHM_INTERVIEW2_15_3SUM_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0, n=nums.size(); i<n-2; ++i){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int tg = -1 * nums[i], lt = i+1, gt = n-1;
                while(lt < gt){
                    if(nums[lt] + nums[gt] > tg){
                        gt--;
                    }else if(nums[lt] + nums[gt] < tg){
                        lt++;
                    }else{
                        res.emplace_back( vector<int>{nums[i], nums[lt], nums[gt]} );
                        while(lt < gt && nums[++lt] == nums[lt-1]){}
                        while(lt < gt && nums[--gt] == nums[gt+1]){}
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
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> res = Solution().threeSum(nums);
        for(auto re : res){
            printf("[");
            for(auto r : re){
                printf("%d, ",r);
            }
            printf("]\n");
        }
    }
};
#endif //ALGORITHM_INTERVIEW2_15_3SUM_H
