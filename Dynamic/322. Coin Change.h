//
// Created by Shinelon on 2017/10/2.
//

#ifndef ALGORITHM_INTERVIEW2_322_COIN_CHANGE_H
#define ALGORITHM_INTERVIEW2_322_COIN_CHANGE_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 其中F(i,amount)表示，加入第i个钱币后，组成amount的钱的最少数量，p为第i个钱币的价值
     * F(i, amount) = min( F(i-1,amount), 1 + F(i,amount-p)) )
     * 这里使用一行记录，从左向右更新值，因为比较的是本行已经计算好的值，需要和01背包区分
     * @param coins
     * @param amount
     * @return
     */
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){ return 0; }
        sort(coins.begin(), coins.end());
        vector<int> res(amount+1, amount);
        res[0] = 0;
        for(int i=0, n=coins.size(); i<n; i++){
            for(int j=coins[i]; j<=amount; j++){
                res[j] = min(res[j], 1+res[ j-coins[i] ]);
            }
        }
        if(res[amount] == amount){
            return coins[0]==1 ? amount : -1;
        }
        return res[amount];
    }
};

#endif //ALGORITHM_INTERVIEW2_322_COIN_CHANGE_H
//    vector<int> vec = {1,2,5};
//    int amount = 11;
//    vector<int> vec = {1};
//    int amount = 1;
//    cout<< Solution().coinChange(vec, amount) <<endl;