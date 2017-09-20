//
// Created by Shinelon on 2017/9/20.
//

#ifndef ALGORITHM_INTERVIEW2_283_H
#define ALGORITHM_INTERVIEW2_283_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    /**
     * 将非零元素与前面的0交换
     * @param nums
     */
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        while(nums[k] != 0){
            k++;
        }
        for(int i=k+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[k++], nums[i]);
            }
        }
    }

    /**
     * 将非零元素移动到前面
     * @param nums
     */
    void moveZeroes2(vector<int>& nums) {
        int k = 0;
        while(nums[k] != 0){
            k++;
        }
        for(int i=k+1; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[k++] = nums[i];
            }
        }
        for(int i=k; i<nums.size(); i++){
            nums[i] = 0;
        }
    }

    // 时间复杂度 O(n)
    // 空间复杂度 O(n)
    void moveZeroes1(vector<int>& nums) {
        vector<int> nonZeroElements;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nonZeroElements.push_back(nums[i]);
            }
        }
        for(int i=0; i<nonZeroElements.size(); i++){
            nums[i] = nonZeroElements[i];
        }
        for(int i=nonZeroElements.size(); i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_283_H
//int arr[] = {0, 1, 0, 3, 12};
//vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
//Solution().moveZeroes(vec);
//
//for(int i=0; i<vec.size(); i++){
//cout<<vec[i]<<" ";
//}