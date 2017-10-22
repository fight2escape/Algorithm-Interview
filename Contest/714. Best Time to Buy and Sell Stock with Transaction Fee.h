//
// Created by Shinelon on 2017/10/22.
//

#ifndef ALGORITHM_INTERVIEW2_714_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
#define ALGORITHM_INTERVIEW2_714_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> sell(n+1, 0) , buy(n+1, 0);
        buy[1] = 0 - prices[0];
        for(int i=1; i<n; ++i){
            int j = i+1;
            sell[j] = max(buy[j-1]+prices[i]-fee, sell[j-1]);
            buy[j] = max(buy[j-1], max(sell[j-2]-prices[i], sell[j-1]-prices[i]));
        }
        return sell[n];
    }
};

class Test{
public:
    void test(){
        vector<int> prices = {1, 3, 2, 8, 4,3,2};
        int fee = 2;
        cout<< Solution().maxProfit(prices, fee) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_714_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
