//
// Created by Shinelon on 2017/10/3.
//

#ifndef ALGORITHM_INTERVIEW2_392_IS_SUBSEQUENCE_H
#define ALGORITHM_INTERVIEW2_392_IS_SUBSEQUENCE_H

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0, ti=0;
        int sz1 = s.size(), sz2 = t.size();
        if(sz1==0) return true;
        while(si<sz1 && ti<sz2){
            if(s[si] == t[ti]){
                si++;
                if(si == sz1) return true;
            }
            ti++;
        }
        return false;
    }
};

#endif //ALGORITHM_INTERVIEW2_392_IS_SUBSEQUENCE_H
//    string s = "abc";
//    string t = "ahbgdc";
//    cout<< Solution().isSubsequence(s, t) <<endl;