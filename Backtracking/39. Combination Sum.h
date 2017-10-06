//
// Created by Shinelon on 2017/10/6.
//

#ifndef ALGORITHM_INTERVIEW2_39_COMBINATION_SUM_H
#define ALGORITHM_INTERVIEW2_39_COMBINATION_SUM_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end());
        __combinationSum(candidates, target, 0);
        return res;
    }
private:
    vector<int> tmp;
    vector<vector<int>> res;

    void __combinationSum(const vector<int>& cd, const int target, int index){
        if(!target){
            res.push_back(tmp);
            return ;
        }
        for(int i=index,n=cd.size(); i<n && cd[i] <= target; i++){
            tmp.push_back(cd[i]);
            __combinationSum(cd, target-cd[i], i);
            tmp.pop_back();
        }
        return ;
    }
};

class Test{
public:
    void test(){
//        vector<int> vec = {2, 3, 6, 7};
//        int target = 7;
        vector<int> vec = {8,7,4,3};
        int target = 11;
        vector<vector<int>> res = Solution().combinationSum(vec, target);
        for(auto re : res){
            for(auto r : re){
                cout<< r <<" ";
            }
            cout<<endl;
        }
        return ;
    }
};

#endif //ALGORITHM_INTERVIEW2_39_COMBINATION_SUM_H
