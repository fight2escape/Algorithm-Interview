//
// Created by Shinelon on 2017/10/2.
//

#ifndef ALGORITHM_INTERVIEW2_300_LONGEST_INCREASING_SUBSEQUENCE_H
#define ALGORITHM_INTERVIEW2_300_LONGEST_INCREASING_SUBSEQUENCE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n<=0 ) { return 0; }
        vector<int> res(n, 1);
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    res[i] = max(res[i], 1+res[j]);
                }
            }
        }
        int ret = 0;
        for(int r : res){
            ret = max(r, ret);
        }
        return ret;
    }
};

#endif //ALGORITHM_INTERVIEW2_300_LONGEST_INCREASING_SUBSEQUENCE_H
//    vector<int> vec = {10, 9, 2, 5, 3, 7, 101, 18};
//    cout<< Solution().lengthOfLIS(vec) <<endl;