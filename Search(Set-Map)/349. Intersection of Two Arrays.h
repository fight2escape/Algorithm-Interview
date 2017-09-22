//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_349_INTERSECTION_OF_TWO_ARRAYS_H
#define ALGORITHM_INTERVIEW2_349_INTERSECTION_OF_TWO_ARRAYS_H

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> res;
        for(unordered_set<int>::iterator iter = s2.begin(); iter != s2.end(); iter++){
            if(s1.find(*iter) != s1.end()){
                res.push_back(*iter);
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_349_INTERSECTION_OF_TWO_ARRAYS_H
