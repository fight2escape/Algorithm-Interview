//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_1_TWO_SUM_H
#define ALGORITHM_INTERVIEW2_1_TWO_SUM_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int rest;
        for(int i=0; i<nums.size(); i++){
            rest = target - nums[i];
            if(map.find(rest) != map.end()){
                int res[2] = {map[rest], i};
                return vector<int>(res, res+2);
            }
            map[nums[i]] = i;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_1_TWO_SUM_H
