//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_344_REVERSE_STRING_H
#define ALGORITHM_INTERVIEW2_344_REVERSE_STRING_H

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    /**
     * 对撞指针
     * @param s
     * @return
     */
    string reverseString1(string s) {
        int st = 0, end = s.length()-1;
        while(st < end){
            swap(s[st++], s[end--]);
        }
        return s;
    }
};

#endif //ALGORITHM_INTERVIEW2_344_REVERSE_STRING_H
//string s2 = "aA";
//string s3 = "aaP";
//string s4 = "ab2a";
//string s5 = "a";
//string res2 = Solution().reverseString(s2);
//string res3 = Solution().reverseString(s3);
//string res4 = Solution().reverseString(s4);
//string res5 = Solution().reverseString(s5);
//cout<<"reverse to : "<< res2 <<endl;
//cout<<"reverse to : "<< res3 <<endl;
//cout<<"reverse to : "<< res4 <<endl;
//cout<<"reverse to : "<< res5 <<endl;