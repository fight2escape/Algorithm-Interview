//
// Created by Shinelon on 2017/10/14.
//

#ifndef ALGORITHM_INTERVIEW2_290_WORD_PATTERN_H
#define ALGORITHM_INTERVIEW2_290_WORD_PATTERN_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> ctos;
        unordered_map<string, char> stoc;

        stringstream ss(str);
        string s;
        int pi = 0;
        while(!ss.eof()){
            ss>>s;

            if(pi == pattern.size()){
                return false;
            }

            if(ctos.find(pattern[pi])!=ctos.end()){
                if(ctos[pattern[pi]] != s){
                    return false;
                }
            }else{
                ctos[pattern[pi]] = s;
            }

            if(stoc.find(s)!=stoc.end()){
                if(stoc[s] != pattern[pi]){
                    return false;
                }
            }else{
                stoc[s] = pattern[pi];
            }

            ++pi;
        }
        return pattern.size()==pi;
    }
};

class Test{
public:
    void test(){
//        string pattern = "jquery";
//        string str = "jquery";

        string pattern = "abaa";
        string str = "dog cat dog dog";
        bool flag = Solution().wordPattern(pattern,str);
        printf("%s", flag ? "true" : "false");
    }
};

#endif //ALGORITHM_INTERVIEW2_290_WORD_PATTERN_H
