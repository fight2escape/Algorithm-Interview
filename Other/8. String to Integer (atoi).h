//
// Created by Shinelon on 2017/10/14.
//

#ifndef ALGORITHM_INTERVIEW2_8_STRING_TO_INTEGER_ATOI_H
#define ALGORITHM_INTERVIEW2_8_STRING_TO_INTEGER_ATOI_H

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int flag = 1;
        while(str[i] == ' '){ ++i; }
        if(str[i]=='+' || str[i]=='-'){
            flag = str[i]=='-' ? -1 : 1;
            ++i;
        }else if(str[i]<'0' || str[i]>'9'){
            return 0;
        }
        long long res = 0;
        while(str[i]>='0' && str[i]<='9'){
            res = res*10 + str[i++]-'0';
            if(res*flag > INT32_MAX){ return INT32_MAX; }
            else if(res*flag < INT32_MIN){ return INT32_MIN; }
        }
        return (int)res*flag;
    }
};

class Test{
public:
    void test(){
//        string str = "-   0  1 0";
//        string str = "      +004500";
//        string str = "  -0012a42123213233";
//        string str = "  -001 2a4";
//        string str = "-2147483647";
        string str = "  1  ";
        int res = Solution().myAtoi(str);
        printf("%d \n", res);
    }
};

#endif //ALGORITHM_INTERVIEW2_8_STRING_TO_INTEGER_ATOI_H
