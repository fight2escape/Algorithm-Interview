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
     * 一行记录
     * 时间复杂度：O(n*C)
     * 空间复杂度：O(C)
     * @param w
     * @param v
     * @param c
     * @return
     */
    int knapsack01(const vector<int> &w, const vector<int> &v, int c){
        int n = w.size();
        vector<int> res(c+1, -1);
        for(int i=0; i<=c; i++){
            res[i] = w[0]<c ? 0 : v[0];
        }
        for(int i=1; i<n; i++){
            for(int j=w[i]; j<=c; j++){
                res[j] = max(res[j], v[i] + res[ j-w[i] ]);
            }
        }
        return res[c];
    }

    /**
     * 0-1背包：迭代版
     * 两行记录
     * 时间复杂度：O(n*C)
     * 空间复杂度：O(C)
     * @param w
     * @param v
     * @param c
     * @return
     */
    int knapsack01_3(const vector<int> &w, const vector<int> &v, int c){
        int n = w.size();
        vector<vector<int>> res(2, vector<int>(c+1, -1));
        for(int i=0; i<=c; i++){
            res[0][i] = i<w[0] ? 0 : v[0];
        }

        for(int i=1; i<n; i++){
            int cur = i%2;
            int pre = cur==0 ? 1 : 0;
            for(int j=0; j<=c; j++){
                if(j < w[i]){
                    res[cur][j] = res[pre][j];
                }else{
                    res[cur][j] = max(res[pre][j], v[i]+res[pre][ j-w[i] ]);
                }
            }
        }
        return res[(n-1)%2][c];
    }


    /**
     * 0-1背包：迭代版
     * 时间复杂度：O(n*C)
     * 空间复杂度：O(n*C)
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
