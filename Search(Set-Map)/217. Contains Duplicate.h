//
// Created by Shinelon on 2017/10/21.
//

#ifndef ALGORITHM_INTERVIEW2_217_CONTAINS_DUPLICATE_H
#define ALGORITHM_INTERVIEW2_217_CONTAINS_DUPLICATE_H

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto ni : nums){
            if(set.find(ni) != set.end()){
                return true;
            }else{
                set.insert(ni);
            }
        }
        return false;
    }
};

class Test{
public:
    void test(){
        vector<int> nums = {1,2,3,4,5,1};
        cout<< Solution().containsDuplicate(nums) <<endl;
    }
};


#endif //ALGORITHM_INTERVIEW2_217_CONTAINS_DUPLICATE_H
