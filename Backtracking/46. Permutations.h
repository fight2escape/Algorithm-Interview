//
// Created by Shinelon on 2017/10/5.
//

#ifndef ALGORITHM_INTERVIEW2_46_PERMUTATIONS_H
#define ALGORITHM_INTERVIEW2_46_PERMUTATIONS_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        used = vector<bool>(nums.size(), false);
        if(nums.empty()){
            return res;
        }
        __permute(nums, 0, {});
        return res;
    }
private:
    vector<vector<int>> res;
    vector<bool> used;
    void __permute(vector<int> nums, int index, vector<int> p) {
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        for(int i=0, n=nums.size(); i<n; i++){
            if(!used[i]){
                p.push_back(nums[i]);
                used[i] = true;
                __permute(nums, index+1, p);
                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }
};

#endif //ALGORITHM_INTERVIEW2_46_PERMUTATIONS_H
//    vector<int> vec = {0,-1,1};
//    vector<int> vec = {0,2,1};
//
//    time_t start = clock();
//    vector<vector<int>> res = Solution().permute(vec);
//    time_t end = clock();
//
//    double spendTime = double(end-start)/(double)CLOCKS_PER_SEC;
//    cout<<res.size()<<endl;
//    cout<<"spendTime: "<<spendTime<<endl;
//
//    for(auto re : res){
//        for(auto r:re){
//            cout<<r;
//        }
//        cout<<endl;
//    }