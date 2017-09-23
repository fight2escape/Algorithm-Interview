//
// Created by Shinelon on 2017/9/23.
//

#ifndef ALGORITHM_INTERVIEW2_219_CONTAINS_DUPLICATE_II_H
#define ALGORITHM_INTERVIEW2_219_CONTAINS_DUPLICATE_II_H

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    /**
     * 滑动窗口+搜索表
     * @param nums
     * @param k
     * @return
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i=0; i<n; i++){
            if(set.find(nums[i]) != set.end()){
                return true;
            }
            set.insert(nums[i]);
            if(set.size() == k+1){
                set.erase(nums[i-k]);
            }
        }
        return false;
    }
};

#endif //ALGORITHM_INTERVIEW2_219_CONTAINS_DUPLICATE_II_H
//vector<int> vec = {1,2,1};
//int k = 1;
//
//bool res = Solution().containsNearbyDuplicate(vec,k);
//
//cout<<"res:"<<res<<endl;