//
// Created by Shinelon on 2017/9/22.
//

#ifndef ALGORITHM_INTERVIEW2_350_INTERSECTION_OF_TWO_ARRAYS_II_H
#define ALGORITHM_INTERVIEW2_350_INTERSECTION_OF_TWO_ARRAYS_II_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>  rec;
        for(int i=0; i<nums1.size(); i++){
            rec[nums1[i]]++;
        }
        vector<int> res;
        for(int i=0; i<nums2.size(); i++){
            if(rec[nums2[i]] > 0){
                res.push_back(nums2[i]);
                rec[nums2[i]]--;
            }
        }
        return res;
    }
};

#endif //ALGORITHM_INTERVIEW2_350_INTERSECTION_OF_TWO_ARRAYS_II_H
//vector<int> v1 = {1,2,2,1,};
//vector<int> v2 = {2,2};
//
//vector<int> res = Solution().intersect(v1,v2);
//
//for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++){
//cout<<*iter<<" ";
//}
//cout<<endl;