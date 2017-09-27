//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_343_INTEGER_BREAK_H
#define ALGORITHM_INTERVIEW2_343_INTEGER_BREAK_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int integerBreak(int n) {
        vector<int> memo(n+1,0);
        memo[2] = 1;
        int a,b;
        for(int i=3; i<=n; i++){
            for(int j=1; j<=i/2; j++){
                a = max(j, memo[j]);
                b = max(i-j, memo[i-j]);
                memo[i] = max(memo[i], a*b);
            }
        }
        return memo[n];
    }
};

#endif //ALGORITHM_INTERVIEW2_343_INTEGER_BREAK_H
