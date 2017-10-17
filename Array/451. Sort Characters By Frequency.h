//
// Created by Shinelon on 2017/10/17.
//

#ifndef ALGORITHM_INTERVIEW2_451_SORT_CHARACTERS_BY_FREQUENCY_H
#define ALGORITHM_INTERVIEW2_451_SORT_CHARACTERS_BY_FREQUENCY_H

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2){
    return p1.second > p2.second;
}

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> fre(128);
        for(auto si : s){
            fre[si].first = si;
            fre[si].second++;
        }
        sort(fre.begin(), fre.end(), cmp);
        s = "";
        for(auto f : fre){
            for(int i=0; i<f.second; i++){
               s += f.first;
            }
        }
        return s;
    }
};

class Test{
public:
    void test(){
        string s = "Aabb";
        string res = Solution().frequencySort(s);
        char *ch = &res[0];
        printf("%s", ch);
    }
};
#endif //ALGORITHM_INTERVIEW2_451_SORT_CHARACTERS_BY_FREQUENCY_H
