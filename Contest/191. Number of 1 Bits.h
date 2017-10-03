//
// Created by Shinelon on 2017/10/3.
//

#ifndef ALGORITHM_INTERVIEW2_191_NUMBER_OF_1_BITS_H
#define ALGORITHM_INTERVIEW2_191_NUMBER_OF_1_BITS_H

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n){
            if(n&1) sum++;
            n >>= 1;
        }
        return sum;
    }
};

#endif //ALGORITHM_INTERVIEW2_191_NUMBER_OF_1_BITS_H
