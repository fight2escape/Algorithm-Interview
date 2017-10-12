//
// Created by Shinelon on 2017/10/12.
//

#ifndef ALGORITHM_INTERVIEW2_202_HAPPY_NUMBER_H
#define ALGORITHM_INTERVIEW2_202_HAPPY_NUMBER_H

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1){
           return true;
        }

        unordered_set<int> happy;
        happy.insert(n);

        while(true){
            int sum=0, cur;
            while(n){
                cur = n%10;
                sum += cur*cur;
                n /= 10;
            }
            n = sum;

            if(n == 1){
                return true;
            }else if(happy.find(n) != happy.end()){
                return false;
            }else{
                happy.insert(n);
            }
        }
    }
};

class Test{
public:
    void test(){
        int n = 19;
        int res = Solution().isHappy(n);
        printf("%d\n", res);
    }
};

#endif //ALGORITHM_INTERVIEW2_202_HAPPY_NUMBER_H
