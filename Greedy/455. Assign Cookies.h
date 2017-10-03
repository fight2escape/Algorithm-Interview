//
// Created by Shinelon on 2017/10/3.
//

#ifndef ALGORITHM_INTERVIEW2_455_ASSIGN_COOKIES_H
#define ALGORITHM_INTERVIEW2_455_ASSIGN_COOKIES_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = g.size()-1, si = s.size()-1, count = 0;
        while(si>=0 && gi>=0){
            if(s[si] >= g[gi]) {
                count++;
                si--;
            }
            gi--;
        }
        return count;
    }
};

#endif //ALGORITHM_INTERVIEW2_455_ASSIGN_COOKIES_H

//    vector<Interval> itv;

//    itv.push_back(Interval(1,2));
//    itv.push_back(Interval(2,3));
//    itv.push_back(Interval(3,4));
//    itv.push_back(Interval(1,3));

//    itv.push_back(Interval(1,2));
//    itv.push_back(Interval(1,2));
//    itv.push_back(Interval(1,2));

//    itv.push_back(Interval(1,2));
//    itv.push_back(Interval(2,3));

//    cout << Solution().eraseOverlapIntervals(itv) << endl;