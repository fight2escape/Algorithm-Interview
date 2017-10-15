//
// Created by Shinelon on 2017/10/15.
//

#ifndef ALGORITHM_INTERVIEW2_697_DEGREE_OF_AN_ARRAY_H
#define ALGORITHM_INTERVIEW2_697_DEGREE_OF_AN_ARRAY_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for(int i=0,n=nums.size(); i<n; ++i){
            map[ nums[i] ].push_back(i);
        }
        int maxl = 0;
        for(auto iter=map.begin(); iter!=map.end(); ++iter){
            maxl = max(maxl, (int)iter->second.size());
        }
        int minl = nums.size();
        for(auto iter=map.begin(); iter!=map.end(); ++iter){
            if(maxl == iter->second.size()){
                minl = min(minl, iter->second.back() - iter->second[0] + 1);
            }
        }
        return minl;
    }
};

class Test{
public:
    void test(){
//        vector<int> nums = {1, 2, 2, 3, 1};
        vector<int> nums = {-1,1,1,1,2,-1};
        cout << Solution().findShortestSubArray(nums) <<endl;
    }
};
#endif //ALGORITHM_INTERVIEW2_697_DEGREE_OF_AN_ARRAY_H
