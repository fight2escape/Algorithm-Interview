//
// Created by Shinelon on 2017/9/27.
//

#ifndef ALGORITHM_INTERVIEW2_70_CLIMBING_STAIRS_H
#define ALGORITHM_INTERVIEW2_70_CLIMBING_STAIRS_H

#include <vector>
using namespace std;

class Solution {
public:

    int climbStairs(int n){
        vector<int> memory(n+1, -1);
        memory[0] = memory[1] = 1;
        for(int i=2; i<=n; i++){
            memory[i] = memory[i-1] + memory[i-2];
        }
        return memory[n];
    }


    /**
     * 递归版
     */
    vector<int> memory;
    int climbStairs1(int n) {
        memory = vector<int>(n+1, -1);
        return calcWays(n);
    }
private:
    int calcWays(int n){
        if(n <= 1){
            return 1;
        }
        if(memory[n] == -1){
            memory[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return memory[n];
    }
};

#endif //ALGORITHM_INTERVIEW2_70_CLIMBING_STAIRS_H
//int n = 2;
//int res = Solution().climbStairs(n);
//cout<<res<<endl;