//
// Created by Shinelon on 2017/10/7.
//

#ifndef ALGORITHM_INTERVIEW2_242_VALID_ANAGRAM_H
#define ALGORITHM_INTERVIEW2_242_VALID_ANAGRAM_H

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ag;
        for(auto ch : s){
            ag[ch] = ag[ch] ? ag[ch]+1 : 1;
        }
        int n = s.size();
        for(auto ch : t){
            if(!ag[ch]) {
                return false;
            }else{
                ag[ch]--;
                n--;
            }
        }
        return !n;
    }
};

class Test{
public:
    void test(){
        string s = "ab";
        string t = "ab";
        cout<< Solution().isAnagram(s, t) <<endl;
    }
};

#endif //ALGORITHM_INTERVIEW2_242_VALID_ANAGRAM_H
