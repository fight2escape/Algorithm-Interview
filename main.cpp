#include<iostream>
#include<iomanip>
#include "Dynamic/309. Best Time to Buy and Sell Stock with Cooldown.h"

using namespace std;

int main(){

    vector<int> vec = {1,2,3,0,2};
    int res = Solution().maxProfit(vec);
    cout<<res<<endl;

    return 0;
}