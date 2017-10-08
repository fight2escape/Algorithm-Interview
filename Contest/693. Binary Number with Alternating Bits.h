//
// Created by Shinelon on 2017/10/8.
//

#ifndef ALGORITHM_INTERVIEW2_693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H
#define ALGORITHM_INTERVIEW2_693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag;
        flag = n&1 ? true : false;
        while(n){
            if(!flag && !(n&1)){
                flag = true;
            }else if(flag && n&1){
                flag = false;
            }else{
                return false;
            }
            n>>=1;
        }
        return true;
    }
};

class Test{
public:
    void test(){
        int n=1;
        cout<< Solution().hasAlternatingBits(n) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H
