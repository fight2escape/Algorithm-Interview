//
// Created by Shinelon on 2017/10/22.
//

#ifndef ALGORITHM_INTERVIEW2_712_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H
#define ALGORITHM_INTERVIEW2_712_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i=1; i<=s2.size(); ++i){
            dp[0][i] = dp[0][i-1] + (int)s2[i-1];
        }
        for(int i=1; i<=s1.size(); ++i){
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
            for(int j=1; j<=s2.size(); ++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j]+(int)s1[i-1], dp[i][j-1]+(int)s2[j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

class Test{
public:
    void test(){
        string s1 = "";
        string s2 = "";
        cout<< Solution().minimumDeleteSum(s1, s2) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_712_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H
