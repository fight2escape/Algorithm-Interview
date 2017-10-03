//
// Created by Shinelon on 2017/10/3.
//

#ifndef ALGORITHM_INTERVIEW2_583_DELETE_OPERATION_FOR_TWO_STRINGS_H
#define ALGORITHM_INTERVIEW2_583_DELETE_OPERATION_FOR_TWO_STRINGS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * DP
     * @param word1
     * @param word2
     * @return
     */
    int minDistance(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        return (sz1+sz2) - 2*LCS(word1, word2);
    }

    /**
     * 递归解法
     * @param word1
     * @param word2
     * @return
     */
    int minDistance1(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        memo = vector<vector<int>>(sz1, vector<int>(sz2,-1));
        return (sz1 + sz2) - 2*lcs(word1, sz1-1, word2, sz2-1);
    }
private:

    /**
     * 求最长公共子序列(DP)
     * @param word1
     * @param word2
     * @return
     */
    int LCS(string word1, string word2){
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> memo(sz1+1, vector<int>(sz2+1,0));
        for(int i=1; i<=sz1; i++){
            for(int j=1; j<=sz2; j++){
                if(word1[i-1] == word2[j-1]){
                    memo[i][j] = memo[i-1][j-1] + 1;
                }else{
                    memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
                }
            }
        }
        return memo[sz1][sz2];
    }


    /**
     * 表示word1中的[0,n]和word2中[0,m]两段的LCS
     */
    vector<vector<int>> memo;
    /**
     * 求最长公共子序列(递归)
     * @param word1
     * @param n
     * @param word2
     * @param m
     * @return
     */
    int lcs(string word1, int n, string word2, int m) {
        if(n<0 || m<0){ return 0;}
        if(memo[n][m] != -1){ return memo[n][m]; }
        int res;
        if(word1[n] == word2[m]){
            res = 1 + lcs(word1, n-1, word2, m-1);
        }else{
            res = max(lcs(word1, n, word2, m-1), lcs(word1, n-1, word2, m));
        }
        memo[n][m] = res;
        return memo[n][m];
    }
};

#endif //ALGORITHM_INTERVIEW2_583_DELETE_OPERATION_FOR_TWO_STRINGS_H
//    string str1 = "sea";
//    string str2 = "eat";
//    cout<< Solution().minDistance(str1, str2)<<endl;