//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_11_CONTAINER_WITH_MOST_WATER_H
#define ALGORITHM_INTERVIEW2_11_CONTAINER_WITH_MOST_WATER_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size()-1, res = 0;
        while(l <r){
            res = max((r-l)*min(h[l], h[r]), res);
            if(h[l] <= h[r]){
                l++;
            }else{
                r--;
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_11_CONTAINER_WITH_MOST_WATER_H
