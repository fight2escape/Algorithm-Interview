//
// Created by Shinelon on 2017/9/30.
//

#ifndef ALGORITHM_INTERVIEW2_309_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
#define ALGORITHM_INTERVIEW2_309_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0){ return 0;}
        int preSell=0, sell=0, preBuy, buy=0-prices[0];
        for(int p : prices){
            preBuy = buy;
            buy = max(preBuy, preSell-p);
            preSell = sell;
            sell = max(sell, preBuy+p);
        }
        return sell;
    }
};

#endif //ALGORITHM_INTERVIEW2_309_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
//vector<int> vec = {1,2,3,0,2};
//int res = Solution().maxProfit(vec);
//cout<<res<<endl;