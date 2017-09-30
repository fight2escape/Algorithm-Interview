//
// Created by Shinelon on 2017/9/30.
//

#ifndef ALGORITHM_INTERVIEW2_0_1_BAG_H
#define ALGORITHM_INTERVIEW2_0_1_BAG_H

#include <iostream>
#include <vector>
using namespace std;

class Knapsack01{
public:

    /**
     * 0-1背包：迭代版
     * @param w
     * @param v 
     * @param c
     * @return
     */
    int knapsack01_2(const vector<int> &w, const vector<int> &v, int c){
        int n = w.size();
        vector<vector<int>> res(n, vector<int>(c+1, -1));
        for(int i=0; i<=c; i++){
            res[0][i] = i<w[0] ? 0 : v[0];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=c; j++){
                if(j < w[i]){
                    res[i][j] = res[i-1][j];
                }else{
                    res[i][j] = max(res[i-1][j], v[i]+res[i-1][ j-w[i] ]);
                }
            }
        }
        return res[n-1][c];
    }

    /**
     * 0-1背包：递归版
     */

    int knapsack01_1(const vector<int> &w, const vector<int> &v, int c){
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(c+1, -1));
        return bestValue(w, v, n-1, c);
    }
private:
    vector<vector<int>> memo;

    int bestValue(const vector<int> &w, const vector<int> &v, int index, int c){
        if(index < 0 || c <= 0){
            return 0;
        }
        if(memo[index][c] != -1){
            return memo[index][c];
        }
        int res = bestValue(w, v, index-1, c);
        if(w[index] <= c){
            res = max(res, v[index] + bestValue(w, v, index-1, c-w[index]));
        }
        memo[index][c] = res;
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_0_1_BAG_H
