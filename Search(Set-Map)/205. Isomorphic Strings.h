
//
// Created by Shinelon on 2017/10/15.
//

#ifndef ALGORITHM_INTERVIEW2_205_ISOMORPHIC_STRINGS_H
#define ALGORITHM_INTERVIEW2_205_ISOMORPHIC_STRINGS_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sl = s.size(), tl = t.size();
        if(sl != tl) return false;
        int i = 0;
        unordered_map<char, char> sm, tm;
        while(i < sl){
            if(sm.find(s[i])!=sm.end()){
                if(sm[ s[i] ] != t[i]){
                    return false;
                }
            }else{
                sm[ s[i] ] = t[i];
            }
            if(tm.find(t[i])!=sm.end()){
                if(tm[ t[i] ] != s[i]){
                    return false;
                }
            }else{
                tm[ t[i] ] = s[i];
            }
            ++i;
        }
        return true;
    }
};

class Test{
public:
    void test(){
        string s = "paper";
        string t = "title";
        cout << Solution().isIsomorphic(s, t) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_205_ISOMORPHIC_STRINGS_H
