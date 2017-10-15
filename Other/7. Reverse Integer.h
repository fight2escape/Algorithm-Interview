
//
// Created by Shinelon on 2017/10/14.
//

#ifndef ALGORITHM_INTERVIEW2_7_REVERSE_INTEGER_H
#define ALGORITHM_INTERVIEW2_7_REVERSE_INTEGER_H

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res=0;
        while(x){
            res = res*10 + x%10;
            x /= 10;
        }
        return (res>INT32_MAX || res<INT32_MIN) ? 0 : (int)res;
    }
};

class Test{
public:
    void test(){
        int n = 10;
//        int n = -1234567894;
        int res = Solution().reverse(n);
        printf("%d \n", res);
    }
};

#endif //ALGORITHM_INTERVIEW2_7_REVERSE_INTEGER_H
