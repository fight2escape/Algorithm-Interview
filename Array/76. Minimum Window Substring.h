//
// Created by Shinelon on 2017/10/14.
//

#ifndef ALGORITHM_INTERVIEW2_76_MINIMUM_WINDOW_SUBSTRING_H
#define ALGORITHM_INTERVIEW2_76_MINIMUM_WINDOW_SUBSTRING_H

#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        for(auto ti : t) map[ti]++;
        int begin=0, end=0, pos=0, length=INT32_MAX, count=t.size();
        while(end < s.size()){
            if(map[ s[end++] ]-- > 0) count--;
            while(count == 0){
                int size = end - begin;
                if(size < length) {
                    length = size;
                    pos = begin;
                }
                if(map[ s[begin++] ]++ == 0) count++;
            }
        }
        return length==INT32_MAX ? "" : s.substr(pos, length);
    }
};

class Test{
public:
    void test(){
        string s = "ADOBECODEBANC";
        string t = "ABC";
        string res = Solution().minWindow(s, t);
        char *ch = &res[0];
        printf("%s \n", ch);
    }
};
#endif //ALGORITHM_INTERVIEW2_76_MINIMUM_WINDOW_SUBSTRING_H
