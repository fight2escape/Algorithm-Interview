//
// Created by Shinelon on 2017/9/20.
//

#ifndef ALGORITHM_INTERVIEW2_27_REMOVE_ELEMENT_H
#define ALGORITHM_INTERVIEW2_27_REMOVE_ELEMENT_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int i = 0;
        while(i < k){
            if(nums[i] == val){
                swap(nums[i], nums[--k]);
            }else{
                i++;
            }
        }
        return k;
    }
};

#endif //ALGORITHM_INTERVIEW2_27_REMOVE_ELEMENT_H
//int arr[] = {3, 2, 2, 3};
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//int len = Solution().removeElement(vec, 3);
//
//cout<<"len : "<<len<<endl;
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}