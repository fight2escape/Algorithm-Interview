//
// Created by Shinelon on 2017/10/15.
//

#ifndef ALGORITHM_INTERVIEW2_698_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H
#define ALGORITHM_INTERVIEW2_698_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum % k) return false;
        int size = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] > size) return false;

        vector<int> group(k,0);
        return search(group, 0, nums, size);
    }
private:
    /**
     * 遍历nums，依次取出放入K-th个箱中，全放不下即返回false，能全放入即true
     * @param group
     * @param index
     * @param nums
     * @param size
     * @return
     */
    bool search(vector<int>& group, int index, vector<int>& nums, const int &size) {
        if(index == nums.size()) return true;
        int cur = nums[index++];
        for(int i=0, n=group.size(); i<n; ++i){
            if(group[i] + cur <= size){
                group[i] += cur;
                if(search(group, index, nums, size)) return true;
                group[i] -= cur;
            }
        }
        return false;
    }
};

class Test{
public:
    void test(){
//        vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
//        vector<int> nums = {1,5,1,5,2,4};
        vector<int> nums = {-1,0,1};
        int k = 1;
        cout<< Solution().canPartitionKSubsets(nums, k) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_698_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H
