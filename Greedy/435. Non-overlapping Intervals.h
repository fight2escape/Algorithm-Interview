//
// Created by Shinelon on 2017/10/3.
//

#ifndef ALGORITHM_INTERVIEW2_435_NON_OVERLAPPING_INTERVALS_H
#define ALGORITHM_INTERVIEW2_435_NON_OVERLAPPING_INTERVALS_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval a, const Interval b){
    if(a.start != b.start){
        return a.start < b.start;
    }else{
        return a.end < b.end;
    }
}

bool cmp(const Interval a, const Interval b){
    if(a.end != b.end){
        return a.end < b.end;
    }else{
        return a.start < b.start;
    }
}

class Solution {
public:
    /**
     * 贪心算法
     * @param intervals
     * @return
     */
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 0){ return 0;}
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 1;
        int pre = 0;
        for(int i=1; i<n; i++){
            if(intervals[i].start >= intervals[pre].end){
                res++;
                pre = i;
            }
        }
        return n-res;
    }


    /**
     * DP
     * @param intervals
     * @return
     */
    int eraseOverlapIntervals1(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 0){ return 0; }
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> res(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(intervals[i].start >= intervals[j].end){
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        int ret = 0;
        for(int r:res){
            ret = max(ret, r);
        }
        return n-ret;
    }
};

#endif //ALGORITHM_INTERVIEW2_435_NON_OVERLAPPING_INTERVALS_H
