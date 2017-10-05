//
// Created by Shinelon on 2017/10/5.
//

#ifndef ALGORITHM_INTERVIEW2_77_COMBINATIONS_H
#define ALGORITHM_INTERVIEW2_77_COMBINATIONS_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        if(n<=0 || k<=0 || k>n){
            return res;
        }
        __combine(n, 1, k, {});
        return res;
    }
private:
    vector<vector<int>> res;
    void __combine(int n, int index, int k, vector<int> p) {
        if(k == p.size()){
            res.push_back(p);
            return;
        }
        // 剪枝，从Index开始，后面还需要(k-p.size())个，不够的就不用计算
        for(int i=index; i<=n-(k-p.size())+1; i++){
            p.push_back(i);
            __combine(n, i+1, k, p);
            p.pop_back();
        }
        return;
    }
};

#endif //ALGORITHM_INTERVIEW2_77_COMBINATIONS_H
//    int n = 20;
//    int k = 10;
//    time_t start = clock();
//    vector<vector<int>> res = Solution().combine(n, k);
//    time_t end = clock();
//
//    double spendTime = double(end-start)/(double)CLOCKS_PER_SEC;
//    cout<<res.size()<<endl;
//    cout<<"spendTime: "<<spendTime<<endl;

//    int i=1;
//    for(auto re : res){
//        cout<<i++<<": ";
//        for(auto r:re){
//            cout<<r<<" ";
//        }
//        cout<<endl;
//    }