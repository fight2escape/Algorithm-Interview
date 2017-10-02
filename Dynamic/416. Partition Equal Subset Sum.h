//
// Created by Shinelon on 2017/10/1.
//

#ifndef ALGORITHM_INTERVIEW2_416_PARTITION_EQUAL_SUBSET_SUM_H
#define ALGORITHM_INTERVIEW2_416_PARTITION_EQUAL_SUBSET_SUM_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 迭代版
     * @param nums
     * @return
     */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if(sum % 2 != 0){ return false; }
        sum /= 2;
        vector<int> res(sum+1, -1);
        for(int i=0; i<=sum; i++){
            res[i] = i < nums[0] ? 0 : nums[0];
        }
        for(int i=1,n=nums.size(); i<n; i++){
            for(int j=sum; j>=nums[i]; j--){
                res[j] = max(res[j], nums[i] + res[ j-nums[i] ]);
            }
        }
        return res[sum]==sum;
    }

    /**
     * 递归版
     * @param nums
     * @return
     */
    bool canPartition1(vector<int>& nums) {
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        if(sum % 2 != 0){ return false; }
        sum /=2;
        memo = vector<vector<int>>(nums.size(), vector<int>(sum+1, -1));
        return __canPartition(nums, nums.size()-1, sum);
    }
private:
    /**
     * memo[index][c] 表示，[0,index]中是否存在和为c的组合
     * -1 表示未计算，0表示没有，1表示有
     */
    vector<vector<int>> memo;

    /**
     * 看能否从[0,right]之间找到和为sum的数
     * @param nums
     * @param right
     * @param sum
     * @return
     */
    bool __canPartition(vector<int> nums, int right, int sum){
        if(right < 0 || sum < 0){ return false; }
        if(sum == 0){ return true; }

        if(memo[right][sum] != -1){ return memo[right][sum] == 1; }
        memo[right][sum] = (__canPartition(nums, right-1, sum) || __canPartition(nums, right-1, sum-nums[right])) ? 1 : 0;

        return memo[right][sum] == 1;
    }
};

#endif //ALGORITHM_INTERVIEW2_416_PARTITION_EQUAL_SUBSET_SUM_H
//    vector<int> vec = {1,5,11,5};
//    vector<int> vec = {1,2,3,8};
//    vector<int> vec = {1,2,5};
//    cout<< Solution().canPartition(vec) <<endl;