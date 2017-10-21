//
// Created by Shinelon on 2017/10/21.
//

#ifndef ALGORITHM_INTERVIEW2_40_COMBINATION_SUM_II_H
#define ALGORITHM_INTERVIEW2_40_COMBINATION_SUM_II_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end(), greater<int>());
        if(candidates.empty() || candidates.back() > target || accumulate(candidates.begin(), candidates.end(), 0) < target) return res;
        dfs(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int>& candidates, int target, int index) {
        if(target == 0){
            res.push_back(tmp);
            return ;
        }
        for(int i=index, n=candidates.size(); i<n; ++i){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) continue;
            tmp.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1);
            tmp.pop_back();
        }
    }
};

class Test{
public:
    void test(){
//        vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
        vector<int> candidates = {};
        int target = 2;
        for(auto res : Solution().combinationSum2(candidates, target)){
            for(auto r : res){
                cout<<r<<" ";
            }
            cout<<endl;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_40_COMBINATION_SUM_II_H
