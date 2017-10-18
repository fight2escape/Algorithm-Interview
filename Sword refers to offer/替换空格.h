//
// Created by Shinelon on 2017/10/18.
//

#ifndef ALGORITHM_INTERVIEW2_替换空格_H
#define ALGORITHM_INTERVIEW2_替换空格_H

#include <iostream>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        char *cur = str;
        int count = 0;
        int oldLength = 0;
        while(*cur!='\0'){
            ++oldLength;
            if(*cur == ' '){
                ++count;
            }
            ++cur;
        }
        count = 2*count + oldLength;
        if(count > length) return ;

        char *p1 = str + oldLength;
        char *p2 = str + count;

        while(p1 < p2){
            if(*p1 == ' '){
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            }else{
                *p2-- = *p1;
            }
            --p1;
        }
    }
};

class Test{
public:
    void test(){
        int length = 20;
        char str[] = "We are happy";
        Solution().replaceSpace(str, length);
        cout<<str<<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_替换空格_H
