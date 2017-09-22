//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_454_4SUM_II_H
#define ALGORITHM_INTERVIEW2_454_4SUM_II_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        for(int i=0; i<C.size(); i++){
            for(int j=0; j<D.size(); j++){
                map[C[i] + D[j]]++;
            }
        }
        int res = 0;
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<B.size(); j++){
                if(map.find(0-A[i]-B[j]) != map.end()){
                    res += map[0-A[i]-B[j]];
                }
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_454_4SUM_II_H
