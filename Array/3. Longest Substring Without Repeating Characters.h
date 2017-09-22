//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define ALGORITHM_INTERVIEW2_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] = {0};
        int n = s.size(), sz = 0;
        int l = 0, r = -1;
        while(l < n){
            if(r+1 < n && map[s[r+1]] == 0){
                map[s[++r]] = 1;
            }else{
                map[s[l++]] = 0;
            }
            sz = max(r-l+1, sz);
        }
        return sz;
    }
};

#endif //ALGORITHM_INTERVIEW2_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
//string s1 = "abcabcbb";
//string s2 = "bbbbb";
//string s3 = "pwwkew";
//
//int res1 = Solution().lengthOfLongestSubstring(s1);
//int res2 = Solution().lengthOfLongestSubstring(s2);
//int res3 = Solution().lengthOfLongestSubstring(s3);
//
//cout<<"res:"<<res1<<endl;
//cout<<"res:"<<res2<<endl;
//cout<<"res:"<<res3<<endl;