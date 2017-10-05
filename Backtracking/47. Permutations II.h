//
// Created by Shinelon on 2017/10/5.
//

#ifndef ALGORITHM_INTERVIEW2_47_PERMUTATIONS_II_H
#define ALGORITHM_INTERVIEW2_47_PERMUTATIONS_II_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        used = vector<bool>(nums.size(), false);
        if(nums.empty()){
            return res;
        }
        sort(nums.begin(), nums.end());
        __permuteUnique(nums, 0, {});
        return res;
    }
private:
    vector<vector<int>> res;
    vector<bool> used;
    void __permuteUnique(vector<int> nums, int index, vector<int> p) {
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        // access中保存已经被使用过的元素，后续的元素如果已经在其中存在，则不进行递归调用
        // 局部变量，只对本层的循环有效
        unordered_set<int> access;
        for(int i=0, n=nums.size(); i<n; i++){
            if(!used[i] && access.find(nums[i])==access.end()){
                p.push_back(nums[i]);
                used[i] = true;
                access.insert(nums[i]);
                __permuteUnique(nums, index+1, p);
                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }
};

#endif //ALGORITHM_INTERVIEW2_47_PERMUTATIONS_II_H
